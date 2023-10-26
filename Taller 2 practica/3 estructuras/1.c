#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3

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
    Tiempo t1, t2, t3;

    t1.anio = 2022;
    t1.mes = 12; // Diciembre
    t1.dia = 31;
    t1.hora = 23;
    t1.minuto = 59;
    t1.segundo = 50;

    t2.anio = 2020;
    t2.mes = 3; // Enero
    t2.dia = 12;
    t2.hora = 16;
    t2.minuto = 44;
    t2.segundo = 32;

    t3.anio = 2019;
    t3.mes = 7; // Julio
    t3.dia = 10;
    t3.hora = 19;
    t3.minuto = 12;
    t3.segundo = 45;

    int resultado = compara_tiempos(&t1, &t2);

    if (resultado == 1)
    {
        printf("El tiempo 1 es menor que el tiempo 2\n");
    }
    else if (resultado == 0)
    {
        printf("El tiempo 1 es igual que el tiempo 2\n");
    }
    else
    {
        printf("El tiempo 1 es mayor que el tiempo 2\n");
    }

    printf("Tiempo 1: ");
    imprime_tiempo(t1);
    printf("Tiempo 2: ");
    imprime_tiempo(t2);

    Archivo lista[N];

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el dato %d: ", i + 1);
        char *nombre = (char *)malloc(sizeof(char) * 10);
        fgets(nombre, 10, stdin);

        lista[i].nombre = nombre;
        printf("Ingrese la ultiam fecha de modificacion en el formato YYYY/MM/DD HH:MM:SS: ");
        scanf("%d/%d/%d  %d:%d:%d\n", &(lista[i].ultima_mod.dia), &(lista[i].ultima_mod.mes), &(lista[i].ultima_mod.anio), &(lista[i].ultima_mod.hora), &(lista[i].ultima_mod.minuto), &(lista[i].ultima_mod.segundo));
        fflush(stdin); // Consume el caracter del enter en el bufer de entrada
    }
    /*
             lista[i].ultima_mod.anio = t1.anio;
             lista[i].ultima_mod.mes = t1.mes;
             lista[i].ultima_mod.dia = t1.dia;
             lista[i].ultima_mod.hora = t1.hora;
             lista[i].ultima_mod.minuto = t1.minuto;
             lista[i].ultima_mod.segundo = t1.segundo;
         }

             lista[1].nombre = "Meli";
             lista[1].ultima_mod.anio = t2.anio;
             lista[1].ultima_mod.mes = t2.mes;
             lista[1].ultima_mod.dia = t2.dia;
             lista[1].ultima_mod.hora = t2.hora;
             lista[1].ultima_mod.minuto = t2.minuto;
             lista[1].ultima_mod.segundo = t2.segundo;

             lista[2].nombre = "Sofi";
             lista[2].ultima_mod.anio = t3.anio;
             lista[2].ultima_mod.mes = t3.mes;
             lista[2].ultima_mod.dia = t3.dia;
             lista[2].ultima_mod.hora = t3.hora;
             lista[2].ultima_mod.minuto = t3.minuto;
             lista[2].ultima_mod.segundo = t3.segundo;
         */
    ordena_alfa(lista, 3);

    printf("\nlista despues de ordenar alfabeticamente:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", lista[i].nombre);
    }

    return 0;
}

int compara_tiempos(Tiempo *t1, Tiempo *t2)
{
    if (t1->anio < t2->anio)
    {
        return 1;
    }
    if (t1->anio > t2->anio)
    {
        return -1;
    }

    if (t1->mes < t2->mes)
    {
        return 1;
    }
    if (t1->mes > t2->mes)
    {
        return -1;
    }

    if (t1->dia < t2->dia)
    {
        return 1;
    }
    if (t1->dia > t2->dia)
    {
        return -1;
    }

    if (t1->hora < t2->hora)
    {
        return 1;
    }
    if (t1->hora > t2->hora)
    {
        return -1;
    }

    if (t1->minuto < t2->minuto)
    {
        return 1;
    }
    if (t1->minuto > t2->minuto)
    {
        return -1;
    }

    if (t1->segundo < t2->segundo)
    {
        return 1;
    }
    if (t1->segundo > t2->segundo)
    {
        return -1;
    }

    else
    {
        return 0;
    }
}
/*
Otra forma de usar menos lineas de codigo es poner todo en una linea, se puede obviar las {}
if (t1->anio < t2->anio) return 1;
    if (t1->anio > t2->anio) return -1;
    if (t1->mes < t2->mes) return 1;
    if (t1->mes > t2->mes) return -1;
    if (t1->dia < t2->dia) return 1;
    if (t1->dia > t2->dia) return -1;
    if (t1->hora < t2->hora) return 1;
    if (t1->hora > t2->hora) return -1;
    if (t1->minuto < t2->minuto) return 1;
    if (t1->minuto > t2->minuto) return -1;
    if (t1->segundo < t2->segundo) return 1;
    if (t1->segundo > t2->segundo) return -1;
    return 0;
    }
*/

void imprime_tiempo(Tiempo t)
{
    printf("%d/%d/%d %d:%d:%d\n", t.anio, t.mes, t.dia, t.hora, t.minuto, t.segundo);
}

void ordena_alfa(Archivo *lista, int n)
{
    Archivo temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((strcmp(lista[i].nombre, lista[j].nombre)) < 0)
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// void ordena_temporal(Archivo * lista, int n);
