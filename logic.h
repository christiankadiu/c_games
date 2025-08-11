#include <ncurses.h>

enum DIRECTION {UP, DOWN, LEFT, RIGHT};

typedef struct{
    int x;
    int y;
    struct point *next;
} point;

typedef struct {
    struct point *snake;
    struct point *fruits;
    int xmax;
    int ymax;
} board;

void moveSnake()



