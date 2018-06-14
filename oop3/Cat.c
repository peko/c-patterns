#include "Cat.h"

inline static void
Introspection(Cat* cat) {
    AAnimal->Introspection(cat->animal);
    Cat* c = cat;
    printf("Cat: tail: %d\n", c->tail_length);
}

inline static void
Voice(void* cat) {
    printf("Meow!\n");
}

inline static void
Init(Cat* cat) {
    AAnimal->Init(cat->animal);
    cat->voice = Voice;
    cat->tail_length = 10;
}

inline static void
DeInit(Cat* cat) {
    AAnimal->DeInit(cat->animal);
}

inline static Cat*
Create() {
    Cat* cat = malloc(sizeof(Cat));
    Init(cat);
    return cat;
}

inline static void
Release(Cat* cat) {
    DeInit(cat);
	free(cat);
}

struct ACat ACat[1] = {{
    .Create  = Create,
    .Init    = Init,
    .DeInit  = DeInit,
    .Release = Release,

    .Introspection = Introspection,
}};

