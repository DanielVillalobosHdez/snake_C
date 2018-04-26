#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define N 4
#define T 25 /*Maximo del cuerpo*/
struct Snake {
	double x;
	double y;

};
void calcular_comienzo(struct Snake body[T], int size);
void posicionar_objeto(struct Snake *obj);
void pintar(struct Snake body[T], int size);
void mover(struct Snake body[T], int size, struct Snake vel);
void pintar_objeto(struct Snake *obj);
void coger(struct Snake body[T], struct Snake *obj, int size);

int main(){
	int size = 3;
	struct Snake body[T];
	struct Snake obj;
	struct Snake vel = {1., 0};
	int contador = 0;

	
	srand(time(NULL));	

	initscr();
	curs_set(0);
	calcular_comienzo(body, size);
	posicionar_objeto(&obj);

	while(1){
		clear();
		mover(body, size, vel);
		pintar(body, size);
		pintar_objeto(&obj);
		if(body[0].y == obj.y && body[0].x == obj.x){
                	size++;
			posicionar_objeto(&obj);
		}
		refresh();
		usleep(100000);
	}
	endwin();


	return EXIT_SUCCESS;

}
void calcular_comienzo(struct Snake body[T], int size){

	int a = LINES/2;
	int b = COLS /2;
	for( int c ; c<size ; c++){
		body[c].y = a;
		body[c].x = b + c;
	}
}
void pintar(struct Snake body[T], int size){

	for (int i = 0 ;  i<size ; i++)
		mvprintw((int) body[i].y, body[i].x, "0");

}

void mover(struct Snake body[T], int size, struct Snake vel){
	for(int m = size-1; m > 0; m--){
		body[m].x = body[m-1].x;
		body[m].y = body[m-1].y;
	}

	body[0].x += vel.x;
	body[0].y += vel.y;

	if(body[0].x == 0 || body[0].y == 0 || body[0].x == COLS || body[0].y == LINES){
		endwin();
		exit(1);
	}
}
void pintar_objeto(struct Snake *obj){

	mvprintw(obj->y, obj->x, "*");
}
void coger(struct Snake body[T], struct Snake *obj, int size){
	if(body[0].y == obj->y && body[0].x == obj->x)
		size++;
}

void posicionar_objeto(struct Snake *obj){
	obj -> x = rand() % COLS -1;
        obj -> y = rand() % LINES -1 ;
}
