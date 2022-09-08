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
    stPersona persona;
    struct nodo * siguienteNodo;

} nodo;

nodo * inicializarLista ();
void cargarPersonaToArchivo (char archivo[]);
void mostrarArchivoPersona(char archivo[]);
void mostrarDatosPersona (stPersona personaAux);

nodo * agregarPrincipio (nodo * lista, nodo * nuevoNodo);
nodo * archivoToLista (char archivo[], nodo * lista);
void mostrarNodoPersona (nodo * lista);


//void mostrarNodosDiego(stNodo** lista);



int main()
{
    char archivoPersona[] = "archivoPersona.dat";
    char archivoEntero [] = "archivoEntero.dat";

    nodo * lista  = inicializarLista();
    nodo * lista1 = inicializarLista();


    puts("-------- Archivo -----------");
    //cargarPersonaToArchivo(archivoPersona);
    mostrarArchivoPersona(archivoPersona);

    puts("\n\n-------- NODO ---------- ");
    lista = archivoToLista(archivoPersona, lista);
    mostrarNodoPersona(lista);

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

            lista = agregarPrincipio(lista,crearNodo(personaAux));
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
    nodo * aux = lista;

    if (aux == NULL)
        puts("No hay nodos");
    else
    {
        while (aux != NULL)
        {
            mostrarDatosPersona(aux->persona);
            aux = aux->siguienteNodo;
        }
    }
}









