#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define container_of(ptr, type, member) \
	((type *)((char *)(ptr) - offsetof(type, member)))
	

typedef struct animal {
    struct animal_vtable* vtable;
} animal;

typedef struct animal_vtable {
    void (*voice)(animal*);
    void (*free )(animal*);
} animal_vtable;


void animal_voice(animal* a) {
	a->vtable->voice(a);
}

void animal_free(animal* a) {
	a->vtable->free(a);
}

// cat 

typedef struct cat {
    char* name;
	animal animal;
} cat;

static void 
method_voice_cat(animal* a) {
    cat* c = container_of(a, cat, animal);
	printf("%s the cat says: \"Meow\"\n", c->name);
}

static void 
method_free_cat(animal* a) {
    cat* c = container_of(a, cat, animal);
    free(c->name);
	free(c);
}

struct animal_vtable animal_cat_vtable = {
	method_voice_cat, 
	method_free_cat,
};

animal* animal_cat_create(const char* name) {
	struct cat* c = malloc(sizeof(*c));
	c->animal.vtable = &animal_cat_vtable;
	c->name = strdup(name);
	return &c->animal;
}

// Dog 

typedef struct dog {
    char* name;
	animal animal;
} dog;

static void 
method_voice_dog(animal* a) {
    dog* c = container_of(a, dog, animal);
	printf("%s the dog says: \"Bark\"\n", c->name);
}

static void 
method_free_dog(animal* a) {
    dog* d = container_of(a, dog, animal);
    free(d->name);
	free(d);
}

struct 
animal_vtable animal_dog_vtable = {
	method_voice_dog, 
	method_free_dog
};

animal* 
animal_dog_create(const char* name) {
	struct dog* d = malloc(sizeof(*d));
	d->animal.vtable = &animal_dog_vtable;
	d->name = strdup(name);
	return &d->animal;
}

// catdog composition

typedef struct catdog {
	animal animal;
	animal* cat;
	animal* dog;
	char* name;
} catdog;

static void
method_catdog_voice(animal* a) {
    catdog* cd = container_of(a, catdog, animal);
    printf("The catdog says:\n");
    animal_voice(cd->cat);
    animal_voice(cd->dog);
}

static void
method_catdog_free(animal* a) {
    catdog* cd = container_of(a, catdog, animal);
    free(cd->name);
    animal_free(cd->dog);
    animal_free(cd->cat);
    free(cd);
}

animal_vtable animal_catdog_vtable = {
	method_catdog_voice,
	method_catdog_free,
};

animal* 
animal_catdog_create(const char* name) {
	catdog* cd = malloc(sizeof(*cd));
	cd->animal.vtable = &animal_catdog_vtable;
	cd->name = strdup(name);
	cd->cat = animal_cat_create(name);
	cd->dog = animal_dog_create(name);
	return &cd->animal;
}


// main

void main(void) {
	animal* c = animal_cat_create("Tom");
	animal_voice(c);
	
	animal* d = animal_dog_create("Butch");
	animal_voice(d);

	animal_free(c);
	animal_free(d);

	animal* cd = animal_catdog_create("CatDog");
	animal_voice(cd);
	animal_free(cd);

};


