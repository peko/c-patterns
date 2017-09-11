
// CAT

#pragma once

typedef struct cat* cat_p;                //           /\___/\   // 
typedef struct cat_attr* cat_attr_p;      //           )     (   // 
struct cat_attr {                         //          =\     /=  // 
    int energy; // Силы          0-100%   //            )   (    // 
    int hunger; // Голод         0-100%   //           /     \   // 
    int food  ; // Запасы еды    1-inf    //           )     (   // 
    int luck  ; // Удача в охоте 0-100%   //          /       \  // 
};                                        //          \       /  // 
                                          //   <3@--   \__ __/   // 
cat_p cat_new();                          //              ))     // 
void  cat_del(cat_p);                     //             //      // 
void  cat_print(cat_p);                   //            ((       // 
void  cat_update(cat_p);                  //             \)      // 

void cat_set_update(cat_p, void (*update)(cat_p));
cat_attr_p cat_get_attr(cat_p cat);

