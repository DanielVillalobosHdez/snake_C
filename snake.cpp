#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


struct Snake {
    double x;
    double y;

};
void begin(struct Snake go){
    for (int i=0; i<N; i++){
        go[i].y = LINE/2;
        go[i].x = COLS / 2;
    }
}
int main(){
    int size = 3;
    struct Snake body[i]{};


    initsrc();
    begin(body)
    for (int i = 0 ;  i<size ; i++) {
        mvprintw(body[i].x,body[i].y, "C");
    }
    refresh();
    endwin();



    return EXIT_SUCCESS;
}
