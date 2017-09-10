
// SLEEPING

#include <stdio.h>

#include "../cat.h"
#include "states.h"

static void update(cat_p cat) {

    printf("SLEEPING     \n");

    cat_attr_p attr = cat_get_attr(cat);

    // пока спит, голод и силы растут
    attr->hunger += 1;
    if (attr->energy <100) {
        attr->energy += 5;
    } else {
        if(attr->hunger < 25) to_play(cat);
    }
    
    // если голодно
    if(attr->hunger > 25) { 
        if (attr->food > 0) to_eat(cat); // подъедаем ништяки
        else                to_hunt(cat);// идем на охоту
    }
}

void to_sleep(cat_p cat) {
    printf("GOING SLEEP\n");
    cat_set_update(cat, update);
}
