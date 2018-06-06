#include <stdio.h>
#include <stdlib.h>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"

int main(void) {
	Animal* animal = AAnimal->Create();
	AAnimal->Print(animal);
	
	Cat* cat = ACat->Create();
	ACat->Print((Animal*)cat);
	
	Dog* dog = ADog->Create();
	ADog->Print((Animal*)dog);

	Fish* fish = AFish->Create();
	AFish->Print((Animal*)fish);

    printf("\n");

	Animal* animals[] = {
		animal,
		cat->animal,
		dog->animal,
		fish->animal
    };

    for(int i=0;i<4; i++) {
		Animal* animal = animals[i];
		AAnimal->Feed(animal, random()%10);
		printf("Some animal says: ");
		animal->Voice(animal);
		
    }

    printf("\n");
    
    AFish->Release(fish); 
	ADog->Release(dog->animal);
	ACat->Release(cat->animal);
	AAnimal->Release(animal);

	Animal* zoo[20];
	for(int i=0;i<20;i++){
		switch(random()%3) {
			case 0: zoo[i] = ACat->Create()->animal;break;
			case 1: zoo[i] = ADog->Create()->animal;break;
			case 2: zoo[i] = AFish->Create()->animal;break;
    	}
   	}
   	
	for(int i=0;i<20;i++){
		zoo[i]->Voice(zoo[i]);
   	}


	for(int i=0;i<20;i++){
		zoo[i]->Release(zoo[i]);
   	}
}
