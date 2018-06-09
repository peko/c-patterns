#include <stdio.h>
#include <stdlib.h>

typedef struct Object Object;
typedef struct Animal Animal;
typedef struct Cat Cat;
typedef struct Dog Dog;

// -------------------------------------------------------

struct Object {
	int x, y, m;
    void (*introspection)(void*);
};

struct Animal {
    union {
    	Object object;
    	struct Object;
    };
    int age;
    void (*voice)(void*);
};

struct Cat {
    union {
        Animal animal;
        struct Animal;
    };
    int tail_length;
};

struct Dog {
    union {
        Animal animal;
        struct Animal;
    };
    int teeth_count;
};

// -------------------------------------------------------

inline static void 
Object_introspection(void* object) {
    Object* o = object;
	printf("Object: x: %d y: %d m: %d\n", 
		o->x, o->y, o->m);
}

inline static Object 
Object_new() {
	Object object = {
		.x = 0, 
		.y = 0,
		.m = 1,	
		.introspection = Object_introspection  
    };
    return object;
}

static void 
Object_move(Object* object, int x, int y) {
	object->x+=x;
	object->y+=y;
}

// -------------------------------------------------------

static void
Animal_introspection (void* animal) {
    Object_introspection(animal);
    Animal* a = animal;
	printf("Animal: age: %d\n", a->age);
}

static void
Animal_voice(void* animal) {
    printf("...\n");
}

inline static Animal
Animal_new() {
    Animal animal;
    animal.object = Object_new();
    animal.age = 5;
    animal.voice = Animal_voice;
    animal.introspection = Animal_introspection;
    return animal;
}

// ----------------------------------------------------

static void
Cat_introspection (void* cat) {
    Animal_introspection(cat);
    Cat* c = cat;
	printf("Cat: tail: %d\n", c->tail_length);
}

static void
Cat_voice(void* cat) {
    printf("Meow!\n");
}

static Cat
Cat_new() {
    Cat cat;
    cat.animal = Animal_new();
    cat.introspection = Cat_introspection;
    cat.voice = Cat_voice;
    cat.tail_length = 10;
    return cat;
}

// -------------------------------------------------------

static void
Dog_voice(void* dog) {
    printf("Bark!\n");
}

static Dog
Dog_new() {
    Dog dog;
    dog.animal = Animal_new();
    dog.teeth_count = 10;
    dog.voice = Dog_voice;
    return dog;
}

// -------------------------------------------------------

/*
ERROR / Duplicate Animal members

struct CatDog {
    union {
        Cat cat;
        struct Cat;
    };
    union {
        Dog dog;
        struct Dog;
    };  
};
*/  

// -------------------------------------------------------


int
main(void) {
    Cat cat = Cat_new();
    Dog dog = Dog_new();
    cat.introspection(&cat);
    Object_move(&cat.object, 10, -10);
    cat.introspection(&cat);
    dog.introspection(&dog);
    cat.voice(&cat);
    dog.voice(&dog);
}
