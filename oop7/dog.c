#include "struct.h"
#include "dog.h"

static void 
voice(animal* a) {
    dog* c = container_of(a, dog, animal);
    printf("%s the dog says: \"Bark\"\n", c->name);
}

static void 
release(animal* a) {
    dog* d = container_of(a, dog, animal);
    free(d->name);
    free(d);
}

static struct animal_vtable 
vtable = {
    voice, 
    release,
};

static animal* 
create(const char* name) {
    struct dog* d = malloc(sizeof(*d));
    d->animal.vtable = &vtable;
    d->name = strdup(name);
    return &d->animal;
}

struct adog adog[1] = {
    create
};
