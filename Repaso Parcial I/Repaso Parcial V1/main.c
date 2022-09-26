#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

typedef struct
{
    char patente[7];
    char marca[15];
    int valor;

} stAuto;

typedef struct nodoAuto
{
    stAuto dato;
    struct nodoAuto * siguiente;

} nodoAuto;

stAuto crearAuto ();

nodoAuto * inicLista ();
nodoAuto * crearNodoSimple (stAuto datoAuto);
nodoAuto * agregarAlPrincipio (nodoAuto * lista, nodoAuto * nuevoNodo);
nodoAuto * agregarAlPrincipioV2 (nodoAuto * lista, stAuto datoAutomovil);
nodoAuto * agregarAlFinal (nodoAuto * lista, nodoAuto * nuevoNodo);
nodoAuto * obtenerUltimoNodo (nodoAuto * lista);
nodoAuto* obtenerUltimoNodoRecursivo(nodoAuto * lista);
void mostrarLista (nodoAuto * lista);
void mostrarListaRecursivo (nodoAuto * lista);
void mostrarDatosAutomovil (stAuto datoAutomovil);
stAuto crearAuto ();
nodoAuto * agregarAlFinalV2(nodoAuto * lista, stAuto datoAutomovil);

char mensajeSalida ();

void cargarArchivo (char archivo[]);
void mostrarArchivo (char archvo[]);
nodoAuto * pasarArchivoToLista (char archivo[], nodoAuto * lista);
nodoAuto * pasarArchivoToListaRecursivoSubprograma(char archivo[], nodoAuto * lista);
void pasarArchivoToListaRecursivo(FILE * archivo, nodoAuto ** lista);

nodoAuto * ordenarLista (nodoAuto * lista);
nodoAuto * obtenerMenor (nodoAuto * iterador);
nodoAuto * intercambio (nodoAuto * anterior, nodoAuto * iterador, nodoAuto * menor);

void intercambiaNodoBlas(nodoAuto ** anterior, nodoAuto ** iterador, nodoAuto ** menor);

int main()
{
    nodoAuto * lista = inicLista();
    char archivoAutos[] = "infoAutos.dat";
    lista = pasarArchivoToLista(archivoAutos,lista);

    mostrarLista(lista);

    printf("\nOrdenar: ");
    lista = ordenarLista(lista);

    mostrarLista(lista);

    return 0;
}

nodoAuto * ordenarLista (nodoAuto * lista)
{
    nodoAuto * iterador =  lista;
    nodoAuto * anterior;

    if (iterador != NULL)
    {
        while(iterador != NULL)
        {

            mostrarLista(iterador);
            anterior = iterador;
            nodoAuto * menor = obtenerMenor(iterador);
            iterador = iterador->siguiente;
            intercambioChaste(&anterior,&iterador,&menor);
        }
    }

    return iterador;
}

nodoAuto * obtenerMenor (nodoAuto * iterador)
{
    nodoAuto* menor = iterador;
    // iterador = iterador->siguiente;

    while(iterador!=NULL)
    {
        if(iterador->dato.valor <  menor->dato.valor)
        {
            menor = iterador;
        }

        iterador = iterador->siguiente;
    }

    return menor;
}

void intercambioChaste (nodoAuto ** anterior, nodoAuto ** iterador, nodoAuto ** menor)
{
    (*anterior)->siguiente = (*menor)->siguiente;    // iterador->siguiente = menor->siguiente;
    (*menor)->siguiente = (*iterador);

}

void intercambiaNodoBlas(nodoAuto ** anterior, nodoAuto ** iterador, nodoAuto ** menor)
{
    (*iterador)->siguiente = (*anterior);
    (*anterior)->siguiente = (*menor)->siguiente;
    (*anterior) = (*menor);
    (*menor)->siguiente = (*iterador);
}

void cargarArchivo (char archivo[])
{
    FILE * archiAutos = fopen(archivo,"ab");
    stAuto datoAutomovil;

    if (archiAutos != NULL)
    {
        do
        {
            datoAutomovil = crearAuto();

            fwrite(&datoAutomovil,sizeof(stAuto),1,archiAutos);

        }
        while (mensajeSalida() != 27);

        fclose(archiAutos);
    }
}

char mensajeSalida ()
{
    char salida;

    printf("\nESC para salir ENTER para seguir: ");
    fflush(stdin);
    salida = getch();

    return salida;
}

void mostrarArchivo (char archvo[])
{
    FILE * archiAutos = fopen(archvo,"rb");
    stAuto datoAutomovil;

    if (archiAutos != NULL)
    {
        while (fread(&datoAutomovil,sizeof(stAuto),1,archiAutos) > 0)
        {
            mostrarDatosAutomovil(datoAutomovil);
        }
    }
}

nodoAuto * pasarArchivoToLista (char archivo[], nodoAuto * lista)
{
    FILE * archiAutos = fopen(archivo,"rb");
    stAuto datoAutomovil;

    if (archiAutos != NULL)
    {
        while (fread(&datoAutomovil,sizeof(stAuto),1,archiAutos) > 0)
        {
            lista = agregarAlPrincipioV2(lista,datoAutomovil);
        }

        fclose(archiAutos);
    }

    return lista;
}

nodoAuto * pasarArchivoToListaRecursivoSubprograma(char archivo[], nodoAuto * lista)
{
    FILE * archiAutos = fopen(archivo,"rb");

    if (archiAutos != NULL)
    {
        pasarArchivoToListaRecursivo(archiAutos,&lista);
        fclose(archiAutos);
    }

    return lista;
}

void pasarArchivoToListaRecursivo(FILE * archivo, nodoAuto ** lista)
{
    stAuto datoAutomovil;

    if (fread(&datoAutomovil,sizeof(stAuto),1,archivo) > 0)
    {
        (*lista) = agregarAlPrincipioV2((*lista),datoAutomovil);
        pasarArchivoToListaRecursivo(archivo,lista);
    }

}



//{ Funciones principales
nodoAuto * inicLista ()
{
    return NULL;
}

stAuto crearAuto ()
{
    stAuto autoDato;

    printf("\nIngrese numero de patente: ");
    fflush(stdin);
    gets(autoDato.patente);

    printf("\nIngrese marca: ");
    fflush(stdin);
    gets(autoDato.marca);

    printf("\nIngrese valor: ");
    fflush(stdin);
    scanf("%d", &autoDato.valor);

    return autoDato;
}

nodoAuto * crearNodoSimple (stAuto datoAuto)
{
    nodoAuto * nuevo = (nodoAuto*) malloc(sizeof(nodoAuto));

    nuevo->dato = datoAuto;
    nuevo->siguiente = inicLista();

    return nuevo;
}

nodoAuto * agregarAlPrincipio (nodoAuto * lista, nodoAuto * nuevoNodo)
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

    return lista;
}

nodoAuto * agregarAlPrincipioV2 (nodoAuto * lista, stAuto datoAutomovil)
{
    if (lista == NULL)
    {
        lista = crearNodoSimple(datoAutomovil);
    }
    else
    {
        nodoAuto * nuevo = crearNodoSimple(datoAutomovil);
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

nodoAuto * agregarAlFinal (nodoAuto * lista, nodoAuto * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoAuto * ultimo = obtenerUltimoNodo(lista);
        ultimo->siguiente = nuevoNodo;
    }

    return lista;
}

nodoAuto * agregarAlFinalV2(nodoAuto * lista, stAuto datoAutomovil)
{
    if (lista == NULL)
    {
        lista = crearNodoSimple(datoAutomovil);
    }
    else
    {
        nodoAuto * ultimo = obtenerUltimoNodo(lista);
        ultimo->siguiente = crearNodoSimple(datoAutomovil);
    }

    return lista;
}

nodoAuto * obtenerUltimoNodo (nodoAuto * lista)
{
    nodoAuto * ultimo = lista;

    while (ultimo->siguiente != NULL)
    {
        ultimo = ultimo->siguiente;
    }

    return ultimo;
}

nodoAuto* obtenerUltimoNodoRecursivo(nodoAuto * lista)
{
    if (lista->siguiente != NULL)
    {
        lista = obtenerUltimoNodoRecursivo(lista->siguiente);
    }

    return lista;
}

void mostrarLista (nodoAuto * lista)
{
    nodoAuto * iterador = lista;

    if (iterador != NULL)
    {
        printf("\nPRIMER NODO --------- ");
        while (iterador != NULL)
        {
            mostrarDatosAutomovil(iterador->dato);
            iterador = iterador->siguiente;
        }

        printf("\nULTIMO NODO --------- ");
    }
}

void mostrarListaRecursivo (nodoAuto * lista)
{
    if (lista != NULL)
    {
        mostrarDatosAutomovil(lista->dato);
        mostrarListaRecursivo(lista->siguiente);
    }
}
void mostrarDatosAutomovil (stAuto datoAutomovil)
{
    printf("\nPatente ----- %s", datoAutomovil.patente);
    printf("\nMarca ----- %s", datoAutomovil.marca);
    printf("\nValor ---- %d\n\n",datoAutomovil.valor);
}
//}



/**
//{ algoritmosValidarPatente

void validarPatenteSubPrograma(char patente[])
{
    int patenteCorrecta;

    do
    {
        patenteCorrecta = validarPatente(patente);

        printf("\nPatente correcta = %d", patenteCorrecta);

        if (patenteCorrecta == 0)
        {
            printf("\nIngrese nuevamente la patente del vehiculo: ");
            fflush(stdin);
            gets(patente);
        }


    } while (patenteCorrecta == 0);


}

int validarLargoPatente (char patente[])
{
    int patenteCorrecta = 0;

    if (strlen(patente) == 6)
        patenteCorrecta = 1;

    return patenteCorrecta;
}

int validarLetraPatente (char patente[])
{
    int patenteCorrecta = 1;
    int i = 0;

    while (i < 3 && patenteCorrecta == 1)
    {
        if (patente[i] < 'A' || patente[i] > 'Z')
            patenteCorrecta = 0;

        i++;
    }

    return patenteCorrecta;
}

int validarNumeracionPatente (char patente[]) // usra funcion strtol
{
    int patenteCorrecta = 1;
    int i = 3;

    while (i < 6 && patenteCorrecta == 1)
    {
        if (patente[i] < 0 && patente[i] > 9)
            patenteCorrecta = 0;

        i++;
    }

    return patenteCorrecta;
}

int validarPatente (char patente[])
{
    int patenteCorrecta = 0;
    int largoPatente;
    int letraPatente;
    int numeracionPatente;

    transformarPalabraMayucula(patente);

    largoPatente = validarLargoPatente(patente);
    letraPatente = validarLetraPatente(patente);
    numeracionPatente = validarNumeracionPatente(patente);

    printf("\nlargo: %d", largoPatente);
    printf("\nl: %d", letraPatente);
    printf("\nn: %d", numeracionPatente);

    if (largoPatente == 1 && letraPatente == 1 && numeracionPatente == 1)
        patenteCorrecta = 1;


    return patenteCorrecta;

}

void transformarPalabraMayucula (char palabra[])
{
    for (int i = 0; i<strlen(palabra);i++)
    {
        palabra[i] = toupper(palabra[i]);
    }
}

//}
**/










