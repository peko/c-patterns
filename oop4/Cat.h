#pragma once

#include "Obj.h"

typedef struct Cat Cat;
struct Cat { 
	struct Obj;
	float satiety;
};

struct ACat {
    struct AClass;
	void (*feed)(void*);
	float(*getSatiety)(void*);
};
extern struct ACat ACat[1];
