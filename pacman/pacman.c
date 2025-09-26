#include <stdio.h>

int main(){
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
}
