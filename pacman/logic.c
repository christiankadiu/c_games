#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

#define MURO '#'
#define PAC 'P'


bool isOkay(pacman* p, int rows, int cols) {
    return (p->x >= 0 && p->x < cols) && (p->y >= 0 && p->y < rows);
}

void updatePosition(int rows, int cols, char matrice[rows][cols], pacman* p, direction d) {
    pacman next_pos;
    next_pos.x = p->x;
    next_pos.y = p->y;

    switch (d) {
        case UP:
            next_pos.y--;
            break;
        case DOWN:
            next_pos.y++;
            break;
        case LEFT:
            next_pos.x--;
            break;
        case RIGHT:
            next_pos.x++;
            break;
        case STOP:
            break;
    }

    if (isOkay(&next_pos, rows, cols) && matrice[next_pos.y][next_pos.x] != MURO) {
        p->x = next_pos.x;
        p->y = next_pos.y;
    }
}


