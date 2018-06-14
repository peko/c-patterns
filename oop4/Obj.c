#include <stdlib.h>

#include "Obj.h"

// forward declarations
static void init (void*);

// definitions 
static void* create(void) {
    void* o = malloc(sizeof(Obj));
    init(o);
    return o;
}

static void init(void* o) {
    Obj* obj = o;
    obj->x = 0.0;
    obj->y = 0.0;
    obj->m = 1.0;
}

static void deinit(void* o) {
    
}

static void release(void* o) {
    deinit(o);
    free(o);
}

// 

static void getPos(void* o, vec2* v) {
    Obj* obj = o;
    v->x = obj->x;
    v->y = obj->y;
}

static void translate(void* o, vec2* v) {
    Obj* obj = o;
    obj->x += v->x;
    obj->y += v->y;
}

// obj definition

struct AObj AObj[1] = {{
    create,
    init,
    deinit,
    release,

    getPos,
    translate,
}};

