
//----------4. Matriz transpuesta ---------------------
/*
Teclea el numero de renglones : 3
Teclea el numero de columnas : 4
MATRIZ ORIGINAL
1 4 5 7
2 4 1 5
7 6 4 9
MATRIZ TRANSPUESTA
1 2 7
4 4 6
5 1 4
7 5 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int filas, columnas = 0;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];
    int matriz_transpuesta[columnas][filas];
    int temp = 0;

    srand(time(NULL));

    // Ciclo para llenar la matriz
    printf("Matriz: \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int temp = rand() % 10 + 1;
            matriz[i][j] = temp;
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Ciclo para imprimir la matriz transpuesta
    printf("Matriz transpuesta: \n");
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            temp = matriz[i][j];
            matriz_transpuesta[j][i] = temp;
            printf("%3d ", matriz_transpuesta[j][i]);
        }
        printf("\n");
    }
}
