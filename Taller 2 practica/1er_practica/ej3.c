
//---------3. Suma de matrices: Programa que realiza la suma de dos matrices de N x N.
/*Teclea el tamano de la matriz : 4
Contenido de las matrices
Matriz 1
1 2 1 3
1 4 5 6
6 2 1 6
7 4 3 1
Matriz 2
2 3 2 5
5 4 2 1
8 7 6 9
9 5 4 1
Suma
3 5 3 8
6 8 8 7
14 9 7 15
16 9 7 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int suma_matrices(int matriz1[][N], int matriz2[][N]);

int main()
{
    int matriz1[N][N];
    int matriz2[N][N];
    int temp = 0;
    srand(time(NULL));

    // ciclo para llenar t mostrar la matriz 1
    printf("Matriz 1: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = rand() % 10 + 1;
            matriz1[i][j] = temp;
            printf("%3d ", matriz1[i][j]);
        }
        printf("\n");
    }

    // Ciclo para llenar y mostrar la matriz 2
    printf("Matriz 2: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = rand() % 10 + 1;
            matriz2[i][j] = temp;
            printf("%3d ", matriz2[i][j]);
        }
        printf("\n");
    }

    suma_matrices(matriz1, matriz2);

    return 0;
}

int suma_matrices(int matriz1[][N], int matriz2[][N])
{
    printf("Suma: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }
}