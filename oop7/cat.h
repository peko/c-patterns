#include "animal.h"

typedef struct cat {
    char* name;
    animal animal;
} cat;

struct acat {
    animal* (*create)(const char*);
};
extern struct acat acat[1];
