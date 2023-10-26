/*
Dado los siguientes prototipos, hacer un programa en que se pida una frase y una letra.
1. La funcion cantidad retornara el numero de veces que se encuentra la letra en la frase.
2. La funcion ocurrencias retornar ́a las posiciones en las que se encuentran dicha letra en la frase.

OBS: No debe usar las funciones de string.h para el parseo de la cadena.

typedef struct char_string {
char c ;
char ∗ cadena ;
} char_string ;

int cantidad (char_string *frase)
int *ocurrencias(char_string *frase, int cantidad)
*/

#include <stdio.h>
#include <stdint.h>

typedef struct char_string
{
    char c;
    char *cadena;
} char_string;

int cantidad(char_string *frase);
int *ocurrencias(char_string *frase, int cantidad);

int main()
{
    char_string primer_frase;
    char frase[100];

    // Introducir la frase
    printf("Introduzca una frase: ");
    fgets(frase, sizeof(frase), stdin);

    primer_frase.cadena = frase; // Ubicar la frase en la struct

    // Introducir el caracter
    printf("Introduzca un caracter: ");
    scanf("%c", &primer_frase.c);

    printf("Frase: %s\nCaracter: %c\n", primer_frase.cadena, primer_frase.c);

    // Llamar a la funcion cantidad
    int letra_repetida = cantidad(&primer_frase);

    printf("La letra \"%c\" aparece un numero de veces igual a: %d\n", primer_frase.c, letra_repetida);

    // Llamar a la funcion ocurrencias
    int *letra_posicion = ocurrencias(&primer_frase, letra_repetida);

    // Ciclo para imprimir las ocurrencias
    for (int i = 0; i < letra_repetida; i++)
    {
        printf("Ocurrencia %d en la posicion %d\n", i + 1, *(letra_posicion + i));
    }
    return 0;
}

int cantidad(char_string *frase)
{
    int letra = 0;

    for (int i = 0; frase->cadena[i] != '\0'; i++)
    {
        if (frase->cadena[i] == frase->c)
        {
            letra++;
        }
    }

    return letra;
}

int *ocurrencias(char_string *frase, int cantidad)
{
    int *posicion = (int *)malloc(sizeof(int) * cantidad);
    int contador = 0;

    for (int i = 0; frase->cadena[i] != '\0'; i++)
    {

        if (frase->cadena[i] == frase->c)
        {
            *(posicion + contador) = i + 1;
            contador++;
        }
    }

    return posicion;
}
