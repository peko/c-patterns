#pragma once

#include "Animal.h"

typedef struct Dog Dog;
struct Dog {
    union {
        Animal animal[1];
        struct Animal;
    };
    int teeth_count;
};

struct ADog {            
    Dog* (*Create )();
    void (*Init   )(Dog*);
    void (*DeInit )(Dog*);
    void (*Release)(Dog*);
    
    void (*Introspection)(Dog*);
};                          
extern struct ADog ADog[1];
