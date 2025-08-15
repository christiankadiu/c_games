#include "logic.h"
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

struct point* create_snake(int x, int y){
    struct point* a = (struct point*)malloc(sizeof(struct point));
    struct point* b = (struct point*)malloc(sizeof(struct point));
    a->x = x;
    a->y = y;
    a->next = b;
    b->x = a->x + 1;
    b->y = a->y;
    b->next = NULL;
    return a;
}

struct board* create_board(struct point *snake, struct point *fruits, int xmax, int ymax){
    struct board *b = (struct board*)malloc(sizeof(struct board));
    b->snake = snake;
    b->fruits = fruits;
    b->xmax = xmax;
    b->ymax = ymax;
    return b;
}

struct point* create_fruits(int xmin, int xmax, int ymin, int ymax){
    struct point *fruits = (struct point*)malloc(sizeof(struct point));
    fruits->x = rand() % (xmax - xmin);
    fruits->y = rand() % (ymax - ymin);
    fruits->next = NULL;
    return fruits;
}

void add_head(struct point** snake, int deltaX, int deltaY){
    struct point* new = (struct point*)malloc(sizeof(struct point));
    new->x = (*snake)->x + deltaX;
    new->y = (*snake)->y + deltaY;
    new->next = *snake;
    *snake = new;
}

void moveSnake(enum DIRECTION dir, struct point** snake){
    switch (dir){
        case RIGHT:
            add_head(snake, 1, 0);
        break;

        case LEFT:
            add_head(snake, -1, 0);
        break;

        case UP:
            add_head(snake, 0, -1);
        break;

        case DOWN:
            add_head(snake, 0, 1);
        break;
    }
}