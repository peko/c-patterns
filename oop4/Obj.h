#pragma once

#include "Class.h"
#include "Primitives.h"

typedef struct Obj Obj;
struct Obj {
    struct vec2;
    float m;
};

struct AObj {
	struct AClass;
	void (*getPos   )(void*, vec2*);
	void (*translate)(void*, vec2*);
};

extern struct AObj AObj[1];
