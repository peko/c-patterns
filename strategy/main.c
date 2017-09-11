#include "cat.h"

int main() {
    for(int i=0; i< 10; i++) {
    	cat_p cat = cat_new();

		cat_do_things(cat);
		cat_do_things(cat);
		cat_do_things(cat);

    	cat_del(cat);
    }
}
