#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#define MURO '#'
#define PAC 'P'



bool isGhostOkay(ghost* p, int rows, int cols){
    return (p->x >= 0 && p->x < cols) && (p->y >= 0 && p->y < rows);
}


bool isOkay(pacman* p, int rows, int cols) {
    return (p->x >= 0 && p->x < cols) && (p->y >= 0 && p->y < rows);
}

int updatePacmanPosition(int rows, int cols, char matrice[rows][cols], pacman* p, direction d){
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
        return 1;
    }
    return 0;
}

void updatePosition(int rows, int cols, char matrice[rows][cols], pacman* p, direction dir, direction prev) {
    if(updatePacmanPosition(rows, cols, matrice, p, dir)) return;
    else updatePacmanPosition(rows, cols, matrice, p, prev);
}

int updateGhost(int rows, int cols, char matrice[rows][cols], ghost* p, direction dir) {
    ghost next_pos;
    next_pos.x = p->x;
    next_pos.y = p->y;
    direction newPos;
    switch (dir) {
        case UP:
            next_pos.y--;
            newPos = UP;
            break;
        case DOWN:
            next_pos.y++;
            newPos = DOWN;
            break;
        case LEFT:
            next_pos.x--;
            newPos = LEFT;
            break;
        case RIGHT:
            next_pos.x++;
            newPos = RIGHT;
            break;
        case STOP:
            break;
    }


    if (isGhostOkay(&next_pos, rows, cols) && matrice[next_pos.y][next_pos.x] != MURO) {
        p->x = next_pos.x;
        p->y = next_pos.y;
        return 1;
    }
    return 0;
}


direction mapping(int n){
    switch(n){
        case 0: 
            return UP; 
            break;
        case 1:
            return RIGHT;
            break;
        case 2:
            return DOWN;
            break;
        case 3:
            return LEFT;
            break;
    }
    return STOP;
}

void updateGhostsPosition(int rows, int cols, char matrice[rows][cols], ghost* fantasmi) {
    while (fantasmi) {
        if (updateGhost(rows, cols, matrice, fantasmi, fantasmi->prev)) {
            fantasmi = fantasmi->next;
            continue; 
        }

        int r;
        direction d;
        do{
            r = rand() % 4;   
            d = mapping(r);
            fantasmi->prev = d;
        }while(updateGhost(rows, cols, matrice, fantasmi, d) == 0);

        fantasmi = fantasmi->next;
    }
}

int checkCollisions(pacman* p, ghost* g){
    while (g){
        return p->x == g->x && p->y == g->y;
    }
    return 0;
}



