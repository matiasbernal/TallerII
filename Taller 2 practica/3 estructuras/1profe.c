#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tiempo
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct
{
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

int compara_tiempos(Tiempo *t1, Tiempo *t2);
void imprime_tiempo(Tiempo t);

void ordena_alfa(Archivo *lista, int n);
void ordena_temporal(Archivo *lista, int n);

int main()
{
    int n = 10;

    Archivo lista[n] = {0}; // Asi reservaria memoria estatica
    // Archivo *lista = (Archivo *)malloc(sizeof(Archivo) * n); // Asi reservaria memoria dinamica

    for (int i = 0; i < n; i++)
    {
        char *nombre = (char *)malloc(sizeof(char) * 10); // Reservar memoria dinamica para nombre
        fgets(nombre, 10, stdin); // Ingresar el nombre por teclado

        strcpy(lista[i].nombre, nombre); // Si tengo un objeto accedo con el punto a la estructura
                                          // lista[i]-> Si tengo un puntero accedo con una flecha a la estructura
        lista[i].ultima_mod = {2022, 9, 25, 21, 27, 10};
    }

    return 0;
}