#include <stdio.h>
#include <stdlib.h>

#include "Fish.h"
#include "Struct.h"

static void Init(Fish* outFish) {
    Animal* animal = outFish->animal;
    AAnimal->Init(animal);
}

static Fish* Create() {
	Fish* fish = (Fish*) malloc(sizeof(Fish));
	Init(fish);
	return fish;
}

static void Release(Fish* cat) {
	free(cat);
	printf("An Fish released!\n");
}

static void Print(Animal* animal) {
	Fish* fish = AStruct_GetParent2(animal, Fish);
	AAnimal->Print(animal);
    printf("Fish have no specifics\n");
}

struct AFish AFish[1] =  {
	Create,
	Init,
	Release,
	Print
};
