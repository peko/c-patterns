#pragma once

#include "Animal.h"

typedef struct Dog Dog;
struct Dog {
    // Inheriting from Animal
    Animal animal[1];
    
    // Additional data
    int tail_length;
    int teeth_count;
};


// Singelton declaration
struct ADog {
    Dog* (*Create)  ();
    void (*Init)    (Dog* outDog);
    void (*Release) (Animal* animal);
    void (*Print)   (Animal* animal);
};

// Singelton pointer declaration
extern struct ADog ADog[1];
