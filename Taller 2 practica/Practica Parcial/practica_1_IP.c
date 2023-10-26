/**
1) Defina una estructura que permita almacenar la siguiente información:
    i) dirección IP
    ii) mascara de red

Crear una función que tome un puntero a dicha estructura y que devuelva
una cadena con el número de red.
Ej:
    IP: 192.168.146.222
    Mask: 255.255.255.0
    Salida: 192.168.146.0
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** ESTRUCTURAS **/
typedef struct red {
    unsigned char ip[4];
    unsigned char mask[4];
} Red;

/** PROTOTIPOS FUNCIONES **/
Red* crearRed();            ///-> Crea Objeto Red (retorna puntero a Red)
char* charRed(Red* p_red);   ///-> Toma un puntero a Red y retorna una cadena
                            ///   con el nro de red.

int main()
{
    Red red001;
    Red* p_red001 = &red001;

    /** Red - Creacion **/
    p_red001 = crearRed();  ///-> Creo Objeto Red

    ///-> Mostramos los valores en forma concatenada
    printf("Direccion IP: ");
    for(int i = 0; i < 4; i++) {
        if(i == 3) {
            printf( "%hhu\n", p_red001->ip[i] );    /// '%hhu' -> type spec. uns. char
        } else {
            printf( "%hhu.", p_red001->ip[i] );
        }
    }
    printf("Mascara de Red: ");
    for(int i = 0; i < 4; i++) {
        if(i == 3) {
            printf( "%hhu\n", p_red001->mask[i] );
        } else {
            printf( "%hhu.", p_red001->mask[i] );
        }
    }

    ///-> Combinamos ambos arrays de numeros (direccion de IP y mascara de red) y creamos
    ///   el Nro de IP
    char* nroIP;
    nroIP = (char*) malloc(sizeof(char) * 16);
    nroIP = charRed(p_red001);
    printf("Nro. de IP: %s", nroIP);

    return 0;
}

Red* crearRed()
{
    Red* nuevaRed;
    nuevaRed = (Red*) malloc( sizeof(Red) );

    ///-> Ingresamos los atributos (nuevaRed->ip y nuevaRed->mask) por separado,
    ///   ya que en un mismo bucle no funciona (PROBADO)
    for(int i = 0; i < 4; i++) {
        printf("Ingrese el numero %d de la direccion IP: ", i);
        scanf("%hhu", &(nuevaRed->ip[i]) );
    }
    for(int i = 0; i < 4; i++) {
        printf("Ingrese el numero %d de la mascara de red: ", i);
        scanf("%hhu", &(nuevaRed->mask[i]) );
    }
    return nuevaRed;
}

char* charRed(Red* p_red)
{
    /// Cadena - Inic.
    char* string;
    string = (char*) malloc(sizeof(char) * 16);

    ///-> Aplico mascara (0) al nro. del IP correspondiente
    for(int i = 0; i < 4; i++) {
        if(p_red->mask[i] == 0) {
            p_red->ip[i] = 0;
        }
    }

    ///-> Concateno y creo el string de retorno
    for(int i = 0; i < 4; i++) {
        switch(i) {
            case 0:
                sprintf(string, "%d%c", p_red->ip[0], '.');
                break;
            case 1:
                sprintf(string, "%s%d%c", string, p_red->ip[i], '.');
                break;
            case 2:
                sprintf(string, "%s%d%c", string, p_red->ip[i], '.');
                break;
            case 3:
                sprintf(string, "%s%d%c", string, p_red->ip[i], '\0');
                break;
        }
    }
    return string;
}
