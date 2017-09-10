#include <stdio.h>
#include <unistd.h>

#include "cat.h"

int main() {
	cat_p cat = cat_new();
	for(int i=0;;i++) {
    	printf("[%d]          \n",i);
		cat_print(cat);
		cat_update(cat);

		printf("\033[5A"); // Move up X lines;
		// printf("\033[XB"); // Move down X lines;
		// printf("\033[XC"); // Move right X column;
		// printf("\033[XD"); // Move left X column;
		// printf("\033[2J"); // Clear screen
		
		usleep(1e4);
    }
	cat_del(cat);
}
