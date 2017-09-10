
// DEAD

#include <stdio.h>

#include "../cat_state.h"

static void update(cat_state_p state, cat_attr_p attr) {

	printf("DEAD         \n");

	// Котик помер, из стейта выхода нет
	attr->hunger = 0;
	attr->food   = 0;
    attr->energy = 0;
	
}

static void print() {
}

void to_death(cat_state_p state) {
    printf("DEAD =x.x=\n");
	state->update = update;
	state->print  = print;
}
