#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "out.h"
#include "logic.h"
#define MURO '#'
#define PUNTO '.'


pacman* init(){
    pacman* p = (pacman*)malloc(sizeof(pacman));
    p->x = 13;
    p->y = 1;
    return p;
}


int main(){

    pacman* pac = init();
    int cols;
    int rows;
    FILE* fp = fopen("mappa.txt", "r");

    if(fp == NULL){
        printf("errore di apertura del file");
        return 1;
    }

    int c = 0;
    while (c <= 0){
        fscanf(fp, "%d %d", &rows, &cols);
        c++;
    } 
    char mappa[rows][cols];
    char ch;
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            fscanf(fp, "%c", &ch);
            if (ch == '\n' || ch == '\r') {
                k--; 
                continue;
            }
            mappa[i][k] = ch;
        }
    }

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); // hide cursor
    timeout(60);
    mvprintw(0, 0, "Debug: Righe: %d, Colonne: %d", rows, cols);
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            mvaddch(i+2, k, mappa[i][k]);
        }
    }
    refresh();
    getch();
    int cha;
    direction dir = UP;

    /*while((cha = getch()) != 'q'){
        clear();
        dir = getDirection(dir, cha);
        displayElements(rows, cols, mappa, pac);
        updatePosition(rows, cols, mappa, pac, dir);
        refresh();
    }*/

    endwin();
    free(pac);
    return 0;
}

