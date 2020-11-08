
#include <stdlib.h>
#include <stdio.h>

struct Class {
	size_t size;
	void (*ctor)(void*);
	void (*dtor)(void*);
};

struct Obj {
	const struct Class* type;
};

struct Cat {
	const struct Class* type;
	int wiskers;
	float* toys;
};

void cat_ctor(void* self){
	printf("Cat ctor\n");
	struct Cat* cat = self;
	cat->wiskers = 32;
	cat->toys = malloc(100);
}

void cat_dtor(void* self) {
	printf("Cat dtor\n");
	struct Cat* cat = self;
	free(cat->toys);
}

static const struct Class _Cat = {
	sizeof(struct Cat), cat_ctor, cat_dtor
};
static const struct Class* Cat = &_Cat;

void* new(const struct Class* type) {
	struct Obj* obj = calloc(1, type->size);
	obj->type = type;
	type->ctor(obj);
	return obj;
}

void delete(struct Obj* obj) {
	obj->type->dtor(obj);
	free(obj);
}

void main(void) {
	struct Cat* cat = new(Cat);
	printf("The cat have %d wiskers\n", cat->wiskers);
	printf("The cat have [%x] toys\n", cat->toys);
	delete((struct Obj*)cat);
}
