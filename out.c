#include <ncurses.h>
#include <out.c>
#include <logic.g>

#define BODY ('#')
#define FRUIT ('*')

void display_snake(struct point *snake){
    while (snake){
        mvaddch(snake->x, snake->y, BODY);
        snake = snake->next;
    }
}

void display_fruits(struct point *fruits){
    while (fruits){
        mvaddch(fruits->x, fruits->y, FRUIT);
        fruits = fruits->next;
    }
}

enum Direction get_direction(enum Direction prev){
    ch = getch();
    switch(ch){
        case KEY_LEFT:
            if (prev != KEY_RIGHT) return Direction.LEFT;
        case KEY_RIGHT:
            if (prev != KEY_LEFT) return Direction.RIGHT;
        case KEY_UP:
            if (prev != KEY_DOWN) return Direction.UP;
        case KEY_DOWN:
            if (prev != KEY_UP) return Direction.DOWN;
        default: return prev;
    }
}

