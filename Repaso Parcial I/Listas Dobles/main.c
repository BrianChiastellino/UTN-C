#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int edad;
    char nombre[30];

} stAlumno;

typedef struct nodoDoble
{
    stAlumno dato;
    struct nodoDoble * anterior;
    struct nodoDoble * siguiente;

}nodoDoble;

nodoDoble * inicializarLista ();
nodoDoble * crearNodoDoble (stAlumno datoAlumno);
nodoDoble * agregarAlPrincipio (nodoDoble * lista, nodoDoble * nuevoNodo);
nodoDoble * agregarAlPrincipioV2(nodoDoble * lista, stAlumno datoAlumno);
nodoDoble * agregarAlFinal (nodoDoble* lista, nodoDoble * nuevoNodo);
nodoDoble * agregarAlFinalV2(nodoDoble * lista, stAlumno datoAlumno);
nodoDoble * obtenerUltimoNodoRecursivo (nodoDoble * lista);
nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo);
stAlumno crearAlumno ();
void mostrarLista (nodoDoble * lista);



int main()
{


    return 0;
}

nodoDoble * inicializarLista ()
{
    return NULL;
}


nodoDoble * agregarAlPrincipio (nodoDoble * lista, nodoDoble * nuevoNodo)
{
    nuevoNodo->siguiente = lista;

    if (lista != NULL)
    {
        lista->anterior = nuevoNodo;
    }

    return nuevoNodo;
}

nodoDoble * agregarAlPrincipioV2(nodoDoble * lista, stAlumno datoAlumno)
{
    nodoDoble * nuevo = crearNodoDoble(datoAlumno);

    nuevo->siguiente = lista;

    if (lista != NULL)
    {
        lista->anterior = nuevo;
    }

    return nuevo;
}

nodoDoble * crearNodoDoble (stAlumno datoAlumno)
{
    nodoDoble * nuevo = (nodoDoble*) malloc(sizeof(nodoDoble));

    nuevo->dato = datoAlumno;
    nuevo->siguiente = inicializarLista();
    nuevo->anterior = inicializarLista();

    return nuevo;
}

nodoDoble * agregarAlFinal (nodoDoble* lista, nodoDoble * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoDoble * ultimo = obtenerUltimoNodoRecursivo(lista);

        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }

    return lista;
}

nodoDoble * agregarAlFinalV2(nodoDoble * lista, stAlumno datoAlumno)
{
    if (lista == NULL)
    {
        lista = crearNodoDoble(datoAlumno);
    }
    else
    {
        nodoDoble * ultimo = obtenerUltimoNodoRecursivo(lista);
        nodoDoble * nuevo = crearNodoDoble(datoAlumno);

        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;
}

nodoDoble * obtenerUltimoNodoRecursivo (nodoDoble * lista)
{
    nodoDoble * ultimo;

    if (lista == NULL)
    {
        ultimo = inicializarLista();
    }
    else
    {
        if (lista->siguiente != NULL)
        {
            ultimo = lista;
        }
        else
        {
            ultimo = obtenerUltimoNodoRecursivo(lista->siguiente);
        }
    }

    return ultimo;
}

nodoDoble * agregarEnOrdenDoble (nodoDoble * lista, nodoDoble * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if (lista->dato.edad > nuevo->dato.edad)
        {
            lista = agregarAlPrincipio(lista,nuevo);
        }
        else
        {
            nodoDoble * anterior = lista;
            nodoDoble * siguiente = lista->siguiente;

            while (siguiente != NULL && siguiente->dato.edad < nuevo->dato.edad)
            {
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }

            anterior->siguiente = nuevo;
            nuevo->anterior = anterior;
            nuevo->siguiente = siguiente;

            if (siguiente != NULL)
            {
                siguiente->anterior = nuevo;
            }
        }
    }

    return lista;
}

void mostrarLista (nodoDoble * lista)
{
    nodoDoble * iterador = lista;

    if (lista != NULL)
    {
        while (iterador != NULL)
        {
            mostrarAlumno(iterador->dato);
            iterador = iterador->siguiente;
        }
    }
}

void mostrarAlumno (stAlumno datoAlumno)
{
   printf("\nNombre: %s",datoAlumno.nombre);
   printf("\nEdad: %d",datoAlumno.edad);

}

stAlumno crearAlumno ()
{
    stAlumno datoAlumno;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(datoAlumno.nombre);

    printf("\nIngrese edad: ");
    fflush(stdin);
    scanf("%d",&datoAlumno.edad);

    return datoAlumno;
}







