
#include <stdlib.h>

typedef struct 
{
    int latitud;
    int longitud;
}pos;


int main() {

    pos arr[10];

    pos *pt = (pos *)malloc(sizeof(pos) * 10);

    for (int i = 0; i < 10; i++)
    {
        *(arr + i) = (pos *)malloc(sizeof(pos)); // arr[i] === *(arr +i)
    }
    

    return 0;
}