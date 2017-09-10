
// PLAYING

#include <stdio.h>

#include "../cat_state.h"

static void update(cat_state_p state, cat_attr_p attr) {

	printf("PLAYING       \n");

	// играем, устаем
	attr->hunger +=1;
    attr->energy -=1;

	// если голододно
    if(attr->hunger >= 25) {
        if(attr->food>0) to_eat(state);  // подъедаем ништяки
        else             to_hunt(state); // отправляемся на охоту
    }

	// устали, нужно подремать
    if(attr->energy<80) to_sleep(state);
}

static void print() {
}

void to_play(cat_state_p state) {
    printf("LETS PLAY\n");
	state->update = update;
	state->print  = print;
}
