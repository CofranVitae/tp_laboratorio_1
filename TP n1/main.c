#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numero1;
    float numero2;
    int flag1 = 0;//Permite saber si el primer operando fue ingresado
    int flag2 = 0;//Permite saber si el segundo operando fue ingresado
    int flag3 = 0;//Permite saber si ya se calcularon los resultados

    float sumaRes;
    float restaRes;
    float divisionRes;
    float multiplicacionRes;
    long long int factorialA;
    long long int factorialB;

    int menu;

    do
    {
        printf("\n-------------MENU--------------");

        if(flag1 == 0)//Si todavia no se ingreso
        {
            printf("\n1-Igresar primer operando (A=x)");
        }
        else//Si ya se ingreso se muetsra el numero
        {
            printf("\n1-Igresar primer operando (A=%f)", numero1);
        }

        if(flag2 == 0)//Si todavia no se ingreso
        {
            printf("\n2-Ingresar el segundo operando (B=y)");
        }
        else//Si ya se ingreso se muetsra el numero
        {
            printf("\n2-Ingresar el segundo operando (B=%f)", numero2);
        }

        printf("\n3-Calcular las operaciones");
        printf("\n4-Mostrar el resultado");
        printf("\n5-Salir");

        menu = getInt("\nIngrese una opcion del menu: ");

        switch(menu)
        {
        case 1:

            numero1 = getFloat("\nIngresa un numero: ", "\nError, ingresa un dato numerico: ");
            flag1 = 1;
            flag3 = 0;
            break;

        case 2:

            numero2 = getFloat("\nIngresa un numero: ", "\nError, ingresa un dato numerico: ");
            flag2 = 1;
            flag3 = 0;
            break;

        case 3:

            if(flag1 == 1 && flag2 == 1)//Se calcula solo si se ingresaron los dos operandos
            {
                sumaRes=suma(numero1, numero2);

                restaRes=resta(numero1, numero2);

                divisionRes=division(numero1, numero2);

                multiplicacionRes=multiplicacion(numero1, numero2);

                factorialA=factorial(numero1);

                factorialB=factorial(numero2);

                printf("\nSe calcularon las siguientes operaciones: ");
                printf("\na-Suma (%f+%f)", numero1, numero2);
                printf("\nb-Resta (%f-%f)", numero1, numero2);
                printf("\nc-Multiplicacion (%f*%f)", numero1, numero2);
                printf("\nd-Division (%f/%f)", numero1, numero2);
                printf("\ne-Factorial(%f!, %f!)", numero1, numero2);

                flag3 = 1;
            }
            else//Error en caso de que los operandos no fueran ingresados
            {
                printf("\nPor favor, primero ingrese los dos operandos\n");
            }

            break;

        case 4:

            if(flag1 == 1 && flag2 == 1 && flag3 == 1)//Si se ingresaron los dos operandos y se calcularon las operaciones se ejecuta
            {
                printf("\nLos resultados de las operaciones fueron: ");
                printf("\na-Suma = %f", sumaRes);
                printf("\nb-Resta = %f", restaRes);
                printf("\nc-Multiplicacion = %f", multiplicacionRes);

                if(numero2 != 0)
                {
                    printf("\nd-Division = %f", divisionRes);
                }
                else
                {
                    printf("\nd-No se puede dividir por 0");
                }


                /*
                si la funcion factorial no opero y devolvio 0, aca lo evalua
                y muestra los mensajes correspondientes.
                */
                if(factorialA != 0 && numero1 < 21)
                {
                    printf("\ne-El factorial de A es: %lld", factorialA);
                }
                else//Si la funcion devolvio 0 o el resultado supera el limite de la memoria, se muestra el error
                {
                    printf("\ne-Error, el operando A no es un numero natural o es demasiado grande (limite 20)");
                }

                if(factorialB != 0 && numero2 < 21)
                {
                    printf("\ne-El factorial de B es: %lld\n", factorialB);
                }
                else
                {
                    printf("\ne-Error, el operando B no es un numero natural o es demasiado grande (limite 20)\n");
                }

            }
            else//Error en caso de no haber ingresado los operandos o no haber operado
            {
                printf("\nPor favor, primero ingrese los dos operandos y lleve a cabo las operaciones\n");
            }

            break;

        case 5 :

            printf("\nEl programa va a cerrarse.\n");
            break;

        default:

            printf("\nError, ingrese una opcion valida: \n");
            break;

        }

        system("\npause");
        system("cls");

    }
    while(menu != 5);

    return 0;
}
