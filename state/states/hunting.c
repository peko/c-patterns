
// HUNTING

#include <stdlib.h>
#include <stdio.h>

#include "states.h"

static const char* prey[] = {"MOUSY", "BIRDY", "FROGGY"}; 

static void update(cat_state_p state, cat_attr_p attr) {

    printf("HUNTING, ");

    // Голод растет, силы падают
    attr->hunger += 1;
    attr->energy -= 1;

    if(attr->hunger >= 100) to_death(state);
    if(attr->energy <=   0) to_sleep(state);

    // Удачаной охоты 
    if(rand()%100 > (100 - attr->luck)) {
        printf("GOT A %s\n", prey[rand()%3]);
        attr->food += rand()%10+1;
        to_eat(state);
    } else {
        printf("GOT NOTHING\n");
    }
}

void to_hunt(cat_state_p state) {
    printf("GOING HUNT\n");
    state->update = update;
}

//      _._     _,-'""`-._
//     (,-.`._,'(       |\`-/|
//         `-.-' \ )-`( , o o)
//               `-    \`_`"'-
