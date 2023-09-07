#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------- 1.Escriba un programa que genere la matriz identidad de tama ̃no N x N.------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

// Programa para imprimir una matriz identidad NxN
int main()
{
    int matriz[N][N];
    int valor = 0;
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            valor = rand() % 100 + 1;
            matriz[i][j] = valor;
        }
    }

    // Imprimir matriz
    printf("Matriz:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}
