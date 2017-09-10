
// SLEEPING

#include <stdio.h>

#include "states.h"

static void update(cat_state_p state, cat_attr_p attr) {

    printf("SLEEPING     \n");

    // пока спит, голод и силы растут
    attr->hunger += 1;
    if (attr->energy <100) {
        attr->energy += 5;
    } else {
        if(attr->hunger < 25) to_play(state);
    }
    
    // если голодно
    if(attr->hunger > 25) { 
        if (attr->food > 0) to_eat(state); // подъедаем ништяки
        else                to_hunt(state);// идем на охоту
    }
}

void to_sleep(cat_state_p state) {
    printf("GOING SLEEP\n");
    state->update = update;
}
