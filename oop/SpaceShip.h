#pragma once

#include "Object.h"

// Наследуем Spaceship от Object
typedef struct SpaceShip SpaceShip;
struct SpaceShip {
    // Анонимный union позволяет реализовать несколько способов обращения к одним и тем же данным
    union {
      // Анонимная структура Object
      // Позволяют получать доступ к свойствам родителя на прямую
      // spaceship->mass как альтернатива spaceship->object->mass
      Object;
      // Объявление родительской структуры массивом позволяет работать с ней как с указателем
      // spaceship->object->mass
      Object object[1];
    };
    int id;
    float fuel;
};

// Singelton declaration
struct ASpaceShip {
    SpaceShip* (*Create)();
    void (*Init   )(SpaceShip* outSpaceShip);
    void (*Release)(SpaceShip* spaceShip);
    void (*Destroy)(SpaceShip* spaceShip);

    void (*Update  )(SpaceShip* spaceShip);
    void (*Describe)(SpaceShip* spaceShip);
    
};

// Singelton pointer decalration
extern struct ASpaceShip ASpaceShip[1];
