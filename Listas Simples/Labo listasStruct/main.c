#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int edad;
    char nombre[30];
    char genero;

} stPersona;

typedef struct
{
    stPersona datoPersona;
    struct nodo* siguienteNodo;

} nodo;


nodo* inicializarLista ();
void cargarStPersona (stPersona *persona);
nodo* crearNodo (nodo* lista, stPersona persona);
nodo * agregarNodoAfila (nodo* lista, nodo* nuevoNodo);
void mostrarNodos (nodo * lista);


int main()
{
    nodo * lista  = inicializarLista();
    stPersona arregloSt;
    nodo * nuevoNodo;

    cargarStPersona(&arregloSt);
    nuevoNodo = crearNodo(lista,arregloSt);
    lista = agregarNodoAfila(lista,nuevoNodo);

    printf("\n\nSegunda parte: ");

    cargarStPersona(&arregloSt);
    nuevoNodo = crearNodo(lista,arregloSt);
    lista = agregarNodoAfila(lista,nuevoNodo);


    mostrarNodos(lista);






    return 0;
}

nodo* inicializarLista ()
{
    return NULL;
}

void cargarStPersona (stPersona *persona)
{
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(persona->nombre);

    printf("\nIngrese edad para %c %s %c",34,persona->nombre,34);
    fflush(stdin);
    scanf("%d",&persona->edad);

    printf("\nIngrese genero ");
    fflush(stdin);
    scanf("%c", &persona->genero);

    system("cls");

}

nodo* crearNodo (nodo* lista, stPersona persona)
{
    nodo * nodoAux = (nodo*)malloc(sizeof(nodo));

    nodoAux->datoPersona.edad = persona.edad;
    nodoAux->datoPersona.genero = persona.genero;
    strcpy(nodoAux->datoPersona.nombre,persona.nombre);
    nodoAux->siguienteNodo = NULL;

    return nodoAux;
}

nodo * agregarNodoAfila (nodo* lista, nodo* nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguienteNodo = lista;
        lista = nuevoNodo;
    }

    return lista;
}

void mostrarNodos (nodo * lista)
{
    nodo* nodoAux = lista;

    if (nodoAux == NULL)
    {
        printf("\nNo hay nodos cargados");
    }
    else
    {
     while (nodoAux != NULL)
     {
        printf("\nNombre: %s",nodoAux->datoPersona.nombre);
        printf("\nEdad: %d",nodoAux->datoPersona.edad);
        printf("\nGenero: %c",nodoAux->datoPersona.genero);

        nodoAux = nodoAux->siguienteNodo;
     }
    }
}



