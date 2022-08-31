#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Listas vinculadas:

Conjunto de datos secuencical.
Todos los nodos son iguales, y tienen que tener un nodo siguiente.


*/


typedef struct
{
    char nombre[30];
    int edad;
    struct  nodo* siguienteNodo;

} nodo;


// SIN PROTOTIPADOS ME TIRA ERROR, PROBRAR EN OTRA PC

nodo* inicializarLista();
nodo* crearNodo (char nombre[30], int edad);
nodo* agregarPrincipio (nodo* lista, nodo *nodoNuevo);
nodo* darUltimoNodo (nodo* lista);






int main()
{


    nodo * lista;
    nodo * nuevoNodo;
    nodo * ultimoNodo;
    lista = inicializarLista(); // inicializamos la lista en NULL

    printf("\nPrimer version de LISTA");
    printf("\nDireccion de lista: %p",lista);

    printf("\n----------");


    nuevoNodo = crearNodo("Brian",23); // creamos el nodo, y lo retornamos a un puntero de tipo nodo "nuevoNodo"
    lista = agregarPrincipio(lista,nuevoNodo); // En LISTA guardamos la direccion de memoria del ultimo nodo cargado.

    printf("\nPrimer lista.");
    printf("\nDireccion del nuevo nodo: %p",nuevoNodo);
    printf("\nDireccion de lista: %p",lista);


    nuevoNodo = crearNodo("Candela",23);
    lista = agregarPrincipio(lista,nuevoNodo);

    printf("\n\n-----------------");

    printf("\nSegunda lista");
    printf("\nDireccion del nuevo nodo: %p",nuevoNodo);
    printf("\nDireccion de lista: %p",lista);

    printf("\n\n-----------------");


    nuevoNodo = crearNodo("Candela",23);
    lista = agregarPrincipio(lista,nuevoNodo);

    printf("\n\n-----------------");


    printf("\nTercera lista");
    printf("\nDireccion del nuevo nodo: %p",nuevoNodo);
    printf("\nDireccion de lista: %p",lista);

    /*

    En resumen:

    - LISTA es una variable estatica, ya que vive en el main que CONTIENE LA DIRECCION DE MEMORIA DEL ULTIMO NODO CARGADO

    - nuevoNodo es un puntero DE TIPO NODO que guarda la direccion de memoria (se la retornamos desde la funcion "crearNodo")
        y la direccion de memoria donde esta el ultimo nodo cargado, se la asignamos a LISTA.

    */




    return 0;
}

nodo* inicializarLista()
{
    return NULL;
}

nodo* crearNodo (char nombre[30], int edad)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));

    aux->edad = edad;
    strcpy(aux->nombre,nombre);
    aux->siguienteNodo = NULL;

    return aux;
}

nodo* agregarPrincipio (nodo* lista, nodo *nodoNuevo)   // agregar nodo al ciclo
{
    if (lista == NULL)
    {
        lista = nodoNuevo;
    }
    else
    {
        nodoNuevo->siguienteNodo = lista;  // el nuevoNodo, tiene la direccion de memoria del anterior nodo. Lo guardamos en ->siguienteNodo, asi no perdemos datos.
        lista = nodoNuevo;      // lista guarda la direccion de memoria del nuevo nodo
    }

    return lista;
}

nodo* darUltimoNodo (nodo* lista)
{
    nodo* siguiente = lista;

    if (siguiente != NULL)
    {
        while (siguiente->siguienteNodo != NULL)
        {

            siguiente = siguiente->siguienteNodo;
        }
    }

    return siguiente;
}























