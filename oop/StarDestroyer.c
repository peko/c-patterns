#include <stdlib.h>
#include <stdio.h>

#include "Struct.h"
#include "StarDestroyer.h"

//-------------------------------------------------------------------------------------------------------------------------

static StarDestroyer* Create ();
static void Init    (StarDestroyer* outStarDestroyer);
static void Release (StarDestroyer* starDestroyer   );
static void Destroy (StarDestroyer* starDestroyer   );

static void _Update  (SpaceShip* spaceShip);
static void _Describe(SpaceShip* spaceShip);

//-------------------------------------------------------------------------------------------------------------------------

static StarDestroyer* 
Create() 
{
    printf("Создание корабля\n");
    StarDestroyer* starDestroyer = malloc(sizeof(StarDestroyer));
    Init(starDestroyer);
    return starDestroyer;
}


static void 
Init(StarDestroyer* outStarDestroyer)
{
    printf("Инициализация уничтожителя\n");
    ASpaceShip->Init(outStarDestroyer);

    // Переназначеие базовых методов
    outStarDestroyer->Describe = _Describe;
    outStarDestroyer->Update   = _Update;

    outStarDestroyer->m = 1000;
    outStarDestroyer->fuel = 500+random()%100;
    outStarDestroyer->beamEnergy = 0.0;
    outStarDestroyer->m += outStarDestroyer->fuel;

    // Создаем дочерние корабли
    int n = 3;
    outStarDestroyer->tieFightersCount = n;
    outStarDestroyer->tieFighters = malloc(sizeof(SpaceShip*)*n);
    for(int i = 0; i<n; ++i)
    {
       outStarDestroyer->tieFighters[i] = ASpaceShip->Create();
    }
    
    printf("Уничтожитель инициализирован\n");
}


// Высвобождаем созданные ресурсы 
static void
Release(StarDestroyer* starDestroyer)
{
    printf("Oсвобождение ресурсов уничтожителя\n");

    // Освобождаем истребители
    int n = starDestroyer->tieFightersCount;
    for(int i = 0; i<n; ++i)
    {
       ASpaceShip->Destroy(starDestroyer->tieFighters[i]);
    }    
    free(starDestroyer->tieFighters);
    
    ASpaceShip->Release(starDestroyer);
    printf("Ресурсы уничтожителя освобождены\n");
}


// Удаляем саму структуру
static void
Destroy(StarDestroyer* starDestroyer)
{
    Release(starDestroyer);
    free(starDestroyer);
    printf("Уничтожитель уничтожен\n");
}

//-------------------------------------------------------------------------------------------------------------------------


static void 
Describe(StarDestroyer* starDestroyer) 
{
    printf("Описание уничтожителя\n"
    "\tTie Fighters: %10d\n" 
    "\tBeam energy : %10.2f\n", 
    starDestroyer->tieFightersCount,
    starDestroyer->beamEnergy);
    
    printf("Описание дочерних тай-файтеорв\n");
    int n = starDestroyer->tieFightersCount;
    for(int i = 0; i<n; ++i)
    {
       ASpaceShip->Describe(starDestroyer->tieFighters[i]);
    }
} 


static void 
_Describe(SpaceShip* spaceShip) 
{
    StarDestroyer* starDestroyer = AStruct_GetParent2(spaceShip, StarDestroyer);
    ASpaceShip->Describe(spaceShip);
    Describe(starDestroyer);    
}


static void 
Update(StarDestroyer* starDestroyer) 
{
    printf("Обновление параметров уничтожителя\n");
    starDestroyer->beamEnergy +=0.1;
    
    printf("Обновление параметров тай-файтеров\n");
    int n = starDestroyer->tieFightersCount;
    for(int i = 0; i<n; ++i)
    {
       ASpaceShip->Update(starDestroyer->tieFighters[i]);
    }
}


static void 
_Update(SpaceShip* spaceShip) 
{
    StarDestroyer* starDestroyer = AStruct_GetParent2(spaceShip, StarDestroyer);
    ASpaceShip->Update(spaceShip);
    Update(starDestroyer);
}


// singelton энкапсулация поведения
struct AStarDestroyer 
AStarDestroyer[1] =  {
    Create,
    Init,
    Release,
    Destroy,
};
