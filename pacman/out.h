#ifndef OUT_H
#define OUT_H

#include <stdio.h>
#include <ncurses.h>
#include "logic.h"
#define MURO '#'
#define PAC 'P'

void stampa(int rows, int cols, char matrice[rows][cols]);

direction getDirection(direction dir);

void displayElements(int rows, int cols, char mappa[rows][cols], pacman* pac);

#endif
