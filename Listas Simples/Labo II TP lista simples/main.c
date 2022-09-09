#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[30];
    char genero;

} stPersona;

typedef struct nodo
{
    stPersona persona;
    struct nodo * siguienteNodo;

} nodo;

void cargarPersonaToArchivo (char archivo[]);
void mostrarArchivoPersona(char archivo[]);
void mostrarDatosPersona (stPersona personaAux);

nodo * inicializarLista ();
nodo * archivoToLista (char archivo[], nodo * lista);
nodo * agregarPrincipio (nodo * lista, nodo * nuevoNodo);
nodo * agregarEnOrden (nodo * lista, nodo * nuevoNodo);
void mostrarNodoPersona (nodo * lista);

int existeDatoEnLista (nodo * lista, int dato);







int main()
{
    char archivoPersona[] = "archivoPersona.dat";
    int edad;

    nodo * lista  = inicializarLista();

    puts("-------- Archivo -----------");
    //cargarPersonaToArchivo(archivoPersona);
    mostrarArchivoPersona(archivoPersona);


    puts("\n\n-------- NODO ---------- ");      //Ejercicio 1 y 2
    lista = archivoToLista(archivoPersona, lista);
    mostrarNodoPersona(lista);

    puts("\n--------------");

    printf("\nIngrese una edad valdia para buscar en la lista: ");      // Ejercicio 3
    scanf("%d",&edad);

    if (existeDatoEnLista(lista,edad) == 1)
        printf("La edad buscada se encuentra en la lista");
    else
        printf("\nLa edad no se encuentra en la lista.");


    puts("\n--------------");







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

            printf("\nIngrese genero: ");
            fflush(stdin);
            scanf("%c",&personaAux.genero);

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
    printf("\nGenero: %c", personaAux.genero);
}

nodo * crearNodo (stPersona personaAux)
{
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));

    nuevoNodo->persona = personaAux;
    nuevoNodo->siguienteNodo = NULL;

    return nuevoNodo;

}

nodo * agregarPrincipio (nodo * lista, nodo * nuevoNodo)
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
            //lista = agregarPrincipio(lista,crearNodo(personaAux));
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
            lista = agregarPrincipio(lista,nuevoNodo);
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

    while (iterador != NULL)
    {
        if (iterador->persona.edad == dato)
            respuesta = 1;

        iterador = iterador->siguienteNodo;
    }

    return respuesta;
}























