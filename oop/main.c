#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "SpaceShip.h"
#include "Object.h"

int main(void) {
   SpaceShip* spaceShip = ASpaceShip->Create();
   Object* object = spaceShip->object;
   for(int i=0; i<150; ++i)
   {
     // printf("\e[1;1H\e[2J");
     // usleep(10000);
     object->Update(object);
     object->Describe(object);
   }

   ASpaceShip->Destroy(spaceShip);
}
