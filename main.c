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
    timeout(100);

    struct point *fruits;
    struct point *snake;
    struct board *boa;
    enum DIRECTION dir = RIGHT;
    int ymax;
    int xmax;
    int ymin, xmin;
    getbegyx(stdscr, ymin, xmin);
    getmaxyx(stdscr, ymax, xmax);
    int x_initial = rand() % (xmax - xmin);
    int y_initial = (rand() % (ymax - ymin));
    snake = create_snake(x_initial, y_initial);
    fruits = create_fruits(xmin, xmax, ymin, ymax);
    boa = create_board(snake, fruits, xmax, ymax);

    while(1){
        clear();
        display_snake(boa->snake);
        display_fruits(boa->fruits);
        dir = get_direction(dir);
        if (dir == STOP) break;
        moveSnake(dir, &boa->snake, &boa->fruits);
        refresh();
    }
    endwin();
    return 0;
}
