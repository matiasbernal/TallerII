
// -------------6 Def sig variables-----------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i = 5;
    int j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pi;

    // Mostrar direccion de i
    printf("%p\n", &i);
    printf("%d\n", i);

    // Mostrar los mismos valores a traves del puntero *pi
    pi = &i;
    printf("%p \n", pi);
    printf("%d \n", *pi);

    // Recorrer vector j mostrando su direccion y valor para cada elemento
    for (int i = 0; i < 10; i++)
    {
        printf("Direccion: %p\t", &j[i]);
        printf("Valor: %d\n", j[i]);
    }

    printf("\n");

    // Recorrer el vector accediendo a traves del puntero *pi y usando algebra de punteros

    pi = &j;
    printf("Vector j: ");
    for (int i = 0; i < 10; i++)
    {

        printf(" %d ", *(pi + i));
    }

    printf("\n");

    // Repita lo mismo con las variables char, el array y el puntero
    char x = 'a', pal[] = "texto en c";
    char *pc;

    // Mostrar direccion de pal
    printf("%p\n", &pal);
    printf("%c\n", pal);

    // Mostrar los mismos valores a traves del puntero *pc
    pc = &x;
    printf("%p \n", pc);
    printf("%c \n", *pc);

    // Recorrer vector pal mostrando su direccion y valor para cada elemento
    for (int i = 0; i < 10; i++)
    {
        printf("Direccion: %p\t", &pal[i]);
        printf("Valor: %c\n", pal[i]);
    }

    printf("\n");

    // Recorrer el vector accediendo a traves del puntero *pc y usando algebra de punteros
    pc = &pal;
    printf("Vector pal: ");
    for (int i = 0; i < 10; i++)
    {

        printf(" %c ", *(pc + i));
    }
}
