#include <stdio.h>
#include <unistd.h>

#include "cat.h"

int main() {

    // Анонимный кот
    cat_p cat = cat_new();
    for(int i=0;;i++) {

        printf("\033[2J"); // Clear screen
        printf("[%d]\n",i);

        // Шаг автоматата
        cat_update(cat);
        // Запрос состояния
        // printf("\033[10B"); // Move down
        cat_print(cat);
		
        usleep(1e5);
    }
    cat_del(cat);
}
