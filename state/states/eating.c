
// EATING

#include <stdio.h>

#include "../cat_state.h"

static void update(cat_state_p state, cat_attr_p attr) {

	printf("EATING       \n");

	// голод и силы падают, еда уменьшается
	attr->hunger -= 5;
	attr->food   -= 1;
    attr->energy -= 1;

    // ест пока не кончатся еда, силы или голод
    if(attr->food   <= 0 ||
	   attr->energy <= 0 ||
	   attr->hunger <= 0) to_sleep(state);
	
}

static void print() {
}

void to_eat(cat_state_p state) {
    printf("GOING EAT\n");
	state->update = update;
	state->print  = print;
}
