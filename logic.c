#include "logic.h"
#include <ncurses.h>

struct point* create_snake(int x, int y){
    a = (struct *point)malloc(sizeof(struct point));
    b = (struct *point)malloc(sizeof(struct point));
    a->x = x;
    a->y = y;
    a->next = b;
    b->x = a->x + 1;
    b->y = a->y;
    b->next = NULL;
    return a;
}

struct board* create_board(struct point *snake, struct point *fruits, int xmax, int ymax){
    board = (struct *board)malloc(sizeof(struct board));
    board->snake = snake;
    board->fruits = fruits;
    board->xmax = xmax;
    board->ymax = ymax;
    return board;
}