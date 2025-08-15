#ifndef LOGIC_H
#define LOGIC_H


#include <ncurses.h>


enum DIRECTION {UP, DOWN, LEFT, RIGHT};

typedef struct point{
    int x;
    int y;
    struct point *next;
} point;

typedef struct board{
    struct point *snake;
    struct point *fruits;
    int xmax;
    int ymax;
} board;

struct point* create_snake(int x, int y);

struct point* create_fruits(int xmin, int xmax, int ymin, int ymax);

struct board* create_board(struct point *snake, struct point *fruits, int xmax, int ymax);

void moveSnake(enum DIRECTION dir, struct point** snake);

#endif





