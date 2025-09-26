#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct pacman{
    int x;
    int y;
} pacman;

typedef enum dir{
    UP,
    DOWN,
    LEFT,
    RIGHT
}dir;

pacman* init(){
    pacman* pac = (pacman*)malloc(sizeof(pacman));
    pac->x = 21;
    pac->y = 22;
    return pac;
}

dir getDirection(){
    char d;
    dir di;
    scanf("%c", &d);
    if (d == 'w'){
        di = UP;
    }else if(d == 's'){
        di = DOWN;
    }else if(d == 'a'){
        di = LEFT;
    }else{
        di = RIGHT;
    }
    return di;
}

void updatePosition(pacman* p, dir d){
    switch(d){
        case 0: p->y -= 1; break;
        case 1: p->y += 1; break;
        case 2: p->x -= 1; break;
        case 3: p->x += 1; break;
    }
}

int main(){
    pacman* pac = init();
    dir direction = LEFT;
    FILE* fp = fopen("mappa.txt", "r");

    if(fp == NULL){
        printf("errore di apertura del file");
        return 1;
    }

    int rows;
    int cols;
    int c = 0;
    while (c <= 0){
        fscanf(fp, "%d %d", &rows, &cols);
        c++;
    } 
    char mappa[rows][cols];
    printf("le righe sono: %d\t", rows);
    printf("le colonne sono: %d\n", cols);
    char ch;
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            fscanf(fp, " %c", &ch);
            mappa[i][k] = ch;
        }
    }   
    for (int i = 0; i < rows; i++){
        for (int k = 0; k < cols; k++){
            printf("%c", mappa[i][k]);
        }
        printf("\n");
    }

    while(1){
        direction = getDirection();
        updatePosition(pac, direction);
        sleep(1000);
    }
}
