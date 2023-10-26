#include <stdio.h>
#include <stdlib.h>

int determinante_Matriz(int tam, int **matriz);

int main()
{
    int tam;
    printf("Ingrese la dimensión de la matriz: ");
    scanf("%d", &tam);

    // Reserva de memoria para la matriz
    int **matriz = (int **)malloc(tam * sizeof(int *));
    for (int i = 0; i < tam; i++)
    {
        matriz[i] = (int *)malloc(tam * sizeof(int));
    }

    // Ingreso de coeficientes
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcula el determinante
    int determinante = determinante_Matriz(tam, matriz);

    // Muestra el resultado
    printf("El determinante de la matriz es: %d\n", determinante);

    // Liberar memoria
    for (int i = 0; i < tam; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int determinante_Matriz(int tam, int **matriz)
{
    if (tam == 2)
    {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }
    else
    {
        int det = 0;
        for (int i = 0; i < tam; i++)
        {
            int **submatriz = (int **)malloc((tam - 1) * sizeof(int *));
            for (int j = 0; j < tam - 1; j++)
            {
                submatriz[j] = (int *)malloc((tam - 1) * sizeof(int));
            }
            for (int j = 1; j < tam; j++)
            {
                int k_new = 0;
                for (int k = 0; k < tam; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    submatriz[j - 1][k_new] = matriz[j][k];
                    k_new++;
                }
            }
            int sign = (i % 2 == 0) ? 1 : -1;
            det += sign * matriz[0][i] * determinante_Matriz(tam - 1, submatriz);
            for (int j = 0; j < tam - 1; j++)
            {
                free(submatriz[j]);
            }
            free(submatriz);
        }
        return det;
    }
}
