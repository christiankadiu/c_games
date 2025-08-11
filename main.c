#include <ncurses.h>
#include <time.h>
#include "logic.h"
#include "out.h"

int main(){
    srand(time(NULL));

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    struct point *fruits;
    struct point *snake;
    struct board *board;
    enum Direction dir = RIGHT;
    int ymax;
    int xmax;
    int ymin, xmin;
    getbegyx(stdscr, ymin, xmin);
    getmaxyx(stdscr, ymax, xmax);
    int x_initial = (rand() % (xmax - xmin));
    int y_initial = (rand() % (ymax - ymin));
    snake = create_snake(x_initial, y_initial);
    fruits = create_fruits();
    board = create_board(snake, fruits, xmax, ymax);

    while(1){
        clear();
        display_snake(board->snake);
        display_fruits(board->fruits);
        dir = get_direction(dir);
        refresh();
        moveSnake(dir, board);
    }
    endwin();
    return 0;
}
