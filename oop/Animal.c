#include <stdlib.h>
#include <stdio.h>

#include "Animal.h"

static void Voice(Animal* animal) {
	printf("...\n");
}

static void Init(Animal* outAnimal) {
    *outAnimal = (struct Animal){
        .Voice  = Voice,
		.age    = random()%100,
		.weight = random()%100,
		.lng    = 180-random()%360,
		.lat    =  90-random()%180,
    };
}

static Animal* Create() {
	Animal* animal = malloc(sizeof(Animal));
	Init(animal);
	return animal;
}

static Animal* Print(Animal* animal) {
    printf("Animal:\n"
           "\tage:    %d\n"
           "\tweigth: %d\n"
           "\tlng:    %f\n"
           "\tlat:    %f\n",
           animal->age, animal->weight, animal->lng, animal->lat);
}

static void Release(Animal* animal){
	free(animal);
	printf("An Animal relesed!\n");
}

struct AAnimal AAnimal[1] =  {
	Create,
	Init,
	Release,
	Print
};
