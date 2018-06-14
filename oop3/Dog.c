#include "Dog.h"

inline static void
Voice(void* dog) {
    printf("Bark!\n");
}

inline static void
Init(Dog* dog) {
    AAnimal->Init(dog->animal);
    dog->teeth_count = 10;
    dog->voice = Voice;
}

inline static void
DeInit(Dog* dog) {
    AAnimal->DeInit(dog->animal);
}

inline static Dog*
Create() {
    Dog* dog = malloc(sizeof(Dog));
    Init(dog);
    return dog;
}

inline static void
Release(Dog* dog) {
    DeInit(dog);
    free(dog);
}

struct ADog ADog[1] = {{
    .Create  = Create,
    .Init    = Init,
    .DeInit  = DeInit,
    .Release = Release,
}};
