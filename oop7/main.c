#include "animal.h"
#include "cat.h"
#include "dog.h"
#include "catdog.h"

void main(void) {
	animal* c = acat->create("Tom");
	aanimal->voice(c);
	
	animal* d = adog->create("Butch");
	aanimal->voice(d);

	aanimal->release(c);
	aanimal->release(d);

	animal* cd = acatdog->create("CatDog");
	aanimal->voice(cd);
	aanimal->release(cd);
};


