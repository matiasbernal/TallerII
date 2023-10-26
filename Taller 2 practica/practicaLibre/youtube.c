#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Punto
{
    float x;
    float y;
};

struct Punto calcularPuntoMedio(struct Punto p, struct Punto q);

int main()
{
    struct Punto puntoInicio; // Creo puntoInicio para designar los valores de coordenadas de inicio

    puntoInicio.x = 1;
    puntoInicio.y = 1;

    struct Punto puntoFin; // Creo puntoFin para designar los valores de coordenadas de fin

    puntoFin.x = 5;
    puntoFin.y = 3;

    struct Punto puntoMedio = calcularPuntoMedio(puntoInicio, puntoFin); // creo puntoMedio para capturar el return de la funcion


    printf("Punto medio: (%.2f, %.2f)", puntoMedio.x, puntoMedio.y);
    return 0;
}

struct Punto calcularPuntoMedio(struct Punto p, struct Punto q)
{
    struct Punto m; // punto medio

    m.x = (p.x + q.x) / 2;
    m.y = (p.y + q.y) / 2;

    return m;
}