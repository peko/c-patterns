#pragma once

#include "Animal.h"

typedef struct Fish Fish;
struct Fish {
    // Inheriting data
	Animal animal[1];
};

struct AFish {
	Fish* (*Create)  ();
	void (*Init)    (Fish* outFish);
	void (*Release) (Fish* cat);
	void (*Print)   (Animal* animal);
};

struct AFish AFish[1];
