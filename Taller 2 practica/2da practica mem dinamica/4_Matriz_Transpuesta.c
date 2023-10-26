#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprimirMatriz(int fil, int col, int **matriz);
void imprimirMatrizTranspuesta(int fil, int col, int **matriz);

int main()
{
    // Defino variables
    int fil, col;

    int **matriz;
    srand(time(NULL));

    // Pedir tamano de matriz y el numero escalar para multiplicar
    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &fil);
    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &col);

    // Reservar memoria dinamica para las filas de la matriz
    matriz = (int **)malloc(sizeof(int *) * fil); // Primero reservar memoria para las filas
    if (matriz == NULL)
    {
        printf("Error al reservar memoria de las filas");
        return 1;
    }

    // Reservar memoria dinamica para las columnas de la matriz
    for (int i = 0; i < fil; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * col); // Segundo reservar memoria para las columnas

        if (matriz[i] == NULL)
        {
            printf("Error al reservar memoria de las columnas");
            return 1;
        }

        for (int j = 0; j < col; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    printf("Matriz: \n");
    imprimirMatriz(fil, col, matriz);

    printf("Matriz transpuesta: \n");
    imprimirMatrizTranspuesta(fil, col, matriz);

    // Liberar memoria al terminar
    for (int i = 0; i < fil; i++)
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}

void imprimirMatriz(int fil, int col, int **matriz)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void imprimirMatrizTranspuesta(int fil, int col, int **matriz)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < fil; j++)
        {
            printf("%2d ", matriz[j][i]);
        }
        printf("\n");
    }
}
