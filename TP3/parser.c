#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int** id)
{
    int retorno;
    int r;
    int i = -1;
    int idIncremento = 1;
    char idtxt[10];
    char nombre[129];
    char horasTrabajadas[10];
    char sueldo[20];
    Employee* auxCarga;


    ll_clear(pArrayListEmployee);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idtxt, nombre, horasTrabajadas, sueldo);
        if(i >= 0 && r == 4)
        {
            auxCarga = employee_newParametros(idtxt, nombre, horasTrabajadas, sueldo);
            if(auxCarga != NULL)
            {
                ll_add(pArrayListEmployee, auxCarga);
                idIncremento++;
            }
            else
            {
                i = -1;
                break;
            }
        }
        else if(r != 4)
        {
            idIncremento = 1;
            ll_clear(pArrayListEmployee);
            i = -1;
            break;
        }
        i++;
    }
    **id = idIncremento;
    retorno = i;
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int** id)
{
    int retorno = -1;
    int flag;
    int idIncremento = 1;//creo un contador de id
    Employee* auxCarga;

    ll_clear(pArrayListEmployee);

    while(!feof(pFile))
    {
        retorno = 0;
        idIncremento++;//lo sumo por cada alta

        auxCarga = employee_new();

        flag = fread(auxCarga, sizeof(Employee), 1, pFile);

        if(flag == 1)
        {
            ll_add(pArrayListEmployee, auxCarga);
        }
    }

    **id = idIncremento - 1;//Lo asigno al id autoincrementable para que las proximas altas continuen desde donde corresponde
    return retorno;
}
