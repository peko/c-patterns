#include <stdlib.h>
#include <stdio.h>

#include "Animal.h"

static void Voice(Animal* animal) {
    printf("...\n");
}

static void Release(Animal* animal){
    free(animal);
    printf("An Animal released!\n");
}

static void Init(Animal* outAnimal) {
    *outAnimal = (struct Animal){
        .Voice   = Voice,
        .Release = Release,
        .age     = random()%10,
        .weight  = random()%20,
        .lng     = 180-random()%360,
        .lat     =  90-random()%180,
    };
}

static Animal* Create() {
    Animal* animal = malloc(sizeof(Animal));
    Init(animal);
    return animal;
}

static void Print(Animal* animal) {
    printf("-------------\n"
           "Animal:\n"
           "\tage:    %d\n"
           "\tweigth: %d\n"
           "\tlng:    %f\n"
           "\tlat:    %f\n",
           animal->age, animal->weight, animal->lng, animal->lat);
}

static void Feed(Animal* animal, int food) {
    animal->weight += food;
    printf("Feeding an animal\n\tnew weight: %d (+%d)\n", animal->weight, food);
}

struct AAnimal AAnimal[1] =  {
    Create,
    Init,
    Release,
    Feed,
    Print
};
