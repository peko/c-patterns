#pragma once

#include "Animal.h"

typedef struct Fish Fish;
struct Fish {
    // Inheritance from Animal
    Animal animal[1];
};

// Singelton declaration
struct AFish {
    Fish* (*Create)  ();
    void (*Init)    (Fish* outFish);
    void (*Release) (Fish* cat);
    void (*Print)   (Animal* animal);
};

// Singelton pointer declaration
extern struct AFish AFish[1];
