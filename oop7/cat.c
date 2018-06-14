#include "struct.h"

#include "cat.h"

static void 
voice(animal* a) {
    cat* c = container_of(a, cat, animal);
    printf("%s the cat says: \"Meow\"\n", c->name);
}

static void 
release(animal* a) {
    cat* c = container_of(a, cat, animal);
    free(c->name);
    free(c);
}

static struct animal_vtable 
vtable = {
    voice, 
    release,
};

static animal* 
create(const char* name) {
    struct cat* c = malloc(sizeof(*c));
    c->animal.vtable = &vtable;
    c->name = strdup(name);
    return &c->animal;
}

struct acat acat[1] = {
    create
};
