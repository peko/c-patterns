#include "Cat.h"

// Class
static void  init   (void*);

// 
static void* create (void){
	void* c = malloc(sizeof(Cat));
	init(c);
	return(c);
}

static void init(void* o) {
    Cat* c = o;
	c->satiety = 100.0;
}

static void deinit (void* o) {
	
}

static void  release(void* o) {
	free(o);
}

// 
static void feed(void* o) {
	Cat* c = o;
	c->satiety += 1.0;
}

float getSatiety(void* o) {
	Cat* c = o;
	return c->satiety;
}

struct ACat ACat[1] = {{
    create,
    init,
    deinit,
    release,

	feed,
	getSatiety,
}};
