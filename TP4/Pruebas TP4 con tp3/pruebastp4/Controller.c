#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;//Error en la lista
    Employee* aux;
    int size;

    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
    {
        size = ll_len(pArrayListEmployee);
        if(size > 0)
        {
            retorno = 0;
            printf("\n  ID|\t\t NOMBRE|HORAS TRABAJADAS|\t SUELDO|");
            for(int i = 0; i < size; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                employee_MostrarEmployee(aux);
            }
        }

    }

    return retorno;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* id)
{
    int retorno = -1;
    FILE* pArchivo;

    if(!cancelarOperacion("\nSe sobreescribiran los datos, desea continuar con la carga? (s - n)"))
    {
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL && pArrayListEmployee != NULL)
        {
            retorno = parser_EmployeeFromText(pArchivo, pArrayListEmployee, &id);
        }

        fclose(pArchivo);
    }
    else
    {
        retorno = -2;
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* id)
{
    int retorno = -1;
    FILE* pArchivo;

    if(!cancelarOperacion("\nSe sobreescribiran los datos, desea continuar con la carga? (s - n)"))
    {
        pArchivo = fopen(path, "rb");

        if(pArchivo != NULL && pArrayListEmployee != NULL)
        {
            retorno = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee, &id);
        }
        fclose(pArchivo);
    }
    else
    {
        retorno = 1;
    }


    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    Employee* miEmpleado;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int retorno = -1;//Error en la lista

    if(pArrayListEmployee != NULL)
    {
        miEmpleado = employee_new();

        if(miEmpleado != NULL &&
                !getPalabra_Nombre(nombre, "Nombre del empleado: ", "Formato invalido", 50) &&
                !ingresarNumero(&horasTrabajadas, "Horas trabajadas del empleado (1-20): ", "No se pudo ingresar", 1, 20) &&
                !ingresarNumero(&sueldo, "Sueldo del empleado (10000-50000): ", "No se pudo igresar", 10000, 50000) &&
                !cancelarOperacion("Desea confirmar el ingreso? (s-n): "))
        {
            employee_setAll(miEmpleado, *id, nombre, horasTrabajadas, sueldo);
            *id = *id + 1;
            ll_add(pArrayListEmployee, miEmpleado);
            retorno = 0;//Bien
        }
        else
        {
            employee_delete(miEmpleado);
            retorno = 1;//Cancelo
        }
    }

    return retorno;
}
int controller_buscarEmployeePorId(LinkedList* lista)
{
    int retorno = -1;//Error de parametros
    int len;
    Employee* aux;
    int idBusqueda;
    int id;

    if(lista != NULL)
    {
        if(lista != NULL &&
                !controller_ListEmployee(lista) &&
                !ingresarNumero(&id, "id del empleado que desea Modificar/Borrar", "No se pudo igresar", 0, 50000) &&
                !cancelarOperacion("Desea confirmar el ingreso? (s-n): "))
        {
            len = ll_len(lista);
            retorno = -2;//No se encuentra el id
            for(int i = 0; i < len; i++)
            {
                aux = ll_get(lista, i);
                employee_getId(aux, &idBusqueda);

                if(aux != NULL && idBusqueda == id)
                {
                    retorno = ll_indexOf(lista, aux);//indice donde esta ese id
                    break;
                }
            }
        }
    }
    return retorno;
}

int controller_menuModificarEmpleado(Employee* aux, int id, char* nombre, int horasTrabajadas, int sueldo)
{
    int retorno = 1;//Cancelo
    int opcion;

    do
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\n--EMPLEADO QUE SE ESTA MODIFICANDO--");
        printf("\n  ID|\t\t NOMBRE|HORAS TRABAJADAS|\t SUELDO|");
        employee_MostrarEmployee(aux);

        printf("\n1-id\n2-nombre\n3-Horas Trabajadas\n4-Sueldo\n5-Salir");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(!ingresarNumero(&id, "Nuevo id", "Error", 0, 50000))
            {
                employee_setId(aux, id);
            }
            break;
        case 2:
            if(!getPalabra_Nombre(nombre, "Nuevo nombre", "Error", 50))
            {
                employee_setNombre(aux, nombre);
            }
            break;
        case 3:
            if(!ingresarNumero(&horasTrabajadas, "Nuevo horasTrabajdaas", "Error", 0, 20))
            {
                employee_setHorasTrabajadas(aux, horasTrabajadas);
            }
            break;
        case 4:
            if(!ingresarNumero(&sueldo, "Nuevo sueldo", "Error", 10000, 50000))
            {
                employee_setSueldo(aux, sueldo);
            }
            break;
        case 5:
            if(!cancelarOperacion("\nDesea confirmar la modificacion?"))
            {
                retorno = 0;//Se modifico
            }
        }
    }
    while(opcion != 5);
    return retorno;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;//Error de parametro cancelo la busqueda

    int id;
    char nombre[129];
    int horasTrabajadas;
    int sueldo;
    int index;

    Employee* miEmpleado;
    Employee* aux;

    index = controller_buscarEmployeePorId(pArrayListEmployee);
    retorno = index;

    if(index >= 0)
    {
        miEmpleado = ll_get(pArrayListEmployee, index);//SEPARAR CON UNA FUNCION MOSTRAR UNO SOLO

        if(miEmpleado != NULL)
        {
            employee_getAll(miEmpleado, &id, nombre, &horasTrabajadas, &sueldo);
            aux = employee_newParametrosInt(id, nombre, horasTrabajadas, sueldo);
            if(aux != NULL)
            {
                retorno = controller_menuModificarEmpleado(aux, id, nombre, horasTrabajadas, sueldo);
                if(retorno == 0)
                {

                    ll_set(pArrayListEmployee, index, aux);
                    employee_delete(miEmpleado);
                }
                else
                {
                    employee_delete(aux);
                }
            }

        }
    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;//No se cancelo o Error
    int index;
    Employee* miEmpleado;


    index = controller_buscarEmployeePorId(pArrayListEmployee);
    retorno = index;

    if(index >= 0 && !cancelarOperacion("\nDesea confirmar la baja?"))
    {
        miEmpleado = ll_get(pArrayListEmployee, index);

        if(miEmpleado != NULL)
        {
            employee_delete(miEmpleado);
            ll_remove(pArrayListEmployee, index);
            retorno = 0;//Bien
        }
    }
    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno;

    printf("\nORDENAMIENTO\n1- Por nombre de A - Z\n2- Por nombre de Z - A\n3- Por id de menor a mayor\n4- Por id de mayor a menor\nElija una opcion: ");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        retorno = ll_sort(pArrayListEmployee, employee_CompareByName, 1);
        break;
    case 2:
        retorno = ll_sort(pArrayListEmployee, employee_CompareByName, 0);
        break;
    case 3:
        retorno = ll_sort(pArrayListEmployee, employee_CompareById, 1);
        break;
    case 4:
        retorno = ll_sort(pArrayListEmployee, employee_CompareById, 0);
        break;
    default:
        retorno = 1;
        break;
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    Employee* miEmpleado;
    int len;

    int id;
    char nombre[129];
    int horasTrabajadas;
    int sueldo;

    pArchivo = fopen(path, "w");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i = 0; i < len; i++)
        {
            miEmpleado = ll_get(pArrayListEmployee, i);
            employee_getAll(miEmpleado, &id, nombre, &horasTrabajadas, &sueldo);

            fprintf(pArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
        }
        retorno = 0;
    }

    fclose(pArchivo);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    Employee* miEmpleado;
    int len;

    pArchivo = fopen(path, "wb");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(int i = 0; i < len; i++)
        {
            miEmpleado = ll_get(pArrayListEmployee, i);
            fwrite(miEmpleado, sizeof(Employee), 1, pArchivo);
        }
        retorno = 0;
    }

    fclose(pArchivo);
    return retorno;
}

int agregarEnIndice(LinkedList* pArrayListEmployee, int* id)
{
    Employee* miEmpleado;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int retorno = -1;//Error en la lista
    int index;

    if(pArrayListEmployee != NULL)
    {
        miEmpleado = employee_new();

        if(miEmpleado != NULL &&
                !getPalabra_Nombre(nombre, "Nombre del empleado: ", "Formato invalido", 50) &&
                !ingresarNumero(&horasTrabajadas, "Horas trabajadas del empleado (1-20): ", "No se pudo ingresar", 1, 20) &&
                !ingresarNumero(&sueldo, "Sueldo del empleado (10000-50000): ", "No se pudo igresar", 10000, 50000) &&
                !ingresarNumero(&index, "Indice a donde lo quiere agregar", "Numero invalido", 0, ll_len(pArrayListEmployee)) &&
                !cancelarOperacion("Desea confirmar el ingreso? (s-n): "))
        {
            employee_setAll(miEmpleado, *id, nombre, horasTrabajadas, sueldo);
            *id = *id + 1;
            if(!ll_push(pArrayListEmployee, index, miEmpleado))
                retorno = 0;//Bien
        }
        else
        {
            employee_delete(miEmpleado);
            retorno = 1;//Cancelo
        }
    }

    return retorno;
}
int pop(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* aux;
    int index;

    printf("Ingresa indice del empleado a remover");
    scanf("%d", &index);

    aux = ll_pop(pArrayListEmployee, index);

    if(aux != NULL)
    {
        employee_MostrarEmployee(aux);
    }
    else
    {
        printf("\nNo se encontro");
    }


}

int subList(LinkedList* lista)
{
    LinkedList* listaClonada;
    int flag;
    listaClonada = ll_subList(lista, 990, 1000);
    if(listaClonada != NULL)
    {
        controller_ListEmployee(listaClonada);
    }
    else
    {
        printf("\nNo se pudo clonar");
    }
    flag = ll_deleteLinkedList(listaClonada);
    if(flag == 0)
    {
        printf("\nSe borro");
        controller_ListEmployee(listaClonada);
    }
    else
    {
        printf("\nNo se borro");
        controller_ListEmployee(listaClonada);
    }
}
int clone(LinkedList* lista)
{
    LinkedList* listaClonada;
    int flag;
    listaClonada = ll_clone(lista);
    if(listaClonada != NULL)
    {
        controller_ListEmployee(listaClonada);
    }
    else
    {
        printf("\nNo se pudo clonar");
    }
    flag = ll_deleteLinkedList(listaClonada);
    if(flag == 0)
    {
        printf("\nSe borro");
        controller_ListEmployee(listaClonada);
    }
    else
    {
        printf("\nNo se borro");
        controller_ListEmployee(listaClonada);
    }
}
int containsall(LinkedList* lista)
{
    LinkedList* listaClonada;
    int flag;
    Employee* aux;
    listaClonada = ll_subList(lista, 990, 1000);
    controller_ListEmployee(listaClonada);
    ll_pop(listaClonada, 5);
    controller_ListEmployee(listaClonada);

    flag = ll_containsAll(lista, listaClonada);

        if(flag == 1)
        {
            printf("\nEstaba contenida");
        }
        else if(flag == 0)
        {
            printf("\nNo estaba contenida");
        }
}
