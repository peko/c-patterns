#include <stdio.h>
#include <stdlib.h>


typedef struct Animal Animal;
typedef struct Cat Cat;
typedef struct Dog Dog;

// -------------------------------------------------------

struct Animal {
	int x,y,w;
	int* animals_data;

	void (*voice)(void*);
};

void
Animal_voice(void* animal) {
	printf("...\n");
}

Animal
Animal_new() {
	return (Animal){
		.x = 1,
		.y = 2,
		.w = 5,
		.animals_data = malloc(sizeof(int)*10),
		.voice = Animal_voice,
	};
}

void
Animal_release(Animal* animal) {
	free(animal->animals_data);
};

// ----------------------------------------------------

struct Cat {
	union {
		Animal animal;
		struct Animal;
	};
	int tail_length;
	int* cats_data;
};


void
Cat_voice(void* cat) {
	printf("Meow!\n");
}

Cat
Cat_new() {
	Cat cat = {
		.animal=Animal_new(),
		.tail_length=10,
		.cats_data = malloc(sizeof(int)*20),
		.voice = Cat_voice,
	};
	return cat;
}
void
Cat_release(Cat* cat) {
	Animal_release(&cat->animal);
	free(cat->cats_data);
}

// -------------------------------------------------------

struct Dog {
	union {
		Animal animal;
		struct Animal;
	};
	int teeth_count;
	int* dogs_data;
};

void
Dog_voice(void* dog) {
	printf("Bark!\n");
}

Dog
Dog_new() {
	Dog dog = {
		.animal=Animal_new(),
		.teeth_count=10,
		.dogs_data = malloc(sizeof(int)*20),
		.voice = Dog_voice,
	};
	return dog;
}

void
Dog_release(Dog* dog) {
	Animal_release(&dog->animal);
	free(dog->dogs_data);
}

// -------------------------------------------------------

/*
ERROR / Duplicate Animal members

struct CatDog {
	union {
		Cat cat;
		struct Cat;
	};
	union {
		Dog dog;
		struct Dog;
	};	
};
*/ 	

// -------------------------------------------------------


int
main(void) {
	Cat cat = Cat_new();
	Dog dog = Dog_new();
	printf("%d %d \n", cat.x, cat.y);
	cat.voice(&cat);
	dog.voice(&dog);
	Cat_release(&cat);
	Dog_release(&dog);
}
