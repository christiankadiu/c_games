#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "out.h"
#include "logic.h"
#include <stdbool.h>
#include <time.h>

#define MURO '#'
#define PUNTO '.'
pacman* init(){
    pacman* p = (pacman*)malloc(sizeof(pacman));
    p->x = 5;
    p->y = 23;
    return p;
}

int main(){
    srand(time(NULL));
    pacman* pac = init();
    ghost* fantasmi = NULL;
    int cols;
    int rows;
    FILE* fp = fopen("mappa.txt", "r");

    if(fp == NULL){
        printf("errore di apertura del file\n");
        return 1;
    }

    // Lettura delle dimensioni
    fscanf(fp, "%d %d", &rows, &cols);
    fgetc(fp);
    // Lettura della mappa. Usa un whitespace in "%c" per ignorare i newline.
    char mappa[rows][cols];
    int ch_int;
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            ch_int = fgetc(fp);
        
            if (ch_int == '\n' || ch_int == '\r') {
                k--; 
                continue; 
            }
        
            mappa[i][k] = (char)ch_int;
            if (mappa[i][k] == 'G'){
                ghost* g = (ghost*)malloc(sizeof(ghost));
                g->x = k;
                g->y = i;
                g->next = fantasmi;
                g->prev = UP;
                fantasmi = g;
            }
        }
    }
    fclose(fp); 

    // Inizializzazione di ncurses
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); 
    timeout(60);
    
    mvprintw(0, 0, "Debug: Righe: %d, Colonne: %d", rows, cols);
    

    char ch;
    direction prev = UP;
    direction dir;
    while(1){
        clear();
        displayElements(rows, cols, mappa, pac);
        displayGhosts(fantasmi);
        dir = getDirection(prev);
        if (dir == STOP) break;

        if (!updatePacmanPosition(rows, cols, mappa, pac, dir)){
            updatePacmanPosition(rows, cols, mappa, pac, prev);
        }else{
            prev = dir;
        }
        updateGhostsPosition(rows, cols, mappa, fantasmi);
        if (checkCollisions(pac, fantasmi)){
            break;
        }
        refresh();
    }
    endwin();
    free(pac);
    return 0;
}
