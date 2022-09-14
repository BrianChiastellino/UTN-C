#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[30];

} stPersona;

typedef struct Pila
{
    stPersona persona;
    struct Pila * topeAnterior;

} Pila;

typedef struct nodo
{
    stPersona persona;
    struct nodo * siguienteNodo;

} nodo;

void cargarPersonaToArchivo (char archivo[]);
void mostrarArchivoPersona(char archivo[]);
void mostrarDatosPersona (stPersona personaAux);
void mostrarNodoPersona (nodo * lista);

nodo * inicializarLista ();
nodo * archivoToLista (char archivo[], nodo * lista);
nodo * agregarAlPrincipio (nodo * lista, nodo * nuevoNodo);
nodo * crearNodo (stPersona personaAux);
nodo * agregarEnOrden (nodo * lista, nodo * nuevoNodo);
nodo * agregarAlFinal (nodo * lista, nodo * nuevoNodo);
nodo * intercambiarListas (nodo * lista1, nodo * lista2, nodo * lista3);
nodo * invertirLista (nodo * lista);

int existeDatoEnLista (nodo * lista, int dato);

////////// TDA PILA proximamente /////////////




int main()
{
    char archivoPersona2[] = "archivoPersona2.dat";
    Pila pilaMain;


    char archivoPersona[] = "archivoPersona.dat";

    nodo * lista  = inicializarLista();
    nodo * listaDos = inicializarLista();
    nodo * listaIntercalada = inicializarLista();

    /*
        cargarPersonaToArchivo(archivoPersona);
        printf("\nSegundo archivo");
        cargarPersonaToArchivo(archivoPersona2);
    */


    lista = archivoToLista(archivoPersona,lista);
    listaDos = archivoToLista(archivoPersona2,listaDos);

    // mostrarNodoPersona(lista);
    // mostrarNodoPersona(listaDos);

    listaIntercalada = intercambiarListas(lista,listaDos,listaIntercalada);

    mostrarNodoPersona(listaIntercalada);

    listaIntercalada = invertirLista(listaIntercalada);

    mostrarNodoPersona(listaIntercalada);


    return 0;
}

nodo * inicializarLista ()
{
    return NULL;
}

void cargarPersonaToArchivo (char archivo[])
{
    FILE *archi = fopen(archivo,"ab");
    stPersona personaAux;

    if (archi != NULL)
    {
        int salida = 1;

        while (salida == 1)
        {

            printf("\nIngrese edad: ");
            fflush(stdin);
            scanf("%d",&personaAux.edad);

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(personaAux.nombre);

            fwrite(&personaAux,sizeof(stPersona),1,archi);

            printf("\nSALIR = 0 || SEGUIR = 1 ");
            fflush(stdin);
            scanf("%d",&salida);

        }

        fclose(archi);
    }
    else
    {
        printf("Error al abrir el archivo");
    }

}

void mostrarArchivoPersona (char archivo[])
{
    FILE * archi = fopen(archivo,"rb");
    stPersona personaAux;

    if (archi != NULL)
    {
        while (fread(&personaAux,sizeof(stPersona),1,archi) > 0)
        {
            mostrarDatosPersona(personaAux);
        }

        fclose(archi);
    }
    else
    {
        printf("\nERROR");
    }
}

void mostrarDatosPersona (stPersona personaAux)
{
    printf("\n---------------");
    printf("\nNombre: %s",personaAux.nombre);
    printf("\nEdad: %d",personaAux.edad);
}

nodo * crearNodo (stPersona personaAux)
{
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));

    nuevoNodo->persona = personaAux;
    nuevoNodo->siguienteNodo = NULL;

    return nuevoNodo;

}

nodo * agregarAlPrincipio (nodo * lista, nodo * nuevoNodo)
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

nodo * archivoToLista (char archivo[], nodo * lista)
{
    FILE *archi = fopen(archivo,"rb");
    stPersona personaAux;

    if (archi != NULL)
    {
        while (fread(&personaAux,sizeof(stPersona),1,archi) > 0)
        {
            lista = agregarEnOrden(lista,crearNodo(personaAux));
            //lista = agregarAlPrincipio(lista,crearNodo(personaAux));
        }

        fclose(archi);
    }
    else
    {
        puts("ERROR");
    }

    return lista;
}

void mostrarNodoPersona (nodo * lista)
{
    nodo * iterador = lista;

    if (iterador == NULL)
        puts("No hay nodos");
    else
    {
        while (iterador != NULL)
        {
            mostrarDatosPersona(iterador->persona);
            iterador = iterador->siguienteNodo;
        }
    }
}

nodo * agregarEnOrden (nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->persona.edad < lista->persona.edad)
        {
            lista = agregarAlPrincipio(lista,nuevoNodo);
        }
        else
        {
            nodo * anterior = lista;
            nodo * iterador = lista;

            while (iterador != NULL && nuevoNodo->persona.edad > iterador->persona.edad)
            {
                anterior = iterador;
                iterador = iterador->siguienteNodo;
            }

            anterior->siguienteNodo = nuevoNodo;
            nuevoNodo->siguienteNodo = iterador;
        }
    }

    return lista;

}

int existeDatoEnLista (nodo * lista, int dato)
{
    nodo * iterador = lista;
    int respuesta = 0;

    while (iterador != NULL && respuesta == 0)
    {
        if (iterador->persona.edad == dato)
            respuesta = 1;

        iterador = iterador->siguienteNodo;
    }

    return respuesta;
}


nodo * intercambiarListas (nodo * lista1, nodo * lista2, nodo * lista3)
{

    /*

    - Agregar al principio o agregar al final el unico cambio es el orden en que se guardan y se muestran.
    - Mayor edad principio es agregarAlPrincipio
    - Menor edad principio es agregarAlFinal

    */
    nodo * aux;

    while (lista1 != NULL && lista2 != NULL)
    {
        if (lista1->persona.edad < lista2->persona.edad)
        {
            aux = lista1;

            lista1 = lista1->siguienteNodo;

            aux->siguienteNodo = inicializarLista();

            lista3 = agregarAlFinal(lista3,aux);
        }
        else
        {
            aux = lista2;

            lista2 = lista2->siguienteNodo;

            aux->siguienteNodo = inicializarLista();

            lista3 = agregarAlFinal(lista3,aux);
        }
    }

    if (lista1 != NULL)
    {
        lista3 = agregarAlFinal(lista3,lista1);
    }
    else if (lista2 != NULL)
    {
        lista3 = agregarAlFinal(lista3,lista2);
    }

    return lista3;
}

nodo * agregarAlFinal (nodo * lista, nodo * nuevoNodo)
{
    nodo * anterior = lista;
    nodo * iterador = lista;

    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (iterador != NULL)
        {
            anterior = iterador;
            iterador = iterador->siguienteNodo;
        }

        anterior->siguienteNodo = nuevoNodo;
        nuevoNodo->siguienteNodo = iterador;

    }

    return lista;

}

nodo * invertirLista (nodo * lista)
{
    nodo * aux;
    nodo * listaInvertida = inicializarLista();

    while (lista != NULL)
    {
        printf("\nlasdkas");

        aux = lista;

        lista = lista->siguienteNodo;

        aux->siguienteNodo = NULL;

        listaInvertida = agregarAlPrincipio(listaInvertida,aux);

    }

    return listaInvertida;
}

/////////////// TDA PILA ////////////

int pilaVacia (Pila ** pila)
{
    int respuesta = 1;

    if ((*pila) == NULL)
        respuesta = 0;

    return respuesta;
}

stPersona topePila(Pila * pila)
{
    stPersona aux = pila->persona;
    return aux;
}

stPersona desapilarTope (Pila * pila)
{
    stPersona aux = darPrimerStPersona(pila);
    borrarPrimero(pila);
    return aux;
}

stPersona darPrimerStPersona (Pila * pila)
{
    stPersona aux = pila->persona;
    return aux;
}


void borrarPrimero (nodo * lista)
{
    nodo * primerNodo = inicializarLista();

    if (lista != NULL)
    {
        primerNodo = lista;
        lista = lista->siguienteNodo;
        free(primerNodo);
    }
}

void apilarPila (Pila * pila, stPersona datoPersona)
{
    pila = agregarAlPrincipio(pila,datoPersona);
}







