#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void testEsPalindromo();
int esPalindromo(char[]);

int main()
{
    testEsPalindromo();
    return 0;
}

void testEsPalindromo()
{
    char palabra[100];

    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin); // lee una linea de texto

    printf("La palabra \"%s\"", palabra); // Imprime la palabra

    // Si es palindromo, imprime "es palindromo", sino, imprime "no es palindromo"
    if (esPalindromo(palabra) == 1)
    {
        printf("es palindromo", palabra); //
    }
    else
    {
        printf("no es palindromo", palabra);
    }
}

int esPalindromo(char palabra[100])
{
    int i = 0;
    int j = (strlen(palabra) - 2);
    int esPalindromo = 1;

    // Ciclo para recorrer la palabra y convertir a minusculas
    for (int i = 0; i < strlen(palabra); i++)
    {
        palabra[i] = tolower(palabra[i]);
    }

    // Ciclo para recorrer la palabra
    while (i < j)

    {
        // Verifica si la letra en la posicion i es diferente a la letra en la posicion j
        if (palabra[i] != palabra[j])
        {
            esPalindromo = 0; // no es palindromo
            break;
        }
        i++;
        j--;
    }

    return esPalindromo; // Retorna 1 si es palindromo, 0 si no lo es
}
#include<stdio.h>
int main(void)
{
    char cadenal[10];
, cadenal);
printf("%s", cadenal);
char *cadena2 = " Hola";
printf("%s" * cadena2);
return 0;
}