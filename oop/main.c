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
	ADog->Release(dog);
	ACat->Release(cat);
	AAnimal->Release(animal);
}
