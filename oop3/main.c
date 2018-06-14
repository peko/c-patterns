#include <stdio.h>
#include <stdlib.h>

#include "Cat.h"
#include "Dog.h"

int
main(void) {
    Cat* cat = ACat->Create();
    Dog* dog = ADog->Create();
    
    ACat->Introspection(cat);
    // Object_move(cat->object, 10, -10);
    // cat->introspection(cat);

    // dog->introspection(dog);
    // cat->voice(cat);
    // dog->voice(dog);

    ADog->Release(dog);
    ACat->Release(cat);
}
