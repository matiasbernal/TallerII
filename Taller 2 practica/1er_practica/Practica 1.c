
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------- 1.Escriba un programa que genere la matriz identidad de tama ̃no N x N.------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 4

    // Programa para imprimir una matriz identidad NxN
    int
    main()
{
    int matriz[N][N];
    int valor = 0;
    srand(time(NULL));

 for (int i = 0; i < N; i++)
 {
    for (int j = 0; j < N; j++)
    {
        valor = rand() % 100 + 1;
        matriz[i][j] = valor;
    }
 }

 //Imprimir matriz
 printf("Matriz:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }


}

*/

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
        for (int j = 0; j < N-1; j++)
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
        for (int i = 0; i < N-1; i++)
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

//---------3. Suma de matrices: Programa que realiza la suma de dos matrices de N x N.
/*Teclea el tamano de la matriz : 4
Contenido de las matrices
Matriz 1
1 2 1 3
1 4 5 6
6 2 1 6
7 4 3 1
Matriz 2
2 3 2 5
5 4 2 1
8 7 6 9
9 5 4 1
Suma
3 5 3 8
6 8 8 7
14 9 7 15
16 9 7 2
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int suma_matrices(int matriz1[][N], int matriz2[][N]);

int main()
{
    int matriz1[N][N];
    int matriz2[N][N];
    int temp = 0;
    srand(time(NULL));

    // ciclo para llenar t mostrar la matriz 1
    printf("Matriz 1: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = rand() % 10 + 1;
            matriz1[i][j] = temp;
            printf("%3d ", matriz1[i][j]);
        }
        printf("\n");
    }

    // Ciclo para llenar y mostrar la matriz 2
    printf("Matriz 2: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = rand() % 10 + 1;
            matriz2[i][j] = temp;
            printf("%3d ", matriz2[i][j]);
        }
        printf("\n");
    }

    suma_matrices(matriz1, matriz2);

    return 0;
}

int suma_matrices(int matriz1[][N], int matriz2[][N])
{
    printf("Suma: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }
}
*/

//----------4. Matriz transpuesta ---------------------
/*
Teclea el numero de renglones : 3
Teclea el numero de columnas : 4
MATRIZ ORIGINAL
1 4 5 7
2 4 1 5
7 6 4 9
MATRIZ TRANSPUESTA
1 2 7
4 4 6
5 1 4
7 5 9
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int filas, columnas = 0;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];
    int matriz_transpuesta[columnas][filas];
    int temp = 0;

    srand(time(NULL));

    // Ciclo para llenar la matriz
    printf("Matriz: \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int temp = rand() % 10 + 1;
            matriz[i][j] = temp;
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Ciclo para imprimir la matriz transpuesta
    printf("Matriz transpuesta: \n");
    for (int j = 0; j < columnas; j++)
    {
        for (int i = 0; i < filas; i++)
        {
            temp = matriz[i][j];
            matriz_transpuesta[j][i] = temp;
            printf("%3d ", matriz_transpuesta[j][i]);
        }
        printf("\n");
    }
}

*/

//----------5. Matriz simetrica ---------------------

// -------------6 Def sig variables-----------
/*
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
*/