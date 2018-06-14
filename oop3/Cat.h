#pragma once

#include "Animal.h"

typedef struct Cat Cat;
struct Cat {
    union {
        Animal animal[1];
        struct Animal;
    };
    int tail_length;
};

struct ACat {            
    Cat* (*Create )();
    void (*Init   )(Cat*);
    void (*DeInit )(Cat*);
    void (*Release)(Cat*);

    void (*Introspection)(Cat*);
};                          
extern struct ACat ACat[1];
