#include <stdio.h>
#include <stdlib.h>

typedef struct charstring
{
    char c;
    char *cadena;
} charstring;

int cantidad(charstring *frase)
{
    int count = 0;
    char buscar = frase->c;
    char *cadena = frase->cadena;

    while (*cadena != '\0')
    {
        if (*cadena == buscar)
        {
            count++;
        }
        cadena++;
    }

    return count;
}

int *ocurrencias(charstring *frase, int cantidad)
{
    int *posiciones = (int *)malloc(sizeof(int) * cantidad);
    if (posiciones == NULL)
    {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    char buscar = frase->c;
    char *cadena = frase->cadena;
    int index = 0;
    int posicion = 0;

    while (*cadena != '\0')
    {
        if (*cadena == buscar)
        {
            posiciones[index++] = posicion;
        }
        cadena++;
        posicion++;
    }

    return posiciones;
}

int main()
{
    charstring frase;
    char buffer[100];

    printf("Ingrese una frase: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("Ingrese una letra: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &frase.c);

    frase.cadena = buffer;
    int count = cantidad(&frase);
    int *positions = ocurrencias(&frase, count);

    printf("La letra '%c' aparece %d veces en la frase.\n", frase.c, count);

    if (count > 0)
    {
        printf("Posiciones de la letra '%c' en la frase: ", frase.c);
        for (int i = 0; i < count; i++)
        {
            printf("%d", positions[i]);
            if (i < count - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
        free(positions);
    }

    return 0;
}
