#pragma once

typedef struct Object Object;
struct Object {
    // data
    float m,vx,vy,px,py,s;

    // Полиморфизм
    void (*Describe)(Object* object);
    void (*Update  )(Object* object);
    
};

// Singelton declaration
struct AObject {
    Object* (*Create )();
    void    (*Init   )(Object* outObject);
    void    (*Release)(Object* object);
    void    (*Destroy)(Object* object);

    // Mетоды для доступа из дочерних классов
    void    (*Describe)(Object* object);
    void    (*Update  )(Object* object);
};

// Singelton pointer decalration
extern struct AObject AObject[1];
