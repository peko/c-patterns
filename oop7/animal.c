#include "animal.h"

static void 
voice(animal* a) {
	a->vtable->voice(a);
}

static void 
release(animal* a) {
	a->vtable->free(a);
}

struct aanimal aanimal[1] = {
    voice, 
    release
};
