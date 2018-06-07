#include <stdlib.h>
#include <stdio.h>

int tabs = 0;
void ptabs(){ for(int i=0;i<tabs;i++) printf("\t"); }

typedef struct Drawable Drawable;
void Drawable_dtor(Drawable* drawable);
Drawable* Drawable_ctor();

struct Drawable {
	int		x,y,a;	
};

void Drawable_init(Drawable* outDrawable){
	printf("Drawable init\n");
	outDrawable->x=1;
	outDrawable->y=2;
	outDrawable->a=3;
}
Drawable* Drawable_ctor() {
	Drawable* drawable = malloc(sizeof(Drawable));
	//drawable->ctor=Drawable_ctor;
	//drawable->dtor=Drawable_dtor;
	Drawable_init(drawable);
	return drawable;
}
void Drawable_dtor(Drawable* drawable) {

	printf("Drawable release\n");
	// Free own shit
	//...
	
	// finaly dealloc pointer
	free(drawable);
}
void Drawable_move(Drawable* drawable, int x, int y){
	drawable->x+=x;
	drawable->y+=y;
}

// -------------------------------------------------------

typedef struct Square Square;
struct Square {
	Drawable drawable[1];
	int size;
	int* texture;
};
void Square_init(Square* outSquare){
	printf("Square init\n");
	tabs++; ptabs();
	Drawable_init((Drawable*)outSquare);
	tabs--;
	outSquare->size = 10;
	outSquare->texture = malloc(10);
	outSquare->texture[0] = 33;
}
Square* Square_ctor() {
	Square* square = malloc(sizeof(Square));
	Square_init(square);
	return square;
}
void Square_dtor(Square* square) {

	printf("Square release\n");
	// Free own shit
	free(square->texture);
	tabs++; ptabs();
	// Ask parent to cleanup
	Drawable_dtor((Drawable*)square);
	tabs--;
}

// -----------------------------------------------------

typedef struct RoundedSquare RoundedSquare;
struct RoundedSquare {
	Square square[1];
	int radius;
};
void RoundedSquare_init(RoundedSquare* outRoundedSquare){
	printf("RoundedSquare init\n");
	tabs++; ptabs();
	Square_init((Square*)outRoundedSquare);
	tabs--;
	outRoundedSquare->radius = 3;
}
RoundedSquare* RoundedSquare_ctor() {
	RoundedSquare* square = malloc(sizeof(RoundedSquare));
	RoundedSquare_init(square);
	return square;
}
void RoundedSquare_dtor(RoundedSquare* square) {
	// Free own shit
	// ...
	printf("RoundedSquare release\n");	
	// Ask parent to cleanup
	tabs++; ptabs();
	Square_dtor((Square*)square);
	tabs--;
}

#define new(Class) Class ## _ctor()
#define del(Class, Instance) Class ## _dtor(Instance)

int main(void) {
	Square* s1 = new(Square);
	RoundedSquare* s2 = new(RoundedSquare);
	Drawable_move(s2->square->drawable,-1,-2);
	Drawable* d = (Drawable*)s1;
	printf("%d %d \n",d->x, d->y);
	d = (Drawable*)s2;
	printf("%d %d \n",d->x, d->y);
	Square* s = (Square*)s2;
	printf("%d\n", s->texture[0]);
	del(Square, s1);
	del(RoundedSquare, s2);
}
