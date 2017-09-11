#pragma once

// анонимный кот
typedef struct cat* cat_p;

// интерфейс кота
cat_p cat_new();
void  cat_del(cat_p);
void  cat_do_things(cat_p);
