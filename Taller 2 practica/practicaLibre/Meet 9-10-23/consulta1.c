#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int grado;
    double *coeficiente;

} polinomio;

int main()
{
    // Ingreso el valor del grado
    polinomio p1;
    p1.grado = 3;
    p1.coeficiente = (double *)malloc(sizeof(double) * (p1.grado + 1));

    
}