#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <fnmatch.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

/* Filter API */

struct filter {
    struct filter_vtable *vtable;
};

struct filter_vtable {
    bool (*match)(struct filter *, const char *);
    void (*free)(struct filter *);
    struct filter *(*clone)(struct filter *);
};

bool filter_match(struct filter *filter, const char *string)
{
    return filter->vtable->match(filter, string);
}

void filter_free(struct filter *filter)
{
    return filter->vtable->free(filter);
}

struct filter *filter_clone(struct filter *filter)
{
    return filter->vtable->clone(filter);
}

/* Regex Filter */

struct filter *filter_regex_create(const char *pattern);

struct filter_regex {
    regex_t regex;
    const char *pattern;
    struct filter filter;
};

static bool
method_match_regex(struct filter *f, const char *string)
{
    struct filter_regex *regex = container_of(f, struct filter_regex, filter);
    return regexec(&regex->regex, string, 0, NULL, 0) == 0;
}

static void
method_free_regex(struct filter *f)
{
    struct filter_regex *regex = container_of(f, struct filter_regex, filter);
    regfree(&regex->regex);
    free(f);
}

static struct filter *
method_clone_regex(struct filter *f)
{
    struct filter_regex *regex = container_of(f, struct filter_regex, filter);
    return filter_regex_create(regex->pattern);
}

struct filter_vtable filter_regex_vtable = {
    method_match_regex, method_free_regex, method_clone_regex
};

struct filter *filter_regex_create(const char *pattern)
{
    struct filter_regex *regex = malloc(sizeof(*regex));
    regex->pattern = pattern;
    regcomp(&regex->regex, pattern, REG_EXTENDED);
    regex->filter.vtable = &filter_regex_vtable;
    return &regex->filter;
}

/* Glob Filter */

struct filter *filter_glob_create(const char *pattern);

struct filter_glob {
    struct filter filter;
    const char *pattern;
};

static bool
method_match_glob(struct filter *f, const char *string)
{
    struct filter_glob *glob = (struct filter_glob *) f;
    return fnmatch(glob->pattern, string, 0) == 0;
}

static void
method_free_glob(struct filter *f)
{
    free(f);
}

static struct filter *
method_clone_glob(struct filter *f)
{
    struct filter_glob *glob = (struct filter_glob *) f;
    return filter_glob_create(glob->pattern);
}

struct filter_vtable filter_glob_vtable = {
    method_match_glob, method_free_glob, method_clone_glob
};

struct filter *filter_glob_create(const char *pattern)
{
    struct filter_glob *glob = malloc(sizeof(*glob));
    glob->pattern = pattern;
    glob->filter.vtable = &filter_glob_vtable;
    return &glob->filter;
}

/* AND Filter */

struct filter *filter_and(struct filter *a, struct filter *b);

struct filter_and {
    struct filter filter;
    struct filter *sub[2];
};

static bool
method_match_and (struct filter *f, const char *s)
{
    struct filter_and *and = (struct filter_and *) f;
    return filter_match(and->sub[0], s) && filter_match(and->sub[1], s);
}

static void
method_free_and(struct filter *f)
{
    struct filter_and *and = (struct filter_and *) f;
    filter_free(and->sub[0]);
    filter_free(and->sub[1]);
    free(f);
}

static struct filter *
method_clone_and(struct filter *f)
{
    struct filter_and *and = (struct filter_and *) f;
    return filter_and(filter_clone(and->sub[0]), filter_clone(and->sub[1]));
}

struct filter_vtable filter_and_vtable = {
    method_match_and, method_free_and, method_clone_and
};

struct filter *filter_and(struct filter *a, struct filter *b)
{
    struct filter_and *and = malloc(sizeof(*and));
    and->sub[0] = a;
    and->sub[1] = b;
    and->filter.vtable = &filter_and_vtable;
    return &and->filter;
}

/* Constant Filters */

static bool
method_match_any(struct filter *f, const char *string)
{
    return true;
}

static bool
method_match_none(struct filter *f, const char *string)
{
    return false;
}

static void
method_free_noop(struct filter *f)
{
}

static struct
filter *method_clone_noop(struct filter *f)
{
    return f;
}

struct filter_vtable filter_any_vtable = {
    method_match_any, method_free_noop, method_clone_noop
};

struct filter_vtable filter_none_vtable = {
    method_match_none, method_free_noop, method_clone_noop
};

struct filter FILTER_ANY  = { &filter_any_vtable };
struct filter FILTER_NONE = { &filter_none_vtable };

/* Test Program */

void pass_match(FILE *input, FILE *output, struct filter *filter)
{
    char line[4096];
    while (fgets(line, sizeof(line), input))
        if (filter_match(filter, line))
            fputs(line, output);
}

int main(int argc, char **argv)
{
    struct filter *filter = &FILTER_ANY;
    for (char **p = argv + 1; *p; p++)
        filter = filter_and(filter, filter_glob_create(*p));
    pass_match(stdin, stdout, filter);
    filter_free(filter);
    return 0;
}
