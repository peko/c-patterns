#pragma once

#include "Animal.h"

typedef struct Cat Cat;
struct Cat {
    // Inheriting data
	Animal animal[1];
	
	// Additional data
	int tail_length;
	int wiskers_count;
};

struct ACat {
	Cat* (*Create)  ();
	void (*Init)    (Cat* outCat);
	void (*Release) (Animal* animal);
	void (*Print)   (Animal* animal);
};

struct ACat ACat[1];
