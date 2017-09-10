
// HUNTING

#include <stdlib.h>
#include <stdio.h>

#include "../cat.h"
#include "states.h"

static const char* prey[] = {"MOUSY", "BIRDY", "FROGGY"}; 

static void update(cat_p cat) {

    printf("HUNTING, ");

    cat_attr_p attr = cat_get_attr(cat);

    // Голод растет, силы падают
    attr->hunger += 1;
    attr->energy -= 1;

    if(attr->hunger >= 100) to_death(cat);
    if(attr->energy <=   0) to_sleep(cat);

    // Удачаной охоты 
    if(rand()%100 > (100 - attr->luck)) {
        printf("GOT A %s\n", prey[rand()%3]);
        attr->food += rand()%10+1;
        to_eat(cat);
    } else {
        printf("GOT NOTHING\n");
    }
}

void to_hunt(cat_p cat) {
    printf("GOING HUNT\n");
    cat_set_update(cat, update);
}

//      _._     _,-'""`-._
//     (,-.`._,'(       |\`-/|
//         `-.-' \ )-`( , o o)
//               `-    \`_`"'-
