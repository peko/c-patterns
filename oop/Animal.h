#pragma once

typedef struct Animal Animal;
struct Animal {

    // data
    int age;
    int weight;
    float lat;
    float lng;

    // Polymorphic function
    void (*Voice  )(Animal* animal);
    void (*Release)(Animal* animal);
};

struct AAnimal {
    Animal* (*Create )();
    void    (*Init   )(Animal* outAnimal);
    void    (*Release)(Animal* animal);
    void    (*Feed   )(Animal* animal, int food);
    void    (*Print  )(Animal* animal);
};

struct AAnimal AAnimal[1];
