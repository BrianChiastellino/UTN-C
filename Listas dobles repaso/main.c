#include <stdio.h>
#include <stdlib.h>

/*
agregar un nodo al principio de la lista
lista doble
y mostrar la lista doble por pantalla

*/


typedef struct nodoDoble
{
    int dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;

}nodoDoble;

nodoDoble* inicializarLista ();
nodoDoble* crearNodo (int dato);
nodoDoble* agregarAlPrincipio (nodoDoble * listaDoble, nodoDoble * nuevoNodo);
void mostrarLista (nodoDoble * listaDoble);
void mostrarDatos (int datos);


int main()
{
    nodoDoble  * listaDoble = inicializarLista();

    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(5));
    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(10));
    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(3));
    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(7));
    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(29));
    listaDoble = agregarAlPrincipio(listaDoble,crearNodo(99));

    mostrarLista(listaDoble);


    return 0;
}

nodoDoble* inicializarLista ()
{
    return NULL;
}

nodoDoble* crearNodo (int dato)
{
    nodoDoble * nodoAux = (nodoDoble*) malloc(sizeof(nodoDoble));

    nodoAux->dato = dato;
    nodoAux->anterior = NULL;
    nodoAux->siguiente = NULL;

    return nodoAux;

}

nodoDoble* agregarAlPrincipio (nodoDoble * listaDoble, nodoDoble * nuevoNodo)
{
    nuevoNodo->siguiente = listaDoble; // El nuevoNodo->siguiente apunta a la lista;
    if (listaDoble != NULL)
    {
        listaDoble->anterior = nuevoNodo; // la lista->anterior apunta al nuevo nodo (entrelazamos los nodos)
    }

    return nuevoNodo;
}

void mostrarLista (nodoDoble * listaDoble)
{
    if (listaDoble == NULL)
        printf("No existen nodos");
    else
    {
        while (listaDoble != NULL)
        {
            mostrarDatos(listaDoble->dato);
            listaDoble = listaDoble->siguiente;
        }
    }
}

void mostrarDatos (int datos)
{
    printf("\nDato: %d", datos);
}





