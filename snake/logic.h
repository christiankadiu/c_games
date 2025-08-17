#ifndef LOGIC_H
#define LOGIC_H


#include <ncurses.h>
/* variabile che gestisce la terminazione del gioco*/
int toQuit;

enum DIRECTION {UP, DOWN, LEFT, RIGHT, STOP};

typedef struct dimensions{
        int xmin;
        int xmax;
        int ymin;
        int ymax;
}dimensions;

typedef struct point{
    int x;
    int y;
    struct point *next;
} point;

typedef struct fruit{
    int x;
    int y;
} fruit;

typedef struct board{
    struct point *snake;
    struct fruit *fruits;
    int xmax;
    int ymax;
} board;

struct point* create_snake(int x, int y);

struct fruit* create_fruits(struct dimensions *dimes);

struct board* create_board(struct point *snake, struct fruit *fruits, struct dimensions *dimes);

void moveSnake(enum DIRECTION dir, struct point** snake, struct fruit* fruits, dimensions *dimes);

#endif





