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

struct board* create_board(struct point *snake, struct fruit *fruits, struct dimensions dimes){
    struct board *b = (struct board*)malloc(sizeof(struct board));
    b->snake = snake;
    b->fruits = fruits;
    b->xmax = dimes.xmax;
    b->ymax = dimes.ymax;
    return b;
}

struct fruit* create_fruits(struct dimensions dimes){
    struct fruit *fruits = (struct fruit*)malloc(sizeof(struct fruit));
    fruits->x = rand() % (dimes.xmax - dimes.xmin);
    fruits->y = rand() % (dimes.ymax - dimes.ymin);
    return fruits;
}

void add_head(struct point** snake, int deltaX, int deltaY){
    struct point* new = (struct point*)malloc(sizeof(struct point));
    new->x = (*snake)->x + deltaX;
    new->y = (*snake)->y + deltaY;
    new->next = *snake;
    *snake = new;
}

bool checkCollisions(fruit* fruits, point* snake){
    if (snake->x == fruits->x && snake->y == fruits->y) return true;
    return false;
}

void remove_tail(point** snake){   
    point* tmp = *snake;
    while(tmp->next->next){
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

void remove_fruit(fruit* fruits, dimensions dimes){
    if (fruits != NULL){
        fruits = create_fruits(dimes);
    }
}

void moveSnake(enum DIRECTION dir, struct point** snake, struct fruit* fruits, dimensions dimes){
    switch (dir){
        case RIGHT:
            add_head(snake, 1, 0);
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                remove_fruit(fruits, dimes);
            }
        break;

        case LEFT:
            add_head(snake, -1, 0);
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                remove_fruit(fruits, dimes);
            }
        break;

        case UP:
            add_head(snake, 0, -1);
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                remove_fruit(fruits, dimes);
            }
        break;

        case DOWN:
            add_head(snake, 0, 1);
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                remove_fruit(fruits, dimes);
            }
        break;
    }
}
