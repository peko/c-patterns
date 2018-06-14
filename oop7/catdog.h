#pragma once

#include "animal.h"

typedef struct catdog {
	animal animal;
	animal* cat;
	animal* dog;
	char* name;
} catdog;

struct acatdog {
    animal* (*create)(const char*);
};
extern struct acatdog acatdog[1];
