#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[30];

} stPersona;

typedef struct stPila
{
    stPersona dato;
    struct stPila* siguienteTope;

} stPila;


stPila* inicLista();
void inicPila (stPila *pilita);
stPila* agregarAlPrincipio (stPila *pilita, stPila* nuevoTope);


int main ()
{

    stPila pilaMain;
    inicPila(&pilaMain);



    return 0;
}

stPila* inicLista()
{
    return NULL;
}

void inicPila (stPila *pilita)
{
    (pilita) = inicLista();
}


stPila* agregarAlPrincipio (stPila *pilita, stPila* nuevoTope)
{
    if (pilita == NULL)
    {
        pilita = nuevoTope;
    }
    else
    {
        nuevoTope->siguienteTope = pilita;
        pilita = nuevoTope;
    }

    return pilita;
}

stPila* crearPila (stPersona persona)
{
    stPila * pilita = (stPila*) malloc(sizeof(stPila));

    pilita->dato = persona;
    pilita->siguienteTope = NULL;

    return pilita;
}

void apilar (stPila * pilita, stPersona persona)
{
    stPila* aux = crearPila(persona);

    pilita = agregarAlPrincipio(pilita,aux);

}

stPersona cargarPersona ()
{
    stPersona persona;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(persona.nombre);

    printf("\nIngrese edad: ");
    scanf("%d",&persona.edad);

    return persona;
}

int pilaVacia (stPila * pilita)
{
    int respuesta = 0;

    if (pilita == NULL)
        respuesta = 1;

    return respuesta;
}

void mostrarPila (stPila * pilita)
{
    stPila * iterador = pilita;

    if (iterador != NULL)
    {
        printf("\nTope: ");

        while (iterador != NULL)
        {
            mostrarPersona(iterador->dato);
            iterador = iterador->siguienteTope;

        }

        printf("\nBase: ");
    }

}

void mostrarPersona (stPersona persona)
{
    printf("\nPersona: %s",persona.nombre);
    printf("\nPersona edad: %d",persona.edad);
}

