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

void method_voice_cat(animal* a) {
    cat* c = container_of(a, cat, animal);
	printf("%s says: Meow\n", c->name);
}

void method_free_cat(animal* a) {
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

void method_voice_dog(animal* a) {
    dog* c = container_of(a, dog, animal);
	printf("%s says: Bark\n", c->name);
}

void method_free_dog(animal* a) {
    dog* d = container_of(a, dog, animal);
    free(d->name);
	free(d);
}

struct animal_vtable animal_dog_vtable = {
	method_voice_dog, 
	method_free_dog
};

animal* animal_dog_create(const char* name) {
	struct dog* d = malloc(sizeof(*d));
	d->animal.vtable = &animal_dog_vtable;
	d->name = strdup(name);
	return &d->animal;
}

// main

void main(void) {
	animal* c = animal_cat_create("Tom");
	animal_voice(c);
	
	animal* d = animal_dog_create("Butch");
	animal_voice(d);

	animal_free(c);
	animal_free(d);

};


