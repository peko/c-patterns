#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "StarDestroyer.h"

int main(void) {
   StarDestroyer* sd = AStarDestroyer->Create();
   for(int i=0; i<150; ++i)
   {
     sd->Update(sd);
     sd->Describe(sd);
   }

   AStarDestroyer->Destroy(sd);
}
