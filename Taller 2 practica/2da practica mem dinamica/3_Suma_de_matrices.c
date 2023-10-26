#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **sumaMatriz(int n, int **matriz1, int **matriz2);
void imprimirMatriz(int n, int **matriz);

int main()
{
    // Defino variables
    int n;
    int **matriz1, **matriz2, **matriz_suma;
    srand(time(NULL));

    // Pedir tamano de matriz y el numero escalar para multiplicar
    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &n);

    printf("\n");

    // Reservar memoria dinamica MATRIZ 1
    matriz1 = (int **)malloc(sizeof(int *) * n); // Primero, reservar memoria para las filas
    if (matriz1 == NULL)
    {
        printf("Error al reservar memoria");
        return 1;
    }

    // Rellenar matriz
    for (int i = 0; i < n; i++)
    {
        matriz1[i] = (int *)malloc(sizeof(int) * n); // Segundo, reservar memoria para las columnas

        if (matriz1[i] == NULL)
        {
            printf("Error al reservar memoria de las columnas");
            return 1;
        }
        
        for (int j = 0; j < n; j++)
        {
            matriz1[i][j] = rand() % 50;
        }
    }

    printf("Matriz 1: \n");
    imprimirMatriz(n, matriz1);

    // Reservar memorai matriz 2
    matriz2 = (int **)malloc(sizeof(int *) * n); // Primero reservar memoria para las filas
    if (matriz2 == NULL)
    {
        printf("Error al reservar memoria de las filas");
        return 1;
    }

    // Reservar memoria dinamica para las columnas de la matriz e imprimir matriz
    for (int i = 0; i < n; i++)
    {
        matriz2[i] = (int *)malloc(sizeof(int) * n); // Segundo reservar memoria para las columnas

        if (matriz2[i] == NULL)
        {
            printf("Error al reservar memoria de las columnas");
            return 1;
        }
        for (int j = 0; j < n; j++)
        {
            matriz2[i][j] = rand() % 50;
        }
    }
    
    printf("Matriz 2: \n");
    imprimirMatriz(n, matriz2);


    matriz_suma = sumaMatriz(n, matriz1, matriz2);

    // Imprimir la nueva matriz
    printf("Matriz Suma: \n");
    imprimirMatriz(n, matriz_suma);

    // Liberar memoria
    for (int i = 0; i < n; i++)
    {
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz_suma[i]);
    }
    free(matriz1);
    free(matriz2);
    free(matriz_suma);

    

    return 0;
}

int **sumaMatriz(int n, int **matriz1, int **matriz2)
{
    int **matriz_suma = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matriz_suma[i] = (int *)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++)
        {
            matriz_suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matriz_suma;
}

void imprimirMatriz(int n, int **matriz)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
