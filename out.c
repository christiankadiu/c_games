#include <ncurses.h>
#include "out.h"
#include "logic.h"

#define BODY ('#')
#define FRUIT ('*')

void display_snake(struct point *snake){
    while (snake){
        mvaddch(snake->y, snake->x, BODY);
        snake = snake->next;
    }
}

void display_fruits(struct fruit *fruits){
    if (fruits){
        mvaddch(fruits->y, fruits->x, FRUIT);
    }
}


enum DIRECTION get_direction(enum DIRECTION previous) {
  int ch = getch();
  switch (ch) {
    case KEY_LEFT:
      if (previous != RIGHT) return LEFT;
    break;
    case KEY_RIGHT:
      if (previous != LEFT) return RIGHT;
    break;
    case KEY_DOWN:
      if (previous != UP) return DOWN;
    break;
    case KEY_UP:
      if (previous != DOWN) return UP;
    break;
    case 113:
        return STOP;
        break;
  }
  return previous;
}

