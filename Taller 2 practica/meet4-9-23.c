#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct pos
{
    int latitud;
    int longitud;

} pos;

struct alumno
{
    char nombre[20];
    int notas[10];
} a3;

int main()
{
    strcpy(a3.nombre, "Luciano");
    a3.notas[0] = 8;

    struct alumno a1; // objeto del tipo struct alumno
    // struct alumno a2; //objeto del tipo struct alumno

    strcpy(a1.nombre, "Martina");
    a1.notas[0] = 8;
    a1.notas[1] = 6;

    printf("%s: %d, %d\n", a1.nombre, a1.notas[0], a1.notas[1]);
    printf("%s: %d\n", a3.nombre, a3.notas[0]);
    return 0;
}