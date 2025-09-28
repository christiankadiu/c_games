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
    p->x = 23;
    p->y = 6;
    return p;
}

int main(){
    pacman* pac = init();
    int cols;
    int rows;
    FILE* fp = fopen("mappa2.txt", "r");

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
        
            // Se il carattere è un newline o un ritorno a capo,
            // lo scartiamo e leggiamo il carattere successivo
            if (ch_int == '\n' || ch_int == '\r') {
                k--; // Ritorna indietro di una posizione per riempire la cella corrente
                continue; // Passa all'iterazione successiva
            }
        
            // Assegna il carattere letto alla matrice
            mappa[i][k] = (char)ch_int;
        }
    }
    fclose(fp); // Chiudi il file appena hai finito di leggerlo

    // Inizializzazione di ncurses
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); 
    timeout(60);

    // Usa SOLO funzioni ncurses per stampare.
    mvprintw(0, 0, "Debug: Righe: %d, Colonne: %d", rows, cols);
    
    // Stampa la mappa sullo schermo ncurses
    /*for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            mvaddch(i + 2, k, mappa[i][k]); // Sposta la mappa verso il basso di 2 righe per non sovrapporsi al debug
        }
    }*/


    char ch;
    direction dir = STOP;
    while(1){
        clear();
        displayElements(rows, cols, mappa, pac);
        dir = getDirection(dir);
        updatePosition(rows, cols, mappa, pac, dir);
        refresh();
    }

    endwin();
    free(pac);
    return 0;
}
