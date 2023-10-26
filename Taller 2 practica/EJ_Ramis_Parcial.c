/*
1) Defina una estructura que permita almacenar la siguiente información:
i) dirección IP
ii) mascara de red

Crear una función que tome un puntero a dicha estructura y que devuelva
una cadena con el número de red.

Ej:
IP: 192.168.146.222
Mask: 255.255.255.0

Salida: 192.168.146.0

2) Definir la función expandir con el siguiente prototipo:

int **expandir(int **matriz, int filas, int cols);

que dada una matriz, la cantidad de filas y columnas de la misma, construya
otra matriz con una fila más y una columna más, completando los valores
nuevos de la matríz con 0.
*/

typedef struct ipinfo
{
    char ip[16];      // Direccion IP en formato "xxx.xxx.xxx.xxx\0"
    char mascara[16]; // Mascara de red en fomato "xxx.xxx.xxx.xxx\0"
} Ipinfo;
