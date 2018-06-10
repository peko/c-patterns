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
        Object object[1];
        struct Object;
    };
    int age;
    void (*voice)(void*);
};

struct Cat {
    union {
        Animal animal[1];
        struct Animal;
    };
    int tail_length;
};

struct Dog {
    union {
        Animal animal[1];
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
inline static void 
Object_init(Object* object) {
    *object = (Object) {
        .x = 0, 
        .y = 0,
        .m = 1, 
        .introspection = Object_introspection  
    };
}

inline static void 
Object_deinit(Object* object) {
	// ..
}

inline static Object* 
Object_new() {
    Object* object = malloc(sizeof(Object));
    Object_init(object);
    return object;
}

inline static void 
Object_move(Object* object, int x, int y) {
    object->x+=x;
    object->y+=y;
}

inline static void
Object_free(Object* object) {
	free(object);
}

// -------------------------------------------------------

inline static void
Animal_introspection (void* animal) {
    Object_introspection(animal);
    Animal* a = animal;
    printf("Animal: age: %d\n", a->age);
}

static void
Animal_voice(void* animal) {
    printf("...\n");
}

inline static void 
Animal_init(Animal* animal) {
	Object_init(animal->object);
    animal->age = 5;
    animal->voice = Animal_voice;
    animal->introspection = Animal_introspection;
}

inline static void 
Animal_deinit(Animal* animal) {
	Object_deinit(animal->object);
}

inline static Animal*
Animal_new() {
    Animal* animal = malloc(sizeof(Animal));
    Animal_init(animal);
    return animal;
}

inline static void
Animal_free(Animal* animal) {
    Animal_deinit(animal);
    free(animal); 
}

// ----------------------------------------------------

inline static void
Cat_introspection (void* cat) {
    Animal_introspection(cat);
    Cat* c = cat;
    printf("Cat: tail: %d\n", c->tail_length);
}

inline static void
Cat_voice(void* cat) {
    printf("Meow!\n");
}

inline static void
Cat_init(Cat* cat) {
    Animal_init(cat->animal);
    cat->introspection = Cat_introspection;
    cat->voice = Cat_voice;
    cat->tail_length = 10;
}

inline static void
Cat_deinit(Cat* cat) {
    Animal_deinit(cat->animal);
}

inline static Cat*
Cat_new() {
    Cat* cat = malloc(sizeof(Cat));
    Cat_init(cat);
    return cat;
}

inline static void
Cat_free(Cat* cat) {
    Cat_deinit(cat);
	free(cat);
}

// -------------------------------------------------------

inline static void
Dog_voice(void* dog) {
    printf("Bark!\n");
}

inline static void
Dog_init(Dog* dog) {
    Animal_init(dog->animal);
    dog->teeth_count = 10;
    dog->voice = Dog_voice;
}

inline static void
Dog_deinit(Dog* dog) {
    Animal_deinit(dog->animal);
}

inline static Dog*
Dog_new() {
    Dog* dog = malloc(sizeof(Dog));
    Dog_init(dog);
    return dog;
}

inline static void
Dog_free(Dog* dog) {
    Dog_deinit(dog);
    free(dog);
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
    Cat* cat = Cat_new();
    Dog* dog = Dog_new();
    cat->introspection(cat);
    Object_move(cat->object, 10, -10);
    cat->introspection(cat);
    dog->introspection(dog);
    cat->voice(cat);
    dog->voice(dog);
    Dog_free(dog);
    Cat_free(cat);
}
