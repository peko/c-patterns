Mojoc strictly follow this OOC programing model. This model supports C language to build large and complex projects. Because tailored for C unique features, so this model still keep simple to use and easy to understand.

* [Singleton](#singleton)
* [Encapsulation](#encapsulation)
* [Inheritance](#inheritance)
* [Composite](#composite)
* [Polymorphism](#polymorphism)
* [Override](#override)
* [Memory](#memory)
* [Samples](#samples)

## Singleton
The Singleton pattern is very important to Mojoc. In C language the data and behavior are separated and there is no namespace. The singleton can abstract a group of behavior and give it namespace. This model build a parallel data struct and behavior struct that correspond to the class of OOP model.

* In .h file
  ```c
  struct ADrawable
  {
      Drawable* (*Create)();  
      void      (*Init)  (Drawable* outDrawable);
  };


  extern struct ADrawable ADrawable[1];
  ```
  
  * The ADrawable is singleton, global unique.
  * The struct ADrawable is type name, ADrawable[1] is object name.
  * The ADrawable object defined as a array, can let it used like a ptr.

* In .c file
  ```c
  static Drawable* Create()
  {
      return (Drawable*) malloc(sizeof(Drawable));
  }

 
  static void Init(Drawable* outDrawable)
  {
      // init outDrawable
  }


  struct ADrawable ADrawable[1] =
  {
      Create,  
      Init,
  };
  ```
 
  * Just initialize the singleton ADrawable object.


## Encapsulation
* In .h file
  ```c
  typedef struct Drawable Drawable;  
  struct  Drawable  
  {  
      float positionX;  
      float positionY;  
  };


  typedef struct 
  {  
      Drawable* (*Create)();  
      void      (*Init)  (Drawable* outDrawable);  
  }  
  ADrawable;  
  

  extern ADrawable ADrawable[1]; 
  ```
  
  * The Drawable object hold the data.
  * The ADrawable object hold the behavior.
  * The Create function malloc the Drawable memory like new keyword.
  * The Init function initialize Drawable which memory already exists, often in stack or in superclass memory.

## Inheritance
The inheritance is superclass struct all datas are embedded in subclass struct. Then one malloc can get all memory in inheritance chain, and one free on subclass object can release all memory in inheritance chain.

  ```c
  typedef struct Drawable Drawable;  
  struct  Drawable  
  {  
      int a;
  };


  typedef struct
  {
      Drawable drawable[1];
  }
  Sprite;


  struct ASprite
  {
      Sprite* (*Create)();  
      void    (*Init)  (Sprite* outSprite);  
  };
  ```

* The Drawable is superclass.
* The Sprite   is subclass.
* The drawable[1] as array, can let it used like a ptr.
* In ASprite function Create and Init, indirect call ADrawable->Init for initialize superclass memory.
* In C there is no limit of inheritance number, the subclass can inheritance any numbers of superclass. This is a new angle of abstract.

#### How to visit subclass from superclass ?

```c
/**
 * Get struct pointer from member pointer
 */
#define AStruct_GetParent2(memberPtr, structType) \
	((structType*) ((char*) memberPtr - offsetof(structType, memberPtr)))


Sprite* sprite = AStruct_GetParent2(drawable, Sprite);
```

* First, get the superclass offset in subclass struct.
* Second, get the subclass ptr from superclass ptr by superclass offset.
* With this ability, we can hold superclass ptr execute same interface, but different implementation of subclass. This is polymorphism.

## Composite
The composite is independent struct ptr are embedded in struct .

```c
typedef struct Drawable Drawable;  
struct  Drawable  
{  
    Drawable* parent;
}; 
```

* The parent composite into Drawable, the memory manage by independent Create and Release of parent.

## Polymorphism

```c
typedef struct Drawable Drawable;  
struct  Drawable  
{   
    void (*Draw)(Drawable* drawable);  
};  
```

* The function Draw in struct, means different Drawable object can has own implementation of Draw.

```c
typedef struct  
{  
    Drawable drawable[1];  
}  
Hero;


typedef struct  
{  
    Drawable drawable[1];  
}  
Enemy; 


Drawable drawables[] =   
{  
    hero->drawable,  
    enemy->drawable,  
};  


for (int i = 0; i < 2; i++)  
{  
    Drawable* drawable = drawables[i];  
    drawable->Draw(drawable);  
}
```

* The Hero and Enemy implement own Draw behavior.

## Override
In inheritance chain, usually need to override superclass function and call superclass function.

```c
typedef struct  
{  
    Drawable drawable[1];  
}  
Sprite;  


struct ASprite
{  
    void (*Draw)(Drawable* drawable);  
};  


extern ASprite ASprite;  
```

* If we want to override Sprite's Draw function, we need to publish Draw to ASprite. Then we override it, that still can call original Draw.

```c
typedef struct  
{  
    Sprite sprite[1];  
}  
SpriteBatch;


// subclass implementation  
static void SpriteBatchDraw(Drawable* drawable)  
{  
      // call father  
      ASprite->Draw(drawable);
      
      // do extra things...
}  


// override
spriteBatch->sprite->drawable->Draw = SpriteBatchDraw;
```

## Memory
* Release, delete struct member ptr memory which composite into struct and Create by struct self.
* Create, malloc struct memory and delete by free and Release if needed.
* Init, initialize struct memory and delete by Release if needed.

## Samples
* [Drawable.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Draw/Drawable.h)
* [Drawable.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/Draw/Drawable.c)
* [Sprite.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Sprite.h)
* [Sprite.c](https://github.com/scottcgi/Mojoc/blob/master/Engine/Graphics/OpenGL/Sprite.c)
* [Struct.h](https://github.com/scottcgi/Mojoc/blob/master/Engine/Toolkit/Head/Struct.h)