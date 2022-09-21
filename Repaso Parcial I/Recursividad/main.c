#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void ejercicio1 ()
{
    int valor;
    int respuestaFactorial;

    printf("\nIngrese valor para buscar su factorial ");
    scanf("%d",&valor);

    respuestaFactorial = factorialNumero(valor);

    printf("\nResultado: %d", respuestaFactorial);

}

void ejercicio2 ()
{
    int valorBase;
    int valorExponente;
    int respuestaPotencia;

    printf("\nIngrese base ");
    scanf("%d",&valorBase);

    printf("\nIngrese exponente: ");
    scanf("%d", &valorExponente);

    respuestaPotencia = potenciaNumero(valorBase,valorExponente);

    printf("\nResultado: %d", respuestaPotencia);
}

void ejercicio3 ()
{
    int arreglo [] = {1,2,3,4,5,6};
    int validos = 6;

    mostrarArreglo(arreglo,validos,0);
}

void ejercicio4_v1 ()
{
    int arreglo [] = {1,2,3,4,5,10,6};
    int validos = 7;

    mostrarArregloInvertido_V1 (arreglo,validos,0);
}

void ejercicio4_v2()
{
    int arreglo [] = {3,4,6,1,2,10};
    int validos = 6;

    mostrarArregloInvertido_V2(arreglo,validos,0);
}

void ejercicio5 ()
{
    int arregloCapicua[] = {1,2,3,5,3,2,1};
    int arregloNoCapicua [] = {1,2,3,4,5,6,8};
    int validosCapicua = 7;
    int respuesta;

    respuesta = esCapicua(arregloCapicua,validosCapicua,0);
    //respuesta = esCapicua(arregloNoCapicua,validosCapicua,0);

    if (respuesta == 1)
        printf("\nEs capicua ");
    else
        printf("\nNo es capicua ");

}

void ejercicio6 ()
{
    int arreglo[] = {10,10,10,10,10,50};
    int validosArreglo = 6;
    int totalSumaArreglo;

    totalSumaArreglo = sumaArreglo(arreglo,validosArreglo,0);

    printf("\nSuma total: %d",totalSumaArreglo);
}

void ejercicio7()
{
    int arreglo[] = {3,4,5,6,2,3,4};
    int validos = 7;
    int menorValor;

    menorValor = menorElementoArreglo(arreglo,validos,0);

    printf("\nMenor elemento: %d", menorValor);
}

int main()
{

    ejercicio8();



    return 0;
}

void ejercicio8()
{
    char archivoInt[]  = "archivo.dat";
    int arreglo[] = {-30,5,3,21,3,-22,-2,-10};
    int validos = 8;
    int menorValor;

    cargarArchivoDeArreglo(archivoInt,arreglo,validos);
    mostrarArchivo(archivoInt);

    menorValor = darMenorDatoEnArchivoSubPrograma(archivoInt);

    printf("\nMenor valor en archivo: %d",menorValor);

}




int factorialNumero (int numero)
{
    int respuesta;

    if (numero == 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = numero * factorialNumero(numero-1);
    }


    return respuesta;

}

int potenciaNumero (int base, int exponente)
{
    int respuesta;

    if (exponente == 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = base * potenciaNumero(base,exponente-1);
    }

    return respuesta;
}

void mostrarArreglo (int arreglo[], int validos, int i)
{
    if (i<validos)
    {
        printf(" %d ", arreglo[i]);
        mostrarArreglo(arreglo,validos,i+1);
    }
}

void mostrarArregloInvertido_V2 (int arreglo[], int validos, int i)
{
    if (i<validos)
    {
        printf(" %d ", arreglo[validos-1]);
        mostrarArregloInvertido_V2(arreglo,validos-1,i);
    }
}

void mostrarArregloInvertido_V1(int arreglo[], int validos, int i)
{
    if (i<validos)
    {
        mostrarArregloInvertido_V1(arreglo,validos,i+1);
        printf(" %d ", arreglo[i]);
    }
}

int esCapicua (int arreglo[], int validos, int i)
{
    int respuestaCapicua = 1;

    if (i<validos-1)
    {
        if (arreglo[i] == arreglo[validos-1])
        {
            respuestaCapicua = esCapicua(arreglo,validos-1,i+1);
        }
        else
        {
            respuestaCapicua = 0;
        }

    }

    return respuestaCapicua;
}

int sumaArreglo (int arreglo[], int validos, int i)
{
    int sumaTotal = 0;

    if (i<validos)
    {
        sumaTotal = arreglo[i] + sumaArreglo(arreglo,validos,i+1);
    }

    return sumaTotal;
}

int menorElementoArreglo (int arreglo[], int validos, int i)
{
    int menor;

    if (i<validos)
    {
        menor = arreglo[i];
        menor = menorElementoArreglo(arreglo,validos,i+1);
    }
    else
    {
        menor = arreglo[i];
    }


    if (arreglo[i] < menor)
    {
        menor = arreglo[i];
    }

    return menor;
}

void cargarArchivoDeArreglo (char archivo[], int arreglo[], int validos)
{
    FILE * archi = fopen(archivo,"wb");

    if (archi != NULL)
    {
        fwrite(arreglo,sizeof(int),validos,archi);

        fclose(archi);
    }

}

void mostrarArchivo (char archivo[])
{
    FILE *archi = fopen(archivo,"rb");
    int dato;

    if (archi != NULL)
    {
        while(fread(&dato,sizeof(int),1,archi) > 0)
        {
            mostrarEntero(dato);
        }

        fclose(archi);
    }
}

void mostrarEntero (int dato)
{
    printf("\nDato: %d", dato);
}

int darMenorDatoEnArchivoSubPrograma (char archivoInt[])
{
    FILE * archi = fopen(archivoInt, "r+b");
    int menor;
    int validosArchivo;

    if (archi != NULL)
    {

        validosArchivo = darValidosArchivo(archi);

        menor = buscarMenorArchivo(archi,validosArchivo,0);

        fclose(archi);
    }

    printf("\nValidos arc %d",validosArchivo);

    return menor;
}


int buscarMenorArchivo(FILE * archivo, int validos, int i)
{
    int datoMenor;
    int dato;

    if (i<validos-1)
    {
        dato = retornarEnteroDesdeArchivo(archivo,i);
        datoMenor = dato;

        datoMenor = buscarMenorArchivo(archivo,validos,i+1);
    }
    else
    {
        dato = retornarEnteroDesdeArchivo(archivo,i);
        datoMenor = dato;
    }

    dato = retornarEnteroDesdeArchivo(archivo,i);

    if (dato < datoMenor)
    {
        datoMenor = dato;
    }

    return datoMenor;
}

int retornarEnteroDesdeArchivo (FILE * archivo, int pos)
{
    int datoMenor;

    if (pos == 0)
    {
        fseek(archivo,0,SEEK_SET);
        fread(&datoMenor,sizeof(int),1,archivo);
    }
    else
    {
        fseek(archivo,sizeof(int)*(pos),SEEK_SET);

        fread(&datoMenor,sizeof(int),1,archivo);
    }

    return datoMenor;
}

int darValidosArchivo (FILE * archivo)
{
    int validos;

    rewind(archivo);

    fseek(archivo,0,SEEK_END);

    validos = ftell(archivo) / sizeof(int);

    return validos;
}



