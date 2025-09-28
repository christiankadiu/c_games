#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

#define MURO '#'
#define PAC 'P'


// Questa funzione è corretta, controlla i limiti della mappa
bool isOkay(pacman* p, int rows, int cols) {
    return (p->x >= 0 && p->x < cols) && (p->y >= 0 && p->y < rows);
}

// Questa è la versione corretta e sicura della funzione
void updatePosition(int rows, int cols, char matrice[rows][cols], pacman* p, direction d) {
    // Usa una variabile locale per calcolare la prossima posizione
    // Questa è molto più veloce ed evita l'uso di malloc.
    pacman next_pos;
    next_pos.x = p->x;
    next_pos.y = p->y;

    // Calcola la prossima posizione in base alla direzione
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

    // Controlla se la prossima posizione è valida e non è un muro
    // Usa l'ordine corretto: matrice[riga][colonna] -> matrice[y][x]
    if (isOkay(&next_pos, rows, cols) && matrice[next_pos.y][next_pos.x] != MURO) {
        // Se la mossa è valida, aggiorna la posizione del Pacman originale
        p->x = next_pos.x;
        p->y = next_pos.y;
    }
}


