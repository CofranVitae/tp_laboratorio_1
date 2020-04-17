#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float getFloat(char mensaje[], char mensajeError[])
{
    float aux;
    int i = 0;

    printf("%s", mensaje);
    fflush(stdin);

    while(i == 0)
    {
        if(scanf("\n%f", &aux) == 1)
        {

            break;
        }
        else
        {
            fflush(stdin);
            printf("%s", mensajeError);
        }
    }
    return aux;
}


int getInt(char mensaje[])
{
    int carga;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &carga);

    return carga;
}


float suma(float numeroUno, float numeroDos)
{
    float resultado = numeroUno + numeroDos;

    return resultado;
}


float resta(float numeroUno, float numeroDos)
{
    float resultado = numeroUno - numeroDos;

    return resultado;
}

float division(float numeroUno, float numeroDos)
{
    float resultado = numeroUno / numeroDos;

    return resultado;
}

float multiplicacion(float numeroUno, float numeroDos)
{
    float resultado = numeroUno * numeroDos;

    return resultado;
}

long long int factorial(float numero)
{
    int i;
    int flag;

    flag = validarNatural(numero);


    if(flag == 1 && (numero == 1 || numero == 0)) //Si es 1 || 0 se le asigna valor 1 a numero
    {
        numero = 1;
    }

    else if(flag == 0) //Si no era natural o 0, se le asigna 0
    {
        numero = 0;
    }
    else //Si es natural > 1 calcula el factorial y se le asigna el resultado
    {
        for(i = numero - 1 ; i>=1 ; i--)
        {
            numero *= i;
        }

    }

    return numero;
}

int validarNatural(float numero)
{
    int retorno = 1;
    int numeroEntero;

    numeroEntero = numero;
    if(numero < 0 || numero - numeroEntero != 0)
    {
        retorno = 0;//Si no es natural devuelve 0
    }

    return retorno;//Si era natural o 0, devuelve 1
}




