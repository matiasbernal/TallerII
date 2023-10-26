#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **producto_escalar_Matriz(int fil, int col, int esc, int **matriz);
void imprimirMatriz(int fil, int col, int **matriz);

int main()
{
    // Defino variables
    int esc, fil, col, factor;
    int **matriz, **matriz_esc = NULL;
    srand(time(NULL));

    // Pedir tamano de matriz y el numero escalar para multiplicar
    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &fil);
    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &col);
    do
    {
        printf("Ingrese el numero por el que quiera multiplicar la matriz: ");
        factor = scanf("%d", &esc);
    } while (factor != 1);

    printf("\n");

    // Reservar memoria dinamica para las filas de la matriz
    matriz = (int **)malloc(sizeof(int *) * fil); // Primero reservar memoria para las filas
    if (matriz == NULL)
    {
        printf("Error al reservar memoria de las filas");
        return 1;
    }

    printf("Matriz: \n");

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
            matriz[i][j] = rand() % 50;
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    matriz_esc = producto_escalar_Matriz(fil, col, esc, matriz);

    // Imprimir la nueva matriz
    printf("Matriz multiplicada por %d: \n", esc);
    imprimirMatriz(fil, col, matriz_esc);

    // Liberar memoria al terminar
    for (int i = 0; i < fil; i++)
    {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}

int **producto_escalar_Matriz(int fil, int col, int esc, int **matriz)
{
    int **matriz_esc = (int **)malloc(sizeof(int) * fil));

    for (int i = 0; i < fil; i++)
    {
        matriz_esc = (int *)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++)
        {
            matriz_esc[i][j] = matriz[i][j] * esc;
        }
    }
    return matriz_esc;
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
