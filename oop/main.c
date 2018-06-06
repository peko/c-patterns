#include <stdio.h>
#include <stdlib.h>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main(void) {
	Animal* animal = AAnimal->Create();
	AAnimal->Print(animal);
	
	Cat* cat = ACat->Create();
	ACat->Print((Animal*)cat);
	
	Dog* dog = ADog->Create();
	ADog->Print((Animal*)dog);

	Animal* animals[] = {
		animal,
		cat->animal,
		dog->animal
    };
    
    for(int i=0;i<3; i++) {
		Animal* animal = animals[i];
		printf("Some animal says: ");
		animal->Voice(animal);
    }
    
	ADog->Release(dog);
	ACat->Release(cat);
	AAnimal->Release(animal);
}
