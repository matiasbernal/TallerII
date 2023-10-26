/*1) Realice un programa en C que permita leer una cadena de caracteres y que
devuelva el número de caracteres que tiene dicha cadena e imprimir dicha cadena al
revés.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra[100];

    printf("Introduce una palabra u oracion: ");
    fgets(palabra, sizeof(palabra), stdin); // lee una linea de texto

    int letras = strlen(palabra); // Cuenta la cantidad de letras
    printf("numero de caracteres: %d \n", letras);

    printf("Palabra al reves: ");
    // Ciclo para invertir los caracteres
    for (int i = letras; i > 0; i--)
    {
        printf("%c", palabra[i - 1]); // Imprime los caracteres invertidos
    }

    return 0;
}