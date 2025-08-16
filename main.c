#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "logic.h"
#include "out.h"

int main(){
    srand(time(NULL));

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); // hide cursor
    timeout(60);
    
   // int *toQuit = 0;
    struct dimensions *dimes;
    struct fruit *fruits;
    struct point *snake;
    struct board *boa;
    enum DIRECTION dir = RIGHT;
    getmaxyx(stdscr, dimes->ymax, dimes->xmax); 
    getbegyx(stdscr, dimes->ymin, dimes->xmin);
    int x_initial = rand() % (dimes->xmax - dimes->xmin);
    int y_initial = (rand() % (dimes->ymax - dimes->ymin));
    snake = create_snake(x_initial, y_initial);
    fruits = create_fruits(dimes);
    boa = create_board(snake, fruits, dimes);

    while(1){
        clear();
        display_snake(boa->snake);
        display_fruits(boa->fruits);
        dir = get_direction(dir);
        if (dir == STOP) break;
        moveSnake(dir, &boa->snake, boa->fruits, dimes);
        if (toQuit == 1) break;
        refresh();
    }
    endwin();
    return 0;
}
