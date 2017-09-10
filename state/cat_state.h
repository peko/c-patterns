
// CAT STATE

#pragma once

#include "cat.h"

typedef struct cat_state* cat_state_p;
typedef struct cat_attr* cat_attr_p;
struct cat_state {
    void (*update)(cat_state_p, cat_attr_p);
};
void cat_state_init(cat_state_p);
