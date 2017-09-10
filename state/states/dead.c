
// DEAD

#include <stdio.h>

#include "../cat.h"
#include "states.h"

static void update(cat_p cat) {

    printf("DEAD         \n");

    cat_attr_p attr = cat_get_attr(cat);

    // Котик помер, из стейта выхода нет
    attr->hunger = 0;
    attr->food   = 0;
    attr->energy = 0;
    
}

void to_death(cat_p cat) {
    printf("DEAD =x.x=\n");
    cat_set_update(cat, update);
}
