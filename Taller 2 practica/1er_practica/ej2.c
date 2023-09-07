/*
2.Un instituto desea controlar los resultados de los alumnos en las diferentes
asignaturas de un curso de inform ́atica.
El programa debe leer las calificaciones obtenidas en las distintas asignaturas
y visualizar en pantalla el n ́umero de cada estudiante seguido por su promedio,
ademas se deber ́a imprimir al lado ”libre”, regular.o ”promovido”, si dicho pro-
medio est ́a en los intervalos [0,6), [6,8) y [8,10] respectivamente.
El programa visualizar ́a tambi ́en la calificaci ́on promedio de todos los estu-
diantes de cada asignatura.
Organice los datos de la siguiente manera:

            notas materias   avg alumno
 Alumnos     [] [] [] []        []
 Alumnos     [] [] [] []        []
 Alumnos     [] [] [] []        []
 Alumnos     [] [] [] []        []

Avg materias [] [] [] []

*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

void avg_alumnos(int matriz_notas[][N]);
void avg_materias(int matriz_notas[][N]);

int main()
{
    float avg, suma = 0;

    float matriz_notas[N][N] = {{10, 9, 8, 7.4}, {5, 4, 3, 6}, {6.4, 5, 7, 8.2}, {6, 8.2, 6.1, 6.8}};

    printf("\t\t     Notas de los alumnos    promedio alumnos\n");
    for (int i = 0; i < N - 1; i++)
    {
        printf("\t Alumno %d:  ", i + 1);
        for (int j = 0; j < N - 1; j++)
        {
            suma += matriz_notas[i][j];
            printf("%.1f   ", matriz_notas[i][j]);
        }
        // Mostrar el promedio del alumno
        avg = suma / 4;
        printf("\t %.2f", avg);
        suma = 0;
        printf("\n");
    }

    printf("Promedio materias:  ");
    for (int j = 0; j < N - 1; j++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            suma += matriz_notas[i][j];
        }
        // Mostrar el promedio de la materia
        avg = suma / 4;
        printf("%.2f  ", avg);
        suma = 0;
    }

    return 0;
}