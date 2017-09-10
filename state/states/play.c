
// PLAYING

#include <stdio.h>

#include "../cat.h"
#include "states.h"

static void update(cat_p cat) {

    printf("PLAYING       \n");

    cat_attr_p attr = cat_get_attr(cat);

    // играем, устаем
    attr->hunger +=1;
    attr->energy -=1;

    // если голододно
    if(attr->hunger >= 25) {
        if(attr->food>0) to_eat(cat);  // подъедаем ништяки
        else             to_hunt(cat); // отправляемся на охоту
    }

    // устали, нужно подремать
    if(attr->energy<80) to_sleep(cat);
}

void to_play(cat_p cat) {
    printf("LETS PLAY\n");
    cat_set_update(cat, update);
}
