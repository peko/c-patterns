#pragma once

#include "Animal.h"

typedef struct Cat Cat;
struct Cat {
    // Inheriting from Animal
    Animal animal[1];
    
    // Additional data
    int tail_length;
    int wiskers_count;
};

// Singelton declaration
struct ACat {
    Cat* (*Create)  ();
    void (*Init)    (Cat* outCat);
    void (*Release) (Animal* animal);
    void (*Print)   (Animal* animal);
};

// Singelton pointer declaration
extern struct ACat ACat[1];
