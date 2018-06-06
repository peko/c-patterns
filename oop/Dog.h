#pragma once

#include "Animal.h"

typedef struct Dog Dog;
struct Dog {
    // Inheriting data
	Animal animal[1];
	
	// Additional data
	int tail_length;
	int teeth_count;
};

struct ADog {
	Dog* (*Create)  ();
	void (*Init)    (Dog* outDog);
	void (*Release) (Dog* cat);
	void (*Print)   (Animal* animal);
};

extern struct ADog ADog[1];
