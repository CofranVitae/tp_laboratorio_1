#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    int opcion;
    int ret;
    int idAutoincremental = 1;


    do
    {
        printf("\t\t\t\t-----MENU-----\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
     "\n3. Alta de empleado"
     "\n4. Modificar datos de empleado"
     "\n5. Baja de empleado"
     "\n6. Listar empleados"
     "\n7. Ordenar empleados"
     "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
     "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
    "\n10. Salir"
    "\nIngrese opcion: ");

    scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            ret = controller_loadFromText("data.csv", listaEmpleados, &idAutoincremental);
            if(ret == -1)
            {
                printf("\nError leyendo el archivo");
            }
            else if(ret == -2)
            {
                printf("\nSe cancelo la carga");
            }
            else
            {
                printf("\nSe cargo correctamente");
            }
            break;
        case 2:
            ret = controller_loadFromBinary("data.bin", listaEmpleados, &idAutoincremental);
            if(ret == -1)
            {
                printf("\nError leyendo el archivo");
            }
            else if(ret == 0)
            {
                printf("\nSe cargo correctamente");
            }
            else
            {
                printf("\nSe cancelo la carga");
            }
            break;
        case 3:
            ret = controller_addEmployee(listaEmpleados, &idAutoincremental);
            if(ret == 0)
            {
                printf("\nSe Agrego exitosamente");
            }
            else if(ret == -1)
            {
                printf("\nError con la lista");
            }
            else
            {
                printf("\nSe cancelo el alta");
            }
            break;
        case 4:
            ret = controller_editEmployee(listaEmpleados);
            if(ret == 0)
            {
                printf("\nSe Modifico");
            }
            else if(ret == 1)
            {
                printf("\nSe cancelo la modificacion");
            }
            else if(ret == -1)
            {
                printf("\nError con los parametros o busqueda cancelada");
            }
            else if(ret == -2)
            {
                printf("\nNo se encontro el Empleado");
            }
            break;
        case 5:
            ret = controller_removeEmployee(listaEmpleados);
            if(ret == 0)
            {
                printf("\nSe elimino");
            }
            else if(ret == -2)
            {
                printf("\nNo se encontro");
            }
            else
            {
                printf("\nSe cancelo la operacion o se produjo un error");
            }
            break;
        case 6:
            ret = controller_ListEmployee(listaEmpleados);//Agregar mensajes de error
            if(ret == -1)
            {
                printf("\nLa lista no existe o esta vacia");
            }
            break;
        case 7:
            ret = controller_sortEmployee(listaEmpleados);
            if(ret == 0)
            {
                printf("\nSe ordeno");
            }
            else if(ret == 1)
            {
                printf("\nError, no se eligio una opcion valida");
            }
            else
            {
                printf("\nError, no se pudo ordenar");
            }
            break;
        case 8:
            ret = controller_saveAsText("data.csv", listaEmpleados);
            if(ret == -1)
            {
                printf("\nError guardando el archivo");
            }
            else
            {
                printf("\nSe guardo correctamente");
            }
            break;
        case 9:
            ret = controller_saveAsBinary("data.bin", listaEmpleados);
            if(ret == -1)
            {
                printf("\nError guardando el archivo");
            }
            else
            {
                printf("\nSe guardo correctamente");
            }
            break;
        }

        printf("\n\n");
        system("pause");
        system("cls");

    }while(opcion != 10);

    return 0;
}
