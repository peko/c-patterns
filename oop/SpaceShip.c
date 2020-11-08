#include <stdlib.h>
#include <stdio.h>

#include "Struct.h"
#include "SpaceShip.h"

//-------------------------------------------------------------------------------------------------------------------------

static SpaceShip* Create ();
static void Init    (SpaceShip* outSpaceShip);
static void Release (SpaceShip* spaceShip   );
static void Destroy (SpaceShip* spaceShip   );

static void _Update  (Object* object);
static void _Describe(Object* object);

//-------------------------------------------------------------------------------------------------------------------------

static SpaceShip* 
Create() 
{
    printf("Создание корабля\n");
    SpaceShip* SpaceShip = malloc(sizeof(SpaceShip));
    Init(SpaceShip);
    return SpaceShip;
}


static void 
Init(SpaceShip* outSpaceShip)
{
    printf("Инициализация корабля\n");
    AObject->Init(outSpaceShip->object);

    // Переназначеие базовых методов
    outSpaceShip->object->Describe = _Describe;
    outSpaceShip->object->Update   = _Update;
    
    outSpaceShip->fuel = 5+random()%10;
    outSpaceShip->object->m += outSpaceShip->fuel;

    printf("Корабль инициализирован\n");
}


// Высвобождаем созданные ресурсы 
static void
Release(SpaceShip* spaceShip)
{
    printf("Oсвобождение ресурсов корабля\n");
    AObject->Release(spaceShip->object);
    printf("Ресурсы корабля освобождены\n");
}


// Удаляем саму структуру
static void
Destroy(SpaceShip* spaceShip)
{
    Release(spaceShip);
    free(spaceShip);
    printf("Корабль уничтожен\n");
}

//-------------------------------------------------------------------------------------------------------------------------


static void 
Describe(SpaceShip* spaceShip) 
{
    printf("Описание корабля\n"
    "\tfuel: %+10.2f\n", spaceShip->fuel);
} 


static void 
_Describe(Object* object) 
{
    SpaceShip* spaceShip = AStruct_GetParent2(object, SpaceShip);
    AObject->Describe(object);
    Describe(spaceShip);
}


static void 
Update(SpaceShip* spaceShip) 
{
    printf("Обновление параметров корабля\n");
    if(spaceShip->fuel >0.0) {
      spaceShip->fuel -= 0.1;
      spaceShip->object->m -= 0.1;
      spaceShip->object->vx *=1.01;
      spaceShip->object->vy *=1.01;
    } else {
      spaceShip->object->vx *=0.5;
      spaceShip->object->vy *=0.5;
    }
}


static void 
_Update(Object* object) 
{
    SpaceShip* spaceShip = AStruct_GetParent2(object, SpaceShip);
    AObject->Update(object);
    Update(spaceShip);
}


// singelton энкапсулация поведения
struct ASpaceShip 
ASpaceShip[1] =  {
    Create,
    Init,
    Release,
    Destroy,
};
