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
void CalcularComienzo(struct Snake *body[T]);
void Pintar(struct Snake body[T]);

int main(){
    int size = 3;
    struct Snake body[T];
    struct Snake obj;

    initscr();
    curs_set(0);
    CalcularComienzo(&body);

    while(1){ 
	/*MoverCuerpo();
     	*/
	sleep(1);    
    	Pintar(body);
    	/*Comprobar();*/
    
    	refresh();
    }
    endwin();


    return EXIT_SUCCESS;

}
void CalcularComienzo(struct Snake *body[T], int size){

	int a = LINES/2;
	int b = COLS /2;
	for( int c ; c<size ; c++){
	body[c]->y = a + c;
        body[c]->x = b + c;
	}
}
void Pintar(struct Snake body[T], int size){

	for (int i = 0 ;  i<size ; i++) {
        	mvprintw( (int) body[i].x,body[i].y, "C");
    	} 
}
