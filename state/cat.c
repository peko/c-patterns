
#include <stdlib.h>
#include <stdio.h>

#include "cat.h"
#include "cat_state.h"

// Завершение структуры кота
struct cat {
	struct cat_attr attr;
	struct cat_state state;
};

cat_p cat_new() {
    cat_p cat = malloc(sizeof(struct cat));
	cat->attr = (struct cat_attr){
    	.hunger=   0,
    	.food  =   0,
    	.energy= 100,
    	.luck  =   5,};
    to_sleep(&cat->state);
    return cat;
}

void cat_del(cat_p cat) {
    free(cat);
}

void cat_print(cat_p cat){
    printf("Energy: %d   \nHunger: %d   \nFood  : %d   \n", cat->attr.energy, cat->attr.hunger, cat->attr.food);
	cat->state.print(&cat->state);
}

void cat_update(cat_p cat) {
	cat->state.update(&cat->state, &cat->attr);
}

