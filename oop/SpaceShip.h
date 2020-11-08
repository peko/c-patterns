#pragma once

#include "Object.h"

typedef struct SpaceShip SpaceShip;
struct SpaceShip {
    Object object[1];
    float fuel;
};

// Singelton declaration
struct ASpaceShip {
    SpaceShip* (*Create)();
    void    (*Init   )(SpaceShip* outSpaceShip);
    void    (*Release)(SpaceShip* spaceShip);
    void    (*Destroy)(SpaceShip* spaceShip);
};

// Singelton pointer decalration
extern struct ASpaceShip ASpaceShip[1];
