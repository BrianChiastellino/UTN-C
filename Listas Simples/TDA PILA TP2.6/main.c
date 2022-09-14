#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[30];

}stPersona;



typedef struct
{
    stPersona persona;
    struct nodo * siguiente;

}nodo;

int main()
{


    return 0;
}
