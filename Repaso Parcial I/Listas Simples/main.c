#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int altura;
    char nombreCalle[30];

} stDireccion;



typedef struct
{
    int edad;
    char nombre[30];
    stDireccion datoDireccion;

} stPersona;

typedef struct nodo
{
    stPersona datoPersona;
    struct nodo * siguiente;

} nodo;

nodo * inicLista ();
stPersona crearPersona ();
nodo * crearNodoSimple (stPersona dato);
nodo * agregarAlPrincipioSimple (nodo * lista, nodo * nuevoNodo);
void mostrarLista (nodo * lista);
void mostrarPersona (stPersona dato);
void mostrarDireccion (stPersona dato);

nodo * agregarAlFinalSimple (nodo * lista, nodo * nuevoNodo);
nodo * darUltimoNodo (nodo * lista);


nodo * pasarArchivoToLista (char archivoPersona[], nodo * lista);
nodo * pasarArchivoToListaOrdenado (char archivoPersona[], nodo * lista);
nodo * agregarOrdenado (nodo * lista, nodo * nuevoNodo);
int existeDatoEnLista (nodo * lista, int datoBuscador);

nodo * intercambiarLista (nodo * lista1, nodo * lista2, nodo * listaIntercalada);


void cargarArchivoPersona (char archivoPersona[]);
void mostrarArchivoPersona (char archivoPersona[]);

nodo * invertirLista (nodo * lista);



void ejercicio1()
{
    nodo * lista = inicLista();
    char archivoPersona[] = "archivoPersona.dat";

    ///cargarArchivoPersona(archivoPersona);
    ///mostrarArchivoPersona(archivoPersona);

    lista = pasarArchivoToLista(archivoPersona,lista);

    mostrarLista(lista);
}

void ejercicio2()
{
    char archivoPersona2[] = "archivoPersona2.dat";
    nodo * lista = inicLista();

    cargarArchivoPersona(archivoPersona2);
    mostrarArchivoPersona(archivoPersona2);

    puts("");

    lista = pasarArchivoToListaOrdenado(archivoPersona2,lista);
    mostrarLista(lista);
}

void ejercicio3()
{
    int existe;
    int dato;
    nodo * lista = inicLista();
    lista = agregarAlPrincipioSimple(lista,crearNodoSimple(crearPersona()));
    lista = agregarAlPrincipioSimple(lista,crearNodoSimple(crearPersona()));

    printf("\nIngrese una edad para buscar en la lista: ");
    scanf("%d",&dato);

    existe = existeDatoEnLista(lista,dato);

    if (existe == 1)
    {
        printf("\nEl dato se encontro en la lista. ");
    }
    else
    {
        printf("\nEl dato no se encontro en la lista ");
    }
}

void ejercicio4()
{
    nodo * lista1 = inicLista();
    nodo * lista2 = inicLista();
    nodo * listaIntercalada = inicLista();

    lista1 = agregarAlPrincipioSimple(lista1,crearNodoSimple(crearPersona()));
    lista2 = agregarAlPrincipioSimple(lista2,crearNodoSimple(crearPersona()));

    listaIntercalada = intercambiarLista(lista1,lista2,listaIntercalada);

    mostrarLista(listaIntercalada);
}

void ejercicio5()
{
    nodo * lista = inicLista();

    lista = agregarAlPrincipioSimple(lista,crearNodoSimple(crearPersona()));
    lista = agregarAlPrincipioSimple(lista,crearNodoSimple(crearPersona()));

    mostrarLista(lista);

    system("pause");
    system("cls");

    lista = invertirLista(lista);

    mostrarLista(lista);
}



int main()
{





    return 0;
}


nodo * invertirLista (nodo * lista)
{
    nodo * aux;
    nodo * listaInvertida = inicLista();

    while (lista != NULL)
    {
        aux = lista;

        lista = lista->siguiente;

        aux->siguiente = inicLista();

        listaInvertida = agregarAlPrincipioSimple(listaInvertida,aux);

    }

    return listaInvertida;
}



nodo * intercambiarLista (nodo * lista1, nodo * lista2, nodo * listaIntercalada)
{
    nodo * repartidor = inicLista();

    while (lista1 != NULL && lista2 != NULL)
    {
        if (lista1->datoPersona.edad < lista2->datoPersona.edad)
        {
            repartidor = lista1;

            lista1 = lista1->siguiente;

            repartidor->siguiente = inicLista();

            listaIntercalada = agregarAlFinalSimple(listaIntercalada,repartidor);
        }
        else
        {
            repartidor = lista2;

            lista2 = lista2->siguiente;

            repartidor->siguiente = inicLista();

            listaIntercalada = agregarAlFinalSimple(listaIntercalada,repartidor);
        }
    }

    if (lista1 != NULL)
    {
        listaIntercalada = agregarAlFinalSimple(listaIntercalada,lista1);
    }
    else if(lista2 != NULL)
    {
        listaIntercalada = agregarAlFinalSimple(listaIntercalada,lista2);
    }

    return listaIntercalada;
}


int existeDatoEnLista (nodo * lista, int datoBuscador)
{
    nodo * buscador = lista;
    int respuesta = 0;

    if (buscador != NULL)
    {
        while (buscador != NULL && respuesta == 0)
        {
            if (buscador->datoPersona.edad == datoBuscador)
            {
                respuesta = 1;
            }

            buscador = buscador->siguiente;
        }
    }

    return respuesta;

}

nodo * pasarArchivoToListaOrdenado (char archivoPersona[], nodo * lista)
{
    FILE * archi = fopen(archivoPersona,"rb");
    stPersona datoPersona;

    if (archi != NULL)
    {
        while (fread(&datoPersona,sizeof(stPersona),1,archi) > 0)
        {
            lista = agregarOrdenado(lista,crearNodoSimple(datoPersona));
        }

        fclose(archi);
    }

    return lista;
}

nodo * agregarOrdenado (nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (lista->datoPersona.edad > nuevoNodo->datoPersona.edad)
        {
            lista = agregarAlPrincipioSimple(lista,nuevoNodo);
        }
        else
        {
            nodo * anterior = lista;
            nodo * siguiente = lista->siguiente;

            while (siguiente != NULL && siguiente->datoPersona.edad < nuevoNodo->datoPersona.edad)
            {
                anterior = siguiente;
                siguiente = siguiente->siguiente;
            }

            nuevoNodo->siguiente = siguiente;
            anterior->siguiente = nuevoNodo;
        }
    }

    return lista;
}

void cargarArchivoPersona (char archivoPersona[])
{
    FILE * archi = fopen(archivoPersona,"ab");
    int opcion;
    stPersona datoPersona;

    if (archi != NULL)
    {
        do
        {
            datoPersona = crearPersona();

            fwrite(&datoPersona,sizeof(stPersona),1,archi);

            printf("\nSeguir cargando? ... [ 0 ] == NO");
            fflush(stdin);
            scanf("%d",&opcion);

        }
        while (opcion == 1);

        fclose(archi);
    }
}

void mostrarArchivoPersona (char archivoPersona[])
{
    FILE * archi = fopen(archivoPersona,"rb");
    stPersona datoPersona;

    if (archi != NULL)
    {
        while (fread(&datoPersona,sizeof(stPersona),1,archi) > 0)
        {
            mostrarPersona(datoPersona);
        }

        fclose(archi);
    }
}

nodo * pasarArchivoToLista (char archivoPersona[], nodo * lista)
{
    FILE * archi = fopen(archivoPersona,"rb");
    stPersona datoPersona;
    if (archi != NULL)
    {
        while (fread(&datoPersona,sizeof(stPersona),1,archi) > 0)
        {
            lista = agregarAlPrincipioSimple(lista,crearNodoSimple(datoPersona));
        }

        fclose(archi);
    }

    return lista;
}

nodo * inicLista ()
{
    return NULL;
}

stPersona crearPersona ()
{
    stPersona persona;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(persona.nombre);

    printf("\nIngrese edad: ");
    scanf("%d",&persona.edad);

    printf("\nIngrese nombre de calle: ");
    fflush(stdin);
    gets(persona.datoDireccion.nombreCalle);

    printf("\nIngrese altura: ");
    scanf("%d",&persona.datoDireccion.altura);

    return persona;
}

nodo * crearNodoSimple(stPersona dato)
{
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));

    nuevo->datoPersona = dato;
    nuevo->siguiente = inicLista();


    return nuevo;
}

nodo * agregarAlPrincipioSimple (nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    return nuevoNodo;
}

void mostrarListaRecursiva (nodo * lista)
{
    if (lista != NULL)
    {
        mostrarPersona(lista->datoPersona);
        mostrarListaRecursiva(lista->siguiente);
    }
}

void mostrarLista (nodo * lista)
{
    nodo * iterador = lista;

    while (iterador != NULL)
    {
        mostrarPersona(iterador->datoPersona);
        iterador = iterador->siguiente;
    }
}

void mostrarPersona (stPersona dato)
{
    printf("\nNombre: %s", dato.nombre);
    printf("\nEdad: %d",dato.edad);
    mostrarDireccion(dato);
}

void mostrarDireccion (stPersona dato)
{
    printf("\nNombre calle: %s", dato.datoDireccion.nombreCalle);
    printf("\nAltura calle: %d", dato.datoDireccion.altura);
}

nodo * agregarAlFinalSimple (nodo * lista, nodo * nuevoNodo)
{
    nodo * ultimo;

    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        ultimo = darUltimoNodo(lista);

        ultimo->siguiente = nuevoNodo;

    }

    return lista;
}

nodo * darUltimoNodo (nodo * lista)
{
    nodo * ultimo = lista;

    if (ultimo != NULL)
    {
        while (ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;
        }

    }

    return ultimo;
}


