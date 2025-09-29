#include <stdio.h>
#include <ncurses.h>
#include "out.h"

#define MURO '#'
#define PAC 'P'


void stampa(int rows, int cols, char matrice[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            mvaddch(i, k, matrice[i][k]);
        }
    }
}


direction getDirection(direction prev){
    int ch = getch();
    switch(ch) {
        case KEY_UP:
            return UP;
        case KEY_DOWN:
            return DOWN;
        case KEY_LEFT:
            return LEFT;
        case KEY_RIGHT:
            return RIGHT;
        case 113:
            return STOP;
    }
    return prev;
}


void displayElements(int rows, int cols, char mappa[rows][cols], pacman* pac){
    int i, k;
    for (i = 0; i < rows; i++){
        for (k = 0; k < cols; k++){
            if (mappa[i][k] == MURO){
                mvaddch(i, k, MURO);                
            }
            if (i == pac->y && k == pac->x){
                mvaddch(i, k, PAC);
            }
        }
    }

}
