#include "Animal.h"

inline static void
Introspection (Animal* animal) {
    AObject->Introspection(animal->object);
    Animal* a = animal;
    printf("Animal: age: %d\n", a->age);
}

static void
Voice(void* animal) {
    printf("...\n");
}

inline static void 
Init(Animal* animal) {
	AObject->Init(animal->object);
    animal->age   = 5;
    animal->voice = Voice;
}

inline static void 
DeInit(Animal* animal) {
	AObject->DeInit(animal->object);
}

inline static Animal*
Create() {
    Animal* animal = malloc(sizeof(Animal));
    Init(animal);
    return animal;
}

inline static void
Release(Animal* animal) {
    DeInit(animal);
    free(animal); 
}

struct AAnimal AAnimal[1] = {{
    .Create  = Create,
    .Init    = Init,
    .DeInit  = DeInit,
    .Release = Release,

    .Introspection = Introspection,
}};
