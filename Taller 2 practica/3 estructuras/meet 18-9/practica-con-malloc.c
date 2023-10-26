// Matrices bidimensionales
// Dibujar donde esta el stack, el heap, para poder ubicarme mejor para entender el codigo y lo que pasa
// Liberar memoria

#include <stdio.h>
#include <stdlib.h>

void ordenarVector(float *, int);

int main()
{
    // No puedo desreferenciar algo que no esta inicializado, esto cuando hablamos de puntero, da error "segmentation fault"
    // Siempre debo iniciar un puntero antes de iniciarlo
    // Siempre que lo quiera usar debo desreferenciarlo y para eso debe estar inicializado

    float *numeros = NULL;
    int cant_numeros = 0;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &cant_numeros);

    numeros = (float *)malloc(sizeof(float) * cant_numeros);

    // Imprimir si se reservo o no memoria
    if (numeros == NULL)
    {
        printf("No se pudo reservar memoria\n");
        return 1;
    }
    else
    {
        printf("Se reservo memoria correctamente\n");
    }

    // Ciclo para ingresar los numeros
    for (int i = 0; i < cant_numeros; i++)
    {
        float numero_ingresado = 0;
        printf("Ingrese un numero: ");
        scanf("%f", &numero_ingresado);
        *(numeros + i) = numero_ingresado;
    }

    ordenarVector(numeros, cant_numeros);

    for (int i = 0; i < cant_numeros; i++)
    {
        printf("Numero %d: %.2f\n", i + 1, *(numeros + i));
    }

    return 0;
}
// Ordenamiento burbuja 0 bubble sort
void ordenarVector(float *vector, int cant_elementos)
{
    int ordenado;
    do
    {
        ordenado = 1;
        for (int i = 0; i < cant_elementos - 1; i++) // cant_elementos-1 porque si no se desborda el vector
        {
            if (*(vector + i) > *(vector + i + 1))
            {
                ordenado = 0;
                float aux = *(vector + i);
                *(vector + i) = *(vector + i + 1);
                *(vector + i + 1) = aux;
            }
        }

    } while (ordenado == 0);
}