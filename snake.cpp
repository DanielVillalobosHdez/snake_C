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
void teclas_mov(struct Snake *vel);

int main(){
    int size = 3;
    struct Snake body[T];
    struct Snake obj;
    struct Snake vel = {0, 0};
    int contador = 0;


    srand(time(NULL));	

    initscr();
    curs_set(0);
    /* keypad(stdscr, true);*/
    noecho();
    calcular_comienzo(body, size);
    posicionar_objeto(&obj);

    while(1){
        clear();
       // mvprintw(0, 0, "%i", size);
        mover(body, size, vel);
        pintar(body, size);
        pintar_objeto(&obj);
        if(body[0].y == obj.y && body[0].x == obj.x){
            size++;
            posicionar_objeto(&obj);
        }
        halfdelay(1);
        teclas_mov(&vel);
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

    if(body[0].x == -1 || body[0].y == -1 || body[0].x == COLS || body[0].y == LINES){
        endwin();
        exit(1);
    }
}
void pintar_objeto(struct Snake *obj){

    mvprintw(obj->y, obj->x, "$");
}
void coger(struct Snake body[T], struct Snake *obj, int size){
    if(body[0].y == obj->y && body[0].x == obj->x)
        size++;
}

void posicionar_objeto(struct Snake *obj){
    obj -> x = rand() % COLS -1;
    obj -> y = rand() % LINES -1 ;
}

void teclas_mov (struct Snake *vel){
    char mv;
    int ult_pos_y, ult_pos_x;

    mv = getch();

    switch(mv) {
        case 'w':
        case 'W':
            //  case NCURSES_KEY_UP:
            if(vel->y == 0){
                vel->y = -1;
                vel->x = 0;
                ult_pos_y = vel->y;
                ult_pos_x = vel->x;
            }
            break;
        case 'a':
        case 'A':
            //case NCURSES_KEY_LEFT:
            if(vel->x == 0){
                vel->x = -1;
                vel->y = 0;
                ult_pos_y = vel->y;
                ult_pos_x = vel->x;
            }
            break;
        case 's':
        case 'S': 
            //case NCURSES_KEY_DOWN:
            if(vel->y == 0){
                vel->y = 1;
                vel->x = 0;
                ult_pos_y = vel->y;
                ult_pos_x = vel->x;
            }
            break;
        case 'd':
        case 'D':
       // case NCURSES_KEY_RIGHT:
            if(vel->x == 0){
                vel->x = 1;
                vel->y = 0;
                ult_pos_y = vel->y;
                ult_pos_x = vel->x;
            }
            break;
        default:
            ult_pos_y;
            ult_pos_x;
            break;
    }
}
