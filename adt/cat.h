#pragma once

// указатель на незавершенную структуру, 
// которая будет завершена в cat.c
typedef struct cat* cat_p;

// интерфейс кота
cat_p cat_new();
void  cat_del(cat_p cat);
void  cat_mew(cat_p cat);

