#include "struct.h"

#include "cat.h"
#include "dog.h"
#include "catdog.h"

static void
voice(animal* a) {
    catdog* cd = container_of(a, catdog, animal);
    printf("The catdog says:\n");
    aanimal->voice(cd->cat);
    aanimal->voice(cd->dog);
}

static void
release(animal* a) {
    catdog* cd = container_of(a, catdog, animal);
    free(cd->name);
    aanimal->release(cd->dog);
    aanimal->release(cd->cat);
    free(cd);
}

static animal_vtable 
vtable = {
	voice,
	release,
};

static animal* 
create(const char* name) {
	catdog* cd = malloc(sizeof(*cd));
	cd->animal.vtable = &vtable;
	cd->name = strdup(name);
	cd->cat = acat->create(name);
	cd->dog = adog->create(name);
	return &cd->animal;
}

struct acatdog acatdog[1] = {
	create
};


