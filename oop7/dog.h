#pragma once

#include "animal.h"

typedef struct dog {
    char* name;
    animal animal;
} dog;

struct adog {
    animal* (*create)(const char*);
};
extern struct adog adog[1];
