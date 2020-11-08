#include <stdlib.h>
#include <stdio.h>

#include "Object.h"

//-------------------------------------------------------------------------------------------------------------------------

static Object* Create ();
static void Init    (Object* outObject);
static void Release (Object* object   );
static void Destroy (Object* object   );

static void Update  (Object* object   );
static void Describe(Object* object   );

//-------------------------------------------------------------------------------------------------------------------------

static Object* 
Create() 
{
    printf("Создание объекта\n");
    Object* object = malloc(sizeof(Object));
    Init(object);
    return object;
}


static void 
Init(Object* outObject)
{
    printf("Инициализация объекта\n");
    *outObject = (struct Object){
        .m  = random()%10,
        .s  = random()%20,
        .px = 100-random()%200,
        .py = 100-random()%200,
        .vx =  10-random()% 20,
        .vy =  10-random()% 20,

        .Update   = Update,
        .Describe = Describe,
    };

    
    printf("Объект инициализирован\n");
}


// Высвобождаем созданные ресурсы 
static void
Release(Object* object)
{
    printf("Oсвобождение ресурсов объекта\n");
    // ...
    printf("Ресурсы объекта освобождены\n");
}


// Удаляем саму структуру
static void
Destroy(Object* object)
{
    Release(object);
    free(object);
    printf("Объект уничтожен\n");
}

//-------------------------------------------------------------------------------------------------------------------------

static void 
Describe(Object* object) 
{
    printf("Опинсание физического объекта\n"
      "\tm : %+10.2f\n"
      "\ts : %+10.2f\n"
      "\tpx: %+10.2f\n"
      "\tpy: %+10.2f\n"
      "\tvx: %+10.2f\n"
      "\tvy: %+10.2f\n",
      object->m , object->s, 
      object->px, object->py,
      object->vx, object->vy);
}


static void 
Update(Object* object) 
{
    printf("Обновление базовой физики объекта\n");
    object->px += object->vx;
    object->py += object->vy; 
}


// singelton энкапсулация поведения
struct AObject 
AObject[1] =  {
    Create,
    Init,
    Release,
    Destroy,
    
    // Доступа из дочерних классов, после переназначения
    Describe,
    Update,
};
