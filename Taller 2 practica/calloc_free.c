// Realizar un vector con 100 elementos aleatorios comprendidos entre 0 y 2 y contar con un vector dinamico cuantas veces aparece cada numero

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void aleatorio(int *, int);

int main()
{
    int vector[100]; // Lo hacemos estatico, ya que no pide ningun requisito extra ni impedimento
    int N = 3;
    int *contador;

    contador = (int *)calloc(sizeof(int), N); // Usamos calloc para Asignar espacio de memoria y inicializarlo

    if (vector == NULL)
    {
        printf("No se pudo reservar la memoria correctamente");
    }
    else
    {
        printf("Vector: ");

        for (int i = 0; i < N; i++)
        {
            printf("%d ", *(contador + i));
        }

        aleatorio(vector, 100);
        printf("\n");

        // Ciclo para contar cuantas veces aparecen los numeros, usando punteros
        for (int i = 0; i < 100; i++)
        {
            if (*(vector + i) == 0) // Suma 1 si aparece el cero
            {
                *(contador + 0) += 1;
            }
            else if (*(vector + i) == 1) // Suma 1 si aparece el uno
            {
                *(contador + 1) += 1;
            }
            else if (*(vector + i) == 2) // Suma 1 si aparece el dos
            {
                *(contador + 2) += 1;
            }
        }
        printf("El numero 0 aparece: %d veces\nEl numero 1 aparece: %d veces\nEl numero 2 aparece: %d veces\n", *(contador + 0), *(contador + 1), *(contador + 2));
    }
    return 0;
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