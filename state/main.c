#include <stdio.h>
#include <unistd.h>

#include "cat.h"

int main() {
    // Анонимный кот
    cat_p cat = cat_new();
    for(int i=0;;i++) {
        printf("[%d]          \n",i);

        // Шаг автоматата
        cat_update(cat);
        // Запрос состояния
        cat_print(cat);

        printf("\033[5A"); // Move up
        usleep(1e5);
    }
    cat_del(cat);
}
