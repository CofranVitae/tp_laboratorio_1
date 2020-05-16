#include "ArrayEmployes.h"

int main()
{
    Employee lista[LENEMPLOYEES];
    int retornoFuncion;
    int id = 0;
    int opcion;

    //hardcodearEmployees(lista);
    initEmployees(lista, LENEMPLOYEES);

    do
    {
        menu(&opcion);

        switch(opcion)
        {
        case 1:
            retornoFuncion = altaEmpleado(lista, LENEMPLOYEES, &id);
            if(retornoFuncion == -1)
            {
                printf("\nNo hay mas espacio");
            }
            else if(retornoFuncion == 1)
            {
                printf("\nSe cancelo la operacion");
            }
            else
            {
                printf("\nAlta exitosa");
            }
            break;
        case 2:
            if(buscarLleno(lista, LENEMPLOYEES) == 0)
            {
                retornoFuncion = modificarEmpleado(lista, LENEMPLOYEES);
                if(retornoFuncion == -1)
                {
                    printf("\nNo se encontro el empleado");
                }
                else if(retornoFuncion == 1)
                {
                    printf("\nSe cancelo la operacion");
                }
                else
                {
                    printf("\nModificacion exitosa");
                }
            }
            else
            {
                printf("\nLa lista esta vacia");
            }
            break;
        case 3:
            if(buscarLleno(lista, LENEMPLOYEES) == 0)
            {
                retornoFuncion = bajaEmpleado(lista, LENEMPLOYEES);
                if(retornoFuncion == -1)
                {
                    printf("\nNo se encontro el empleado");
                }
                else if(retornoFuncion == 1)
                {
                    printf("\nse cancelo la operacion");
                }
                else
                {
                    printf("\nBaja exitosa");
                }
            }
            else
            {
                printf("\nLa lista esta vacia");
            }
            break;
        case 4:
            if(buscarLleno(lista, LENEMPLOYEES) == 0)
            {
                printEmployees(lista, LENEMPLOYEES);
                informeSalarios(lista, LENEMPLOYEES);
            }
            else
            {
                printf("\nLa lista esta vacia");
            }
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(opcion != 5);
    return 0;
}
