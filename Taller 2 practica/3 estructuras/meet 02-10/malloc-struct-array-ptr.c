#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char calle[25];
    int numero;
    char nombre[30];
} direccion;

int main()
{
    direccion *pdir, *pdiri = NULL;
    pdir = pdiri = (direccion *)malloc(1000 * sizeof(direccion));

    printf("\n");

    strcpy(pdir->calle, "Avd. Alemania");
    pdir->numero = 2010;
    strcpy(pdir->nombre, "Fulano");
    printf("La direccion de %s es: %s %d.\n", pdir->nombre, pdir->calle, pdir->numero);

    pdiri++; /* pasa a la siguiente estructura */

    strcpy(pdiri->calle, "Av. Pellegrini");
    pdiri->numero = 250;
    strcpy(pdiri->nombre, "Ingenieria");
    printf("La direccion de %s es: %s %d.\n", pdiri->nombre, pdiri->calle, pdiri->numero);

    pdiri++; /* pasa a la siguiente estructura */

    strcpy(pdiri->calle, "Olive");
    pdiri->numero = 20;
    strcpy(pdiri->nombre, "Augusto");
    printf("La direccion de %s es: %s %d.\n", pdiri->nombre, pdiri->calle, pdiri->numero);

    free(pdir);

    return 0;
}