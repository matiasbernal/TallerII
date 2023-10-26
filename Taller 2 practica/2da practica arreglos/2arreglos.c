#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cambiar_mayus_minus(char[]);

int main()
{
    char palabra[100];

    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin); // lee una linea de texto

    printf("\n");

    printf("Palabra modificada: ");
    cambiar_mayus_minus(palabra);

    return 0;
}

void cambiar_mayus_minus(char palabra[100])
{
    {

        for (int i = 0; i < strlen(palabra); i++)
        {
            if (islower(palabra[i]))
            {
                palabra[i] = toupper(palabra[i]);
            }
            else if (isupper(palabra[i]))
            {
                palabra[i] = tolower(palabra[i]);
            }

            printf("%c", palabra[i]);
        }
    }
}

/*Realice un programa en C programa que lea un texto cualquiera y lo imprima
transformando las mayúsculas en minúsculas y viceversa.*/