


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenarVector(int *, int);

int main()
{
    int N = 0;
    int aux = 0;
    srand(time(NULL));  // semilla para generar numeros aleatorios
    int *vector = NULL; // vector de enteros

    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &N);

    vector = (int *)malloc(sizeof(int) * N); // reservo memoria para el vector

    if (vector == NULL)
    {
        printf("No se pudo reservar memoria\n");
    }
    else
    {
        printf("Se reservo memoria correctamente\n");
    }

    for (int i = 0; i < N; i++)
    {
        aux = rand() % 100; // genera un numero aleatorio entre 0 y 99
        *(vector + i) = aux;
    }

    printf("Vector desordenado: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(vector + i)); // vector[i] == *(vector + i)
    }

    ordenarVector(vector, N);

    printf("\nVector ordenado: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(vector + i)); // desreferencio el puntero para acceder al valor
    }
}

void ordenarVector(int *a, int b)
{
    int ordenado = 0;
    do
    {
        ordenado = 1;
        for (int i = 0; i < b - 1; i++) // b-1 porque si no se desborda el vector
        {
            if (*(a + i) > *(a + i + 1))
            {
                ordenado = 0;
                int aux = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = aux;
            }
        }
    } while (ordenado == 0);
}