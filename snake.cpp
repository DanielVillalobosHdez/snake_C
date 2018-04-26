#include <stdio.h>
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
void pintar(struct Snake body[T], int size);
void mover(struct Snake body[T], int size, struct Snake vel);

int main(){
    int size = 3;
    struct Snake body[T];
    struct Snake obj;
    struct Snake vel = {1., 0};

    initscr();
    curs_set(0);
    calcular_comienzo(body, size);

    while(1){

        clear();
        mover(body, size, vel);
        pintar(body, size);
    	/*Comprobar();*/
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
}

