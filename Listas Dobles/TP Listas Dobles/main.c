#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int edad;
    char nombre[30];

} stPersona;

typedef struct nodoDoble
{
    stPersona persona;
    struct    nodoDoble * siguienteNodo;
    struct    nodoDoble * anteriorNodo;

} nodoDoble;

int main()
{
    nodoDoble * listaDoble = inicializarLista();

    return 0;
}

nodoDoble * inicializarLista ()
{
    return NULL;
}

nodoDoble * crearNodoDoble (nodoDoble * lista, stPersona personaDato)
{
    nodoDoble * nuevoNodoDoble = (nodoDoble) malloc(sizoef(nodoDoble));
    nuevoNodoDoble->persona = personaDato;
    nuevoNodoDoble->siguienteNodo = inicializarLista();
    nuevoNodoDoble->anteriorNodo = inicializarLista();

    return nuevoNodoDoble;

}

stPersona crearPersona ()
{
    stPersona nuevaPersona;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(nuevaPersona.nombre);

    printf("\nIngrese edad: ");
    scanf("%d",&nuevaPersona.edad);

    return nuevaPersona;
}

void mostrarListaDoble (nodoDoble * lista)
{
    nodoDoble * iterador = lista;

    while (iterador != NULL)
    {
        mostrarPersona(iterador->persona);
        iterador = iterador->siguienteNodo;
    }
}

void mostrarPersona (stPersona personaDato)
{
    printf("\nNombre: %s",personaDato.nombre);
    printf("\nEdad: %d",personaDato.edad);
}



