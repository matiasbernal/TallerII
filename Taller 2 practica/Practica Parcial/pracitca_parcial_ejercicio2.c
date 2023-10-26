/*
2) 
Definir la función expandir con el siguiente prototipo:

int **expandir(int **matriz, int filas, int cols);

que dada una matriz, la cantidad de filas y columnas de la misma, construya
otra matriz con una fila más y una columna más, completando los valores
nuevos de la matríz con 0. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_FILAS 2
#define MIN_COLUMNAS 2

int** expandir_matriz(int, int, int**);

int main(void){
    int filas, columnas;
    do{
        printf("Filas: ");
        scanf("%d", &filas);
    }while(filas<MIN_FILAS);
    do{
        printf("Columnas: ");
        scanf("%d", &columnas);
    }while(filas<MIN_COLUMNAS);
    int** matriz_original;
    matriz_original = (int**)malloc(sizeof(int*)*filas);
    for(int i=0; i<filas; i++){
        matriz_original[i] = (int*)malloc(sizeof(int)*columnas);
    }
    srand(time(NULL));
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            matriz_original[i][j] = rand()%9+1;
        }
    }
    printf("Matriz original:\n");
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            printf("[ %d ]", matriz_original[i][j]);
        }
        printf("\n");
    }
    int** matriz_expandida;
    matriz_expandida = expandir_matriz(filas, columnas, matriz_original);
    printf("Matriz expandida:\n");
    for(int i=0; i<(filas+1); i++){
        for(int j=0; j<(columnas+1); j++){
            printf("[ %d ]", matriz_expandida[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int** expandir_matriz(int filas, int columnas, int** matriz_original){
    int** matriz_nueva;
    matriz_nueva = (int**)malloc(sizeof(int)*(filas+1));
    for(int i=0; i<(filas+1); i++){
        matriz_nueva[i] = (int*)malloc(sizeof(int)*(columnas+1));
    }
    for(int i=0; i<(filas+1); i++){
        for(int j=0; j<(columnas+1); j++){
            if(i<filas && j<columnas){
                matriz_nueva[i][j] = matriz_original[i][j];
            }else{
                matriz_nueva[i][j] = 0;
            }
        }
    }
    return matriz_nueva;
}