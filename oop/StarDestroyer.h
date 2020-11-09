#pragma once

#include "SpaceShip.h"

// Наследуем StarDestroyer от SpaceShip
typedef struct StarDestroyer StarDestroyer;
struct StarDestroyer {
    // Анонимный union позволяет реализовать несколько способов обращения к одним и тем же данным
    union {
      // Анонимная структура SpaceShip
      // Позволяют получать доступ к свойствам родителя на прямую
      // spaceship->mass как альтернатива spaceship->object->mass
      SpaceShip;
      // Объявление родительской структуры массивом позволяет работать с ней как с указателем
      // spaceship->object->mass
      SpaceShip spaceShip[1];
    };

    float beamEnergy;
    // Истребители на борту
    int tieFightersCount;
    SpaceShip** tieFighters; 
};

// Singelton declaration
struct AStarDestroyer {
    StarDestroyer* (*Create)();
    void (*Init   )(StarDestroyer* outStarDestroyer);
    void (*Release)(StarDestroyer* starDestroyer);
    void (*Destroy)(StarDestroyer* starDestroyer);
};

// Singelton pointer decalration
extern struct AStarDestroyer AStarDestroyer[1];
