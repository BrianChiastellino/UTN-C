#include <stdio.h>
#include <stdlib.h>

int darFactorial (int num);
int darPotencia (int base, int exponente);
void mostrarArreglo (int arreglo[], int validos, int i);
void mostrarArregloInverso(int arreglo[],int validos, int i);
int esCapicua (int arreglo[], int validos, int i);


int main()
{

    int arreglo[] = {1,2,3,4,5};

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
    if (i<=validos-1)
    {
        printf("\nPosicion %d - Valor %d", i,arreglo[i]);
        mostrarArreglo(arreglo,validos,++i);
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

    if (i<validos)
    {
        if (arreglo[i] == arreglo[validos])
        {
            esCapicua(arreglo,validos,++i);
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
        respuesta = arreglo[i] + darSumaArreglo(arreglo,validos,++i);
    }

    return respuesta;
}









