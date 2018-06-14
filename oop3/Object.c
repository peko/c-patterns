#include "Object.h"

inline static void 
Introspection(Object* object) {
    printf("Object: x: %d y: %d m: %d\n", object->x, object->y, object->m);
}

inline static void 
Init(Object* object) {
    *object = (Object) {
        .x = 0, 
        .y = 0,
        .m = 1, 
    };
}

inline static void 
DeInit(Object* object) {
	// ..
}

inline static Object* 
Create() {
    Object* object = malloc(sizeof(Object));
    Init(object);
    return object;
}

inline static void
Release(Object* object) {
	free(object);
}

inline static void 
Move(Object* object, int x, int y) {
    object->x+=x;
    object->y+=y;
}

struct AObject AObject[1] = {{
    .Create  = Create,
    .Init    = Init,
    .DeInit  = DeInit,
    .Release = Release,

    .Introspection = Introspection,
}};

