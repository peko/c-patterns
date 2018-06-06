#include <stdio.h>
#include <stdlib.h>

#include "Cat.h"
#include "Struct.h"

// Polymorphic function
static void Voice(Animal* animal) {
	Cat* cat = AStruct_GetParent2(animal, Cat);
	for (int i=0; i<cat->wiskers_count; i++)
		printf("Meow! ", cat->wiskers_count);
	printf("\n");
}

static void Init(Cat* outCat) {
    Animal* animal = outCat->animal;
    AAnimal->Init(animal);
    animal->Voice = Voice; 

	outCat->wiskers_count = random()%10;
	outCat->tail_length   = random()%20;
}

static Cat* Create() {
	Cat* cat = (Cat*) malloc(sizeof(Cat));
	Init(cat);
	return cat;
}

// Override function
static void Print(Animal* animal) {
	Cat* cat = AStruct_GetParent2(animal, Cat);
	AAnimal->Print(animal);
    printf("Cat specifics:\n"
           "\twiskers: %d\n"
           "\ttail:    %d\n",
           cat->wiskers_count, cat->tail_length);
}

static void Release(Cat* cat) {
	free(cat);
	printf("An Cat released!\n");
}

struct ACat ACat[1] =  {
	Create,
	Init,
	Release,
	Print
};
