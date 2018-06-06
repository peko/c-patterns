#include <stdio.h>
#include <stdlib.h>

#include "Dog.h"
#include "Struct.h"

// Polymorphic function
static void Voice(Animal* animal) {
	printf("Bark Bark!\n");
}

static void Init(Dog* outDog) {
    Animal* animal = outDog->animal;
    AAnimal->Init(animal);
    animal->Voice = Voice; 

	outDog->teeth_count = random()%10;
	outDog->tail_length = random()%20;
}

static Dog* Create() {
	Dog* dog = (Dog*) malloc(sizeof(Dog));
	Init(dog);
	return dog;
}

// Override function
static void Print(Animal* animal) {
	Dog* cat = AStruct_GetParent2(animal, Dog);
	AAnimal->Print(animal);
    printf("Dog specifics:\n"
           "\ttееth: %d\n"
           "\ttail:  %d\n",
           cat->teeth_count, cat->tail_length);
}

static void Release(Dog* cat) {
	free(cat);
	printf("An Dog released!\n");
}

struct ADog ADog[1] =  {
	Create,
	Init,
	Release,
	Print
};
