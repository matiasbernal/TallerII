// Calcular la probabilidades de que salgan cada uno de los numeros de un dado con un vector usando punteros.
// Calcular con 1000 iteraciones.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void sorteo(int *);
void leer(int *);

int main()
{
    int dado[6] = {0, 0, 0, 0, 0, 0};

    sorteo(dado);
    leer(dado);

    return 0;
}

void sorteo(int *a)
{
    srand(time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        int dado = rand() % 6 + 1; // numero aleatorio entre 1 y 6

        switch (dado)
        {
        case 1:
            *(a + dado - 1) += 1;
            break;
        case 2:
            *(a + dado - 1) += 1;
            break;
        case 3:
            *(a + dado - 1) += 1;
            break;
        case 4:
            *(a + dado - 1) += 1;
            break;
        case 5:
            *(a + dado - 1) += 1;
            break;
        case 6:
            *(a + dado - 1) += 1;
            break;
        }
    }
}

void leer(int *a)
{

    float aux;
    for (int i = 0; i < 6; i++)
    {
        aux = (*(a + 1) * 100.0) / MAX; // agrego .0 para obtener un resultado con decimales
        printf("Probabilidad de que salga el numero %d: %f%%\n", i + 1, aux);
    }
}