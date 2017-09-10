#include <stdlib.h>
#include <stdio.h>

#include "cat.h"

// Завершение структуры
// данные будут доступны только здесь
struct cat {
	int isolated;
	int cat;
	int secrets;
};

// конструктор
cat_p cat_new() {
	cat_p cat =  malloc(sizeof(struct cat));
	cat->secrets = 42;
}

// деструктор
void cat_del(cat_p cat) {
	free(cat);
}

// метод
void cat_mew(cat_p cat) {
	printf("mew %d\n", cat->secrets);
}
