#pragma once

typedef struct animal {
    struct animal_vtable* vtable;
} animal;

typedef struct animal_vtable {
    void (*voice)(animal*);
    void (*free )(animal*);
} animal_vtable;

struct aanimal {
    void (*voice  )(animal*);
    void (*release)(animal*);
};
extern struct aanimal aanimal[1];
