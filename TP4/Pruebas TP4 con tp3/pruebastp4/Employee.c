#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "input.h"


Employee* employee_new(void)
{
    return (Employee*)malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}
/*****************************************************/
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    char caracter[1];

    if(this != NULL && nombre != NULL && sonLetrasNumeros(nombre))
    {
        strlwr(nombre);
        caracter[0] = nombre[0];
        strupr(caracter);
        nombre[0] = caracter[0];//Para que la primer letra este en mayuscula y el resto en minuscula

        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

/*****************************************************/

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/*****************************************************/
int employee_setSueldoTxt(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL && esNumero(sueldo))
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldoTxt(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        sprintf(sueldo, "%d", this->sueldo);
        retorno = 0;
    }
    return retorno;
}
/*****************************************************/
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
/*********************************************/
int employee_setIdTxt(Employee* this,char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && esNumero(id))
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int employee_getIdTxt(Employee* this,char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->id);
        retorno = 0;
    }
    return retorno;
}
/*****************************************************/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajdas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}
/*****************************************************/
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && esNumero(horasTrabajadas))
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajdas)
{
    int retorno = -1;
    if(this != NULL)
    {
        sprintf(horasTrabajdas, "%d", this->horasTrabajadas);
        retorno = 0;
    }
    return retorno;

}
/*****************************************************/
int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo)
{
    int retorno = -1;

    if(!employee_setId(this, id) &&
        !employee_setNombre(this, nombre) &&
        !employee_setHorasTrabajadas(this, horasTrabajadas) &&
        !employee_setSueldo(this, sueldo))
    {
        retorno = 0;
    }
    return retorno;
}
int employee_setAllTxt(Employee* this, char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    int retorno = -1;

    if(!employee_setIdTxt(this, id) &&
        !employee_setNombre(this, nombre) &&
        !employee_setHorasTrabajadasTxt(this, horasTrabajadas) &&
        !employee_setSueldoTxt(this, sueldo))
    {
        retorno = 0;
    }
    return retorno;
}
int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo)
{

    employee_getId(this, id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, horasTrabajadas);
    employee_getSueldo(this, sueldo);

    return 0;
}
/*****************************************************/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empleado = malloc(sizeof(Employee));

    if(employee_setAllTxt(empleado, idStr, nombreStr, horasTrabajadasStr, sueldoStr) == -1)
    {
        empleado = NULL;
    }

    return empleado;
}

Employee* employee_newParametrosInt(int id, char* nombre, int horasTrabajadas, int sueldo)
{
    Employee* empleado = malloc(sizeof(Employee));
    if(employee_setAll(empleado, id, nombre, horasTrabajadas, sueldo) == -1)
    {
        empleado = NULL;
    }
    return empleado;
}



int employee_CompareByName(void* e1, void* e2)
{
    int retorno = -1;
    char nombre1[50];
    char nombre2[50];

    if(e1 != NULL && e2 != NULL)
    {
        employee_getNombre((Employee*)e1, nombre1);
        employee_getNombre((Employee*)e2, nombre2);

        if(stricmp(nombre1, nombre2) > 0)
        {
            retorno = 1;
        }
        else if(stricmp(nombre1, nombre2) < 0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
    int retorno = -1;
    int id1;
    int id2;

    if(e1 != NULL && e2 != NULL)
    {
        employee_getId((Employee*)e1, &id1);
        employee_getId((Employee*)e2, &id2);

        if(id1 > id2)
        {
            retorno = 1;
        }
        else if(id1 < id2)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }

    }
    return retorno;
}
void employee_MostrarEmployee(Employee* this)
{
    int id;
    char nombre[129];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL)
    {
        employee_getId(this, &id);
        employee_getNombre(this, nombre);
        employee_getHorasTrabajadas(this, &horasTrabajadas);
        employee_getSueldo(this, &sueldo);

        printf("\n%4d|\t %14s|\t%8d|\t%7d|", id, nombre, horasTrabajadas, sueldo);
    }
}
