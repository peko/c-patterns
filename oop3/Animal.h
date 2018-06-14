#pragma once

#include "Object.h"

typedef struct Animal Animal;
struct Animal {
    union {
        Object object[1];
        struct Object;
    };
    int age;
    void (*voice)(void*);
};

struct AAnimal {            
    Animal* (*Create )();
    void    (*Init   )(Animal*);
    void    (*DeInit )(Animal*);
    void    (*Release)(Animal*);

    void (*Introspection)(Animal*);
};                          
extern struct AAnimal AAnimal[1];
