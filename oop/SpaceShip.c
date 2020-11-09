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
    SpaceShip* spaceShip = malloc(sizeof(SpaceShip));
    Init(spaceShip);
    return spaceShip;
}


static void 
Init(SpaceShip* outSpaceShip)
{
    printf("Инициализация корабля\n");
    AObject->Init(outSpaceShip);

    // Переназначеие базовых методов
    outSpaceShip->Describe = _Describe;
    outSpaceShip->Update   = _Update;

    outSpaceShip->id   = random()%10000; 
    outSpaceShip->fuel = 5+random()%10;
    outSpaceShip->m   += outSpaceShip->fuel;

    printf("Корабль инициализирован #%06d\n", outSpaceShip->id);
}


// Высвобождаем созданные ресурсы 
static void
Release(SpaceShip* spaceShip)
{
    printf("Oсвобождение ресурсов корабля #%06d\n", spaceShip->id);
    AObject->Release(spaceShip);
    printf("Ресурсы корабля освобождены #%06d\n", spaceShip->id);
}


// Удаляем саму структуру
static void
Destroy(SpaceShip* spaceShip)
{
    Release(spaceShip);
    free(spaceShip);
    printf("Корабль уничтожен #%06d\n", spaceShip->id);
}

//-------------------------------------------------------------------------------------------------------------------------


static void 
Describe(SpaceShip* spaceShip) 
{
    printf("Описание корабля #%06d\n"
    "\tfuel: %+10.2f\n",
    spaceShip->id,
    spaceShip->fuel);
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
    printf("Обновление параметров корабля #%06d\n", spaceShip->id);
    if(spaceShip->fuel >0.0) {
      spaceShip->fuel -= 0.1;
      spaceShip->m -= 0.1;
      spaceShip->vx *=1.01;
      spaceShip->vy *=1.01;
    } else {
      spaceShip->vx *=0.5;
      spaceShip->vy *=0.5;
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
    _Update,
    _Describe,
};
