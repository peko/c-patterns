#include <stdio.h>

#include "Primitives.h"
#include "Obj.h"
#include "Cat.h"

int main(void) {

    void* o = AObj->create();

    vec2 p;
    vec2 v = {10.0, 15.0};
    AObj->getPos(o, &p);
    printf("xy: %f %f\n", p.x, p.y);
    AObj->translate(o, &v);
    AObj->getPos(o, &p);
    printf("xy: %f %f\n", p.x, p.y);
    AObj->release(o);

	v = (vec2){5.0, -5.0};
    void* c = ACat->create();
    AObj->getPos(c, &p);
    printf("xy: %f %f\n", p.x, p.y);
    AObj->translate(c, &v);
    AObj->getPos(c, &p);
    printf("xy: %f %f\n", p.x, p.y);
    printf("sat: %f\n", ACat->getSatiety(c));
    ACat->feed(c);
    printf("sat: %f\n", ACat->getSatiety(c)); 
    ACat->release(c);
}
