#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Object Object;
struct Object {
    int x, y, m;
};

struct AObject {            
    Object* (*Create )();
    void    (*Init   )(Object*);
    void    (*DeInit )(Object*);
    void    (*Release)(Object*);

    void (*Introspection)(Object*);
};                          
extern struct AObject AObject[1];
