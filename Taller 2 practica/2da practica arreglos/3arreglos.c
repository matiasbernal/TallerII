#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void testBuscaCaracter(); // Prototipo de la funcion
void buscaCaracter(char[], char); // Prototipo de la funcion

int main()
{
    testBuscaCaracter(); 
    return 0;
}

void testBuscaCaracter()
{
    char palabra[100];
    char caracter;

    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin); // Lee una linea de texto

    printf("Ingrese un caracter: ");
    caracter = getchar(); // Lee un caracter

    buscaCaracter(palabra, caracter);
}

void buscaCaracter(char palabra[100], char caracter)
{
    int posicion = 0;
// Ciclo para recorrer la palabra
    for (int i = 0; i < strlen(palabra); i++)
    {
        // Si el caracter en la posicion i es igual al caracter ingresado
        if (palabra[i] == caracter)
        {
            posicion = i + 1; // Se guarda la posicion
            printf(" El primer lugar donde aparece el caracter \"%c\" es en la posicion %d \n", caracter, posicion);
            break;
        }
    }
    if (posicion == 0) // Si la posicion es 0, el caracter no se encuentra en la palabra
    {
        printf("El caracter %c no se encuentra en la cadena de caracteres ingresados \n", caracter);
    }
}

/*
a) La función void main(void) que invocará a una función void
testBuscaCaracter();

b) testBuscaCaracter(), pedirá por teclado una cadena de caracteres y un
carácter (se aconseja utilizar las funciones gets(cad) para pedir la cadena y
c=getchar() para pedir el carácter, ya que scanf (...) no sabe reconocer un
carácter que se teclee después de cualquier otro valor -asume como dato
introducido para el carácter el blanco o el retorno de carro con el que se
separaría el valor introducido anterior al carácter-). Invocará a la función del
siguiente apartado c) y visualizará un texto que indique si el carácter estaba o
no en la cadena y, en su caso, la primera posición donde aparece, teniendo
en cuenta que si aparece en la primera posición debe visualizar un 1.

c) Implemente la función int buscaCaracter (Cadena, char); que recorra la
cadena comparando cada elemento con el carácter y devuelva un valor
apropiado. Por si le ayuda para la resolución, una posición nunca puede ser
negativa
*/