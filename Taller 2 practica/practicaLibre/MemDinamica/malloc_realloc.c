// Realizar un vector dinamico de 10 elementos aleatorios comprendidos entre 0 y 2 y eliminar todos los mumeros repetidos reajustando el vector.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void aleatorio(int *, int);

int main()
{
    int *vector;
    int i, j, k;
    int N = 10;

    vector = (int *)malloc(sizeof(int) * N); // Asignar el tamano al vector

    if (vector == NULL)
    {
        printf("No se pudo reservar memoria\n");
        return 1;
    }
    else
    {

        aleatorio(vector, N);
        printf("\n");

        // Ciclo para eliminar los numeros
        for (i = 0; i < N; i++)
        {
            j = i + 1;

            while (j < N)
            {
                if (*(vector + i) == *(vector + j))
                {
                    for (k = j; k + 1 < N; k++)
                    {
                        *(vector + k) = *(vector + k + 1);
                    }
                    N--;
                }
                else
                {
                    j++;
                }
            }
        }
        vector = (int *)realloc(vector, N * sizeof(int)); // Redimensiona el vector conservando sus valores
        if (vector == NULL)
        {
            printf("No se pudo reservar memoria\n");
        }
        else
        {
            for (i = 0; i < N; i++)
            {
                printf("%d ", *(vector + i));
            }
            printf("\n");
        }

        return 0;
    }
}
void aleatorio(int *a, int b)
{
    srand(time(NULL));

    for (int i = 0; i < b; i++)
    {
        *(a + i) = rand() % 3; // Numero aleatorio entre 0 y 3
        printf("%d ", *(a + i));
    }
}