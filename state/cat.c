#include <stdlib.h>
#include <stdio.h>

#include "cat.h"
#include "states/states.h"

// Завершение структуры кота
struct cat {
    struct cat_attr attr;
    void (*update)(cat_p);
};

cat_p cat_new() {
    cat_p cat = malloc(sizeof(struct cat));
    cat->attr = (struct cat_attr){
        .hunger=   0,
        .food  =   0,
        .energy= 100,
        .luck  =   5,};
    to_sleep(cat);
    return cat;
}

void cat_del(cat_p cat) {
    free(cat);
}

void cat_print(cat_p cat){
    printf("Energy: %d   \nHunger: %d   \nFood  : %d   \n", cat->attr.energy, cat->attr.hunger, cat->attr.food);
}

void cat_update(cat_p cat) {
    cat->update(cat);
}

void cat_set_update(cat_p cat, void (*update)(cat_p)) {
	cat->update = update;
}

cat_attr_p cat_get_attr(cat_p cat) {
    return &cat->attr;
}

