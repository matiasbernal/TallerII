/*1) Realice un programa en C que permita leer una cadena de caracteres y que
devuelva el número de caracteres que tiene dicha cadena e imprimir dicha cadena al
revés.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra[100];

    fgets(palabra, sizeof(palabra), stdin); // lee una linea de texto

    printf("numero de caracteres: %d \n", strlen(palabra));

    printf("Palabra al reves: ");
    for (int i = strlen(palabra) - 1; i >= 0; i--)
    {
        printf("%c", palabra[i]);
    }

    return 0;
}