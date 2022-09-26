#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    int edad;

} stPersona;

typedef struct Pila
{
    stPersona datoPersona;
    struct Pila * anterior;

} Pila;

void inicPila (Pila ** p);
Pila * crearTope (stPersona dato);
void apilar (Pila ** p, Pila* tope);
stPersona desapilar (Pila **p);
int pilaVacia (Pila ** p);
void mostrarPila (Pila ** p);
void mostrarPersona (stPersona dato);
stPersona crearPersona ();



int main()
{

    Pila pilita;
    inicPila(&pilita);

    apilar(&pilita,crearTope(crearPersona()));
    apilar(&pilita,crearTope(crearPersona()));
    apilar(&pilita,crearTope(crearPersona()));


    Pila aux;
    inicPila(&aux);

    apilar(&aux,desapilar())



    return 0;
}

void inicPila (Pila ** p)
{
    (*p) = NULL;
}

Pila * crearTope (stPersona dato)
{
    Pila * tope = (Pila*) malloc(sizeof(Pila));

    tope->datoPersona = dato;
    tope->anterior = NULL;

    return tope;
}

void apilar (Pila ** p, Pila* tope)
{
    if ((*p) == NULL)
    {
        (*p) = tope;
    }
    else
    {
        tope->anterior = (*p);
        (*p) = tope;
    }
}

stPersona desapilar (Pila **p)
{
    stPersona exTope;
    Pila * eliminar = (*p);
    Pila * nuevoTope = (*p)->anterior;

    (*p) = nuevoTope;

    exTope = eliminar->datoPersona;

    free(eliminar);

    return exTope;
}

int pilaVacia (Pila ** p)
{
    return (*p) == NULL ? 1 : 0;
 }

void mostrarPila (Pila ** p)
{
   Pila * aux = (*p);

   if (aux != NULL)
   {
       printf("\n\nTOPE --------- TOPE\n");
       while (aux != NULL)
       {
           mostrarPersona(aux->datoPersona);
           puts("");
           aux = aux->anterior;
       }

       printf("\nBASE --------- BASE");
   }
}

void mostrarPersona (stPersona dato)
{
    printf("\nNombre: %s", dato.nombre);
    printf("\nEdad: %d",dato.edad);
}

stPersona crearPersona ()
{
    stPersona dato;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(dato.nombre);

    printf("\nIngrese edad: ");
    fflush(stdin);
    scanf("%d",&dato.edad);

    return dato;
}
