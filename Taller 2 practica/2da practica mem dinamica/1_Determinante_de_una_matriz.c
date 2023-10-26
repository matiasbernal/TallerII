#include <stdio.h>
#include <stdlib.h>

int determinante_Matriz(int tam, int **matriz);

int main()
{
    int tam = 2; // tamano de la matriz

    // Reservar la memoria dinamica
    int **matriz = (int **)malloc(sizeof(int *) * tam);
    if (matriz == NULL)
    {
        printf("No se pudo reservar memoria");
        return EXIT_FAILURE;
    }

    // Recorro e inicializo cada una de las posiciones
    for (int i = 0; i < tam; i++)
    {
        *(matriz + i) = (int *)malloc(sizeof(int) * tam);
        if (matriz == NULL)
        {
            printf("No se pudo reservar memoria");
            return EXIT_FAILURE;
        }
    }

    // Pedir por teclado los valores

    int det = determinante_Matriz(tam, matriz);

    printf("El determinante es %d\n", det);

    // Libero la memoria que reserve cuando no la uso mas
    for (int i = 0; i < tam; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);

    return EXIT_SUCCESS;
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

        for (int x = 0; i < tam; x++)
        {
            det = matriz[i++][j++] +
        }
    }
}

/* Escribir un programa para calcular el determinante de una matriz:
-Solicite la dimensi ́on por teclado
-Solicite la memoria para el almacenamiento
-Ingrese por teclado los coeficientes con valores
-Desarrolle una funci ́on que realice el c ́alculo

-- int determinante_Matriz ( int tam , int ** matriz ) ;

-Mostrar por pantalla el resultado.
Recuerde que el determinante de la matriz es:

a11 a12
a21 a22
=> |A| = a11 × a22 − a12 × a21 (1)

o en caso de una matriz con mas elementos:
a11 a12 a13
a21 a22 a23
a31 a32 a33
= a11×a22×a33 + a12×a23×a31 + a13×a21×a32 − a31×a22×a13 − a32×a23×a11 − a33×a21×a12*/