#include <stdio.h>
#include <stdlib.h>

int darFactorial (int num);
int darPotencia (int base, int exponente);
void mostrarArreglo (int arreglo[], int validos, int i);
void mostrarArregloInverso(int arreglo[],int validos, int i);
int esCapicua (int arreglo[], int validos, int i);
int darSumaArreglo (int arreglo[], int validos, int i);


void cargarArchivo (char archivoInt[], int arreglo[], int validos);
int menorArchivoSubPrograma (char archivoInt[], int arreglo[], int validos);
int menorArchivo (FILE *archivo, int arreglo[], int validos, int i);


int main()
{

    int arreglo[] = {1,2,3,4,5};
    char archivo[] = "archivo.dat";

    printf("\n\nFactorial de 4 es: %d",darFactorial(4));
    printf("\n\nNumero 4 al cuadrado es: %d",darPotencia(5,2));
    printf("\n\nMostrar arreglo: ");
    mostrarArreglo(arreglo,5,0);
    printf("\n\nMostrar arreglo inverso: ");
    mostrarArregloInverso(arreglo,5,0);

    int arregloCapicua[] = {5,4,3,4,5};
    if (esCapicua(arregloCapicua,5,0) == 1)
    {
        printf("\nEs capicua");
    }
    else
    {
        printf("\nNo es capicua.");
    }

    // 1,2,3,4,5
    printf("\nLa suma del arreglo es: %d",darSumaArreglo(arreglo,5,0));

//    printf("\n\nArchivo: ");
//    cargarArchivo(archivo,arreglo,5);
//    printf("\nMenor elemento en archivo: %d", menorArchivoSubPrograma(archivo,arreglo,5));

    printf("\nMenor arreglo: %d",darMenorArreglo(arreglo,5,0));







    printf("\n\n");
    return 0;
}

int darFactorial (int num)
{
    int factorial;
    if (num == 0)
    {
        factorial = 1;
    }
    else
    {
        factorial = num * darFactorial(num-1);
    }

    return factorial;
}

int darPotencia (int base, int exponente)
{
    int resultado;

    if (exponente == 0)
    {
        resultado = 1;
    }
    else
    {

        resultado = base * darPotencia(base,exponente-1);
    }

    return resultado;
}

void mostrarArreglo (int arreglo[], int validos, int i)
{
    if (i<validos-1)
    {
        printf("\nPosicion %d - Valor %d", i,arreglo[i]);
        mostrarArreglo(arreglo,validos,++i);
    }
    else
    {
        printf("\nPosicion %d - Valor %d", i,arreglo[i]);
    }
}

void mostrarArregloInverso(int arreglo[],int validos, int i)
{
    if (i<validos)
    {
        printf("\nPosicion %d - Valor %d", validos,arreglo[--validos]);
        mostrarArregloInverso(arreglo,validos,i);
    }
}


int esCapicua (int arreglo[], int validos, int i)
{
    int respuesta = 1;

    if (i < validos-1)
    {
        if (arreglo[i] == arreglo[validos-1])
        {
            respuesta = esCapicua(arreglo,validos-1,i+1);
        }
        else
            respuesta = 0;
    }


    return respuesta;
}


int darSumaArreglo (int arreglo[], int validos, int i)
{
    int respuesta;

    if (i<validos)
    {
        respuesta = arreglo[i] + darSumaArreglo(arreglo,validos,i+1);
    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

int darMenorArreglo (int arreglo[], int validos, int i)
{
    int menorElemento;

    if (i<validos-1)
    {
        if (arreglo[i] < menorElemento)
        {
            menorElemento = arreglo[i];
        }
        else
        {
            menorElemento = darMenorArreglo(arreglo,validos,i+1);
        }
    }

    return menorElemento;



}

void cargarArchivo (char archivoInt[], int arreglo[], int validos)
{
    FILE *archivo = fopen(archivoInt,"wb");
    if (archivo != NULL)
    {
        for (int i = 0; i<validos; i++)
        {
            fwrite(&arreglo[i],sizeof(int),1,archivo);
        }

        fclose(archivo);
    }
    else
        printf("Error");
}

int menorArchivoSubPrograma (char archivoInt[], int arreglo[], int validos)
{
    FILE *archivo = fopen(archivoInt,"rb");
    int menorElemento;

    if (archivo != NULL)
    {
        menorElemento = menorArchivo(archivo,arreglo,validos,0);

        fclose(archivo);
    }
    else
        printf("Error");

}

int menorArchivo (FILE *archivo, int arreglo[], int validos, int i)
{
    int menorElemento;
    if (archivo != NULL)
    {
        if (fread(&arreglo[i],sizeof(int),1,archivo) > 0)
        {
            printf("\nakdas");


            if (i < validos)
            {


                menorElemento = menorArchivo(archivo,arreglo[i],validos,i);


            }

        }

    }
    else
        printf("Error");

    return menorElemento;
}







