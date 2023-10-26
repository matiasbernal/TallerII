/*1) 
Defina una estructura que permita almacenar la siguiente informacion:
i) dirección IP
ii) mascara de red

Crear una función que tome un puntero a dicha estructura y que devuelva
una cadena con el número de red.

Ej:
IP: 192.168.146.222
Mask: 255.255.255.0
Salida: 192.168.146.0 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POS_IP 4 //total de caracteres necesitados para ingresar la direccion ip y la mask contando numeros y puntos

typedef struct{
    int* direccion_ip;
    int* mascara_red;
}Informacion_red;

char* salida_informacion_red(Informacion_red*);
void cargar_ip(Informacion_red*, int);
void imprimir_ip(Informacion_red*, int);
void cargar_mask(Informacion_red*, int);
void imprimir_mask(Informacion_red*, int);
int* salida(Informacion_red*, int);
void imprimir_salida(int*, int);

int main(void){
    Informacion_red entrada;
    entrada.direccion_ip = (int*)malloc(sizeof(int)*POS_IP);
    entrada.mascara_red = (int*)malloc(sizeof(int)*POS_IP);
    srand(time(NULL));
    cargar_ip(&entrada, POS_IP);
    printf("IP: ");
    imprimir_ip(&entrada, POS_IP);
    printf("\n");
    cargar_mask(&entrada, POS_IP);
    printf("Mask: ");
    imprimir_mask(&entrada, POS_IP);
    int* devolucion;
    devolucion = salida(&entrada, POS_IP);
    printf("\n");
    printf("Salida: ");
    imprimir_salida(devolucion, POS_IP);
    return 0;
}

void cargar_ip(Informacion_red* entrada, int pos_ip){
    entrada->direccion_ip[0] = rand()%223+1;
    for(int i=1; i<=pos_ip; i++){
        entrada->direccion_ip[i] = rand()%255+1;
    }
}

void imprimir_ip(Informacion_red* entrada, int pos_ip){
    int i;
    for(i=0; i<pos_ip-1; i++){
        printf("%d.", entrada->direccion_ip[i]);
    }
    printf("%d", entrada->direccion_ip[i]);
}

void cargar_mask(Informacion_red* entrada, int pos_ip){
    if(entrada->direccion_ip[0] <= 127){
        entrada->mascara_red[0] = 255;
        for(int i=1; i<pos_ip; i++){
            entrada->mascara_red[i] = 0;
        }
    }else if(entrada->direccion_ip[0] > 127 && entrada->direccion_ip[0] <= 191){
        entrada->mascara_red[0] = 255;
        entrada->mascara_red[1] = 255;
        for(int i=2; i<pos_ip; i++){
            entrada->mascara_red[i] = 0;
        }
    }else{
        for(int i=0; i<pos_ip-1; i++){
            entrada->mascara_red[i] = 255;
        }
        entrada->mascara_red[pos_ip-1] = 0;
    }
}

void imprimir_mask(Informacion_red* entrada, int pos_ip){
    int i;
    for(i=0; i<pos_ip-1; i++){
        printf("%d.", entrada->mascara_red[i]);
    }
    printf("%d", entrada->mascara_red[i]);
}

int* salida(Informacion_red* entrada, int pos_ip){
    int* devolucion;
    devolucion = (int*)malloc(sizeof(int)*pos_ip);
    if(entrada->direccion_ip[0] <= 127){
        devolucion[0] = entrada->direccion_ip[0];
        for(int i=1; i<pos_ip; i++){
            devolucion[i] = 0;
        }
    }else if(entrada->direccion_ip[0] > 127 && entrada->direccion_ip[0] <= 191){
        for(int i=0; i<pos_ip; i++){
            if(i<(pos_ip/2)){
                devolucion[i] = entrada->direccion_ip[i];
            }else if(i>=2){
                devolucion[i] = 0;
            }
        }
    }else{
        for(int i=0; i<pos_ip; i++){
            if(i<(pos_ip-1)){
                devolucion[i] = entrada->direccion_ip[i];
            }else{
                devolucion[i] = 0;
            }
        }
    }
    return devolucion;
}

void imprimir_salida(int* devolucion, int pos_ip){
    int i;
    for(i=0; i<(pos_ip-1); i++){
        printf("%d.", devolucion[i]);
    }
    printf("%d", devolucion[i]);
}