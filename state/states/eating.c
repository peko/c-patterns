
// EATING

#include <stdio.h>

#include "../cat.h"
#include "states.h"

static void update(cat_p cat) {

    printf("EATING       \n");

    cat_attr_p attr = cat_get_attr(cat);

    // голод и силы падают, еда уменьшается
    attr->hunger -= 5;
    attr->food   -= 1;
    attr->energy -= 1;

    // ест пока не кончатся еда, силы или голод
    if(attr->food   <= 0 ||
       attr->energy <= 0 ||
       attr->hunger <= 0) to_sleep(cat);
    
}

void to_eat(cat_p cat) {
    printf("GOING EAT\n");
    cat_set_update(cat, update);
}
