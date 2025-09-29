#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

typedef struct pacman{
    int x;
    int y;
} pacman;


typedef enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
}direction;

typedef struct ghost{
    int x;
    int y;
    enum direction prev;
    struct ghost *next;
} ghost;

void stampa(int rows, int cols, char matrice[rows][cols]);

void updatePosition(int rows, int cols, char matrice[rows][cols], pacman* p, direction d);

void updateGhostsPosition(int rows, int cols, char matrice[rows][cols], ghost* fantasmi);

#endif
