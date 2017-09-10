#pragma once

#include "cat.h"

typedef struct cat_state* cat_state_p;
typedef struct cat_attr* cat_attr_p;
struct cat_state {
    void (*update)(cat_state_p, cat_attr_p);
	void (*print )(cat_state_p);
};

void to_eat  (cat_state_p);
void to_sleep(cat_state_p);
void to_play (cat_state_p);
void to_hunt (cat_state_p);
void to_death(cat_state_p);
