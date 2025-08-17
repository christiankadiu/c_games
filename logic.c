#include "logic.h"
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

int toQuit = 0;

struct point* create_snake(int x, int y){
    struct point* a = (struct point*)malloc(sizeof(struct point));
    struct point* b = (struct point*)malloc(sizeof(struct point));
    b->x = x;
    b->y = y;
    b->next = a;
    a->x = b->x + 1;
    a->y = b->y;
    a->next = NULL;
    return a;
}

struct board* create_board(struct point *snake, struct fruit *fruits, struct dimensions *dimes){
    struct board *b = (struct board*)malloc(sizeof(struct board));
    b->snake = snake;
    b->fruits = fruits;
    b->xmax = dimes->xmax;
    b->ymax = dimes->ymax;
    return b;
}

struct fruit* create_fruits(struct dimensions *dimes){
    struct fruit *fruits = (struct fruit*)malloc(sizeof(struct fruit));
    fruits->x = rand() % (dimes->xmax - dimes->xmin);
    fruits->y = rand() % (dimes->ymax - dimes->ymin);
    /*fruits->x = dimes->xmin;
    fruits->y = dimes->ymax - 1;*/
    return fruits;
}

void add_head(struct point** snake, int deltaX, int deltaY, dimensions *dimes){
    struct point* new = (struct point*)malloc(sizeof(struct point));
    new->x = (*snake)->x + deltaX;
    if (new->x >= dimes->xmax){
        new->x = new->x % dimes->xmax;
    } 
    if (new->x < dimes->xmin){
        new->x += dimes->xmax; 
    }
    new->y = (*snake)->y + deltaY;
    if (new->y >= dimes->ymax){
        new->y = new->y % dimes->ymax;
    } 
    if (new->y < dimes->ymin){
        new->y += dimes->ymax; 
    }
    new->next = *snake;
    *snake = new;
}

bool checkCollisions(fruit* fruits, point* snake){
    if (snake->x == fruits->x && snake->y == fruits->y) return true;
    return false;
}

bool checkBodyCollision(point* snake){
   point *tmp2 = snake->next;
   while(tmp2){
       if (snake->x == tmp2->x && snake->y == tmp2->y){
            return true;
       }
       tmp2 = tmp2->next;
   }
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

void spawn_fruit(fruit* fruits, dimensions *dimes){
    if (fruits != NULL){
        fruits->y = rand() % (dimes->ymax - dimes->ymin);
        fruits->x = rand() % (dimes->xmax - dimes->xmin);
    }
}

void moveSnake(enum DIRECTION dir, struct point** snake, struct fruit* fruits, dimensions *dimes){
    switch (dir){
        case RIGHT:
            add_head(snake, 1, 0, dimes);
            if (checkBodyCollision(*snake)){
                toQuit = 1;
                return;
            }
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
               spawn_fruit(fruits, dimes);
            }
        break;

        case LEFT:
            add_head(snake, -1, 0, dimes);
            if (checkBodyCollision(*snake)){
                toQuit = 1;
                return;
            }
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                spawn_fruit(fruits, dimes);
            }
        break;

        case UP:
            add_head(snake, 0, -1, dimes);
            if (checkBodyCollision(*snake)){
                toQuit = 1;
                return;
            }
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                spawn_fruit(fruits, dimes);
            }
        break;

        case DOWN:
            add_head(snake, 0, 1, dimes);
            if (checkBodyCollision(*snake)){
                toQuit = 1;
                return;
            }
            if (!checkCollisions(fruits, *snake)){
                remove_tail(snake);
            }else{
                spawn_fruit(fruits, dimes);
            }
        break;
    }
}
