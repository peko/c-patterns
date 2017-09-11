#include <stdlib.h>
#include <stdio.h>

#include "cat.h"

// Завершаем структуру кота
struct cat {
    int id;
	void (*strategy)();
};

// кошачие стратегии
static void sleeping() {printf("snooor snooor\n"        );}
static void eating  () {printf("chrunch crunch\n"       );}
static void playing () {printf("hur hur hur jump jump\n");}
static void noisy   () {printf("MEOW MEOW MEEEOOOW\n"   );}
static void stary   () {printf("=O.O=\n"                );}
static void (*strategies[])() = { &sleeping, &eating, &playing, &noisy, &stary};

////////////////////////////////////////////////////////

// Реализация интерфейса

// создаем анонимного кота, выбираем случайную стратегию
cat_p cat_new() {
    static int id = 0;
	cat_p cat = malloc(sizeof(struct cat));
	cat->id = id++;
	cat->strategy = strategies[rand()%5];
	return cat;
}

// очистка кота
void cat_del(cat_p cat ) { free(cat);       }

// проверка стратегии кота
void cat_do_things(cat_p cat) { 
	printf("cat #%d\n", cat->id);
    cat->strategy(); 
}

