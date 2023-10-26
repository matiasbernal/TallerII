#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int n;
    double *coeficiente;
} Polinomio;

Polinomio *creaPolinomio(int orden);                              // a) crea y retorna un nuevo polinomio
void setCoef(int n, double c, Polinomio *P);                      // b. /* asigna el n_ésimo coeficiente del Polinomio
double getCoef(int n, Polinomio *P);                              // c. /* retorna el n_ésimo coeficiente del Polinomio
double especializa(double x, Polinomio *P);                       // d. /* calcula el polinomio en x usando:
Polinomio *sum(Polinomio *p1, Polinomio *p2);                     // e. /* suma dos Polinomios retorna un nuevo Polinomio con el resultado
Polinomio *mult(Polinomio *p1, Polinomio *p2);                    // f. /* multiplica dos Polinomios y retorna un nuevo Polinomio con el resultado
Polinomio *deriv(Polinomio *p);                                   // g. /* deriva un Polinomio retornando un nuevo Polinomio con el resultado
void destruyePolinomio(Polinomio *p);                             // h. /* libera la memoria asociada con el polinomio
double ceropol(Polinomio *p, double a, double b, double epsilon); // i. /* busque por el método de bisección un cero de un polinomio dentro de un intervalo[a, b], con una precisión dada por épsilon y lo retorne

int main()
{
    int orden = 3; // Cambiar al orden deseado
    Polinomio *miPolinomio = creaPolinomio(orden);

    if (miPolinomio != NULL)
    {
        printf("Polinomio creado con exito\n");
        printf("Orden del Polinomio: %d\n", miPolinomio->n);

        // acceder y modificar los coeficientes si es necesario
        for (int i = 0; i <= orden; i++)
        {
            printf("Coeficiente %d: %lf\n", i, miPolinomio->coeficiente[i]);
        }

        // Liberar memoria cuando ya no se necesita
        free(miPolinomio->coeficiente);
        free(miPolinomio);
    }

    return 0;
}

Polinomio *creaPolinomio(int orden)
{
    Polinomio *nuevoPolinomio = (Polinomio *)malloc(sizeof(Polinomio));

    if (nuevoPolinomio == NULL)
    {
        printf("Error al asignar memoria\n");
    }

    // Establecer el orden del Polinomio
    nuevoPolinomio->n = orden;

    // Asignar memoria para el arreglo de coeficientes
    nuevoPolinomio->coeficiente = (double *)malloc(sizeof(double) * (orden + 1));

    if (nuevoPolinomio->coeficiente == NULL)
    {
        printf("Error al asignar memoria\n");
        free(nuevoPolinomio); // Liberar la memoria del Polinomia si la asignacion de coeficiente falla
    }

    // Iniciar los coeficientes 0.0
    for (int i = 0; i <= orden; i++)
    {
        nuevoPolinomio->coeficiente[i] = i + 1;
    }

    return nuevoPolinomio;
}