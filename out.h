#include <ncurses.h>
#include "logic.h"

void display_snake(struct point* snake);

void display_fruits(struct fruit* fruits);

enum DIRECTION get_direction(enum DIRECTION previous);
