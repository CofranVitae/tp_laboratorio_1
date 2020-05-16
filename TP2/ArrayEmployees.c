#include "ArrayEmployes.h"

int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    if(list != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = EMPTY;
            retorno = 0;
        }
    }
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno = -1;
    if(list != NULL)
    {
        retorno = 1;
        if(cancelarOperacion("\nConfirmar ingreso s(si), n(no)") == 0)
        {
            list->id = id;
            strcpy(list->name, name);
            strcpy(list->lastName, lastName);
            list->salary = salary;
            list->sector = sector;
            list->isEmpty = FULL;
            retorno = 0;
        }
    }


    return retorno;
}

int printEmployees(Employee* list, int len)
{
    sortEmployees(list, len, 1);
    printf("\n\t APELLIDO|\tNOMBRE| \t SALARIO| \tSECTOR| \tID|");
    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == FULL)
        {
            mostrarempleado(list[i]);
        }
    }
    return 0;
}


int findEmployeeById(Employee* list, int len, int id)
{
    int retorno = -1;
    if(list != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FULL && list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;
    int indice;
    if(list != NULL)
    {
        indice = findEmployeeById(list, len, id);
        if(indice != -1)
        {
            if(cancelarOperacion("\nConfirmar ingreso s(si), n(no)") == 0)
            {
                list[indice].isEmpty = EMPTY;
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno = -1;
    if(list != NULL)
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {

                if(order == 1)
                {
                    if(stricmp(list[i].lastName, list[j].lastName) > 0 ||
                            (stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
                    {
                        ordenar(&list[i], &list[j]);
                    }
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0 ||
                            (stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
                    {
                        ordenar(&list[i], &list[j]);
                    }
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int menu(int* opcion)
{
    printf("\nMenu\n1-Aniadir empleado\n2-Modificar Empleado\n3-Borrar empleado\n4-Informar\n5-Salir");
    printf("\nSeleccione opcion: ");
    scanf("%d", opcion);
    return  0;
}
int menuModificacion(int* opcion)
{
    printf("\nMenu de Modificacion\n1-Modificar nombre\n2-Modificar Apellido\n3-Modificar Salario\n4-Modificar Secto\n5-Salir");
    printf("\nSeleccione opcion: ");
    scanf("%d", opcion);
    return  0;
}
void hardcodearEmployees(Employee* lista)
{
    int id[5]= {1, 2, 3, 4, 5};
    char name[5][51]= {"franco", "pepe", "jose", "agustin", "esteban"};
    char lastName[5][51]= {"Sagnella", "Sagnella", "Avila", "Sanchez", "Carena"};
    float salary[5]= {30, 33, 22, 23, 56};
    int sector[5]= {1, 2, 4, 1, 1};
    int isEmpty[5]= {1, 1, 1, 1, 1};

    for(int i = 0; i < LENEMPLOYEES; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].name, name[i]);
        strcpy(lista[i].lastName, lastName[i]);
        lista[i].salary = salary[i];
        lista[i].sector = sector[i];
        lista[i].isEmpty = isEmpty[i];
    }
}
int altaEmpleado(Employee* lista, int len, int *id)
{
    int retorno = -1;
    int indice;
    Employee auxCarga;

    indice = buscarLibre(lista, len);
    if(indice != -1)
    {
        if(cargarEmployee(&auxCarga, &id) == 0)
        {
            retorno = addEmployee(&lista[indice], len, auxCarga.id, auxCarga.name, auxCarga.lastName, auxCarga.salary, auxCarga.sector);
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

int cargarEmployee(Employee* lista, int** id)
{
    int retorno = 1;
    Employee auxCarga;
    printf("\n\tALTA DE DATOS");

    if(getPalabra_Nombre(auxCarga.name, "Nombre", "Error, dato invalido", 50) == 0 &&
            getPalabra_Nombre(auxCarga.lastName, "Apellido", "Error, dato invalido", 50) == 0 &&
            ingresarDecimal(&auxCarga.salary, "Salario", "Error, dato invalio", 1, 30000) == 0 &&
            ingresarNumero(&auxCarga.sector, "Sector\n1\n2\n3\n4", "Error, dato invalido", 1, 4) == 0)
    {
        **id=generarId(**id);
        *lista = auxCarga;
        lista->id = **id;
        retorno = 0;
    }

    return retorno;
}
int buscarLibre(Employee *lista, int len)
{
    int retorno = -1;

    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == EMPTY)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void mostrarempleado(Employee empleado)
{
    printf("\n%17s| %11s| %16.2f| %12d| %10d|", empleado.lastName, empleado.name, empleado.salary, empleado.sector, empleado.id);
}
int bajaEmpleado(Employee* lista, int len)
{
    int retorno = 1;
    int auxBusqueda;

    printEmployees(lista, len);

    if(ingresarNumero(&auxBusqueda, "ID del empleado que desea eliminar", "Error, dato invalido", 1, 1000) == 0)
    {
        retorno = removeEmployee(lista, len, auxBusqueda);
    }
    return retorno;
}
int ordenar(Employee* A, Employee* B)
{
    Employee aux;

    aux = *A;
    *A = *B;
    *B = aux;

    return 0;
}
int modificarEmpleado(Employee* lista, int len)
{
    int retorno = 1;
    int auxBusqueda;

    printf("\n\tMODIFICACION DE DATOS");
    printEmployees(lista, len);

    if(ingresarNumero(&auxBusqueda, "ID del empleado que desea modificar", "Error, dato invalido", 1, 10000) == 0)
    {
        retorno = modificarDatos(lista, len, auxBusqueda);
    }
    return retorno;
}
int modificarDatos(Employee* lista, int len, int id)
{
    int retorno = -1;
    int indice;
    int opcion;

    indice = findEmployeeById(lista, len, id);
    if(indice != -1)
    {
        retorno = 1;
        do
        {
            system("cls");
            printf("\n\t APELLIDO|\tNOMBRE| \t SALARIO| \tSECTOR| \tID|");
            mostrarempleado(lista[indice]);
            menuModificacion(&opcion);

            switch(opcion)
            {
            case 1:
                getPalabra_Nombre(lista[indice].name, "Nombre", "Error, dato invalido", 50);
                retorno = 0;
                break;
            case 2:
                getPalabra_Nombre(lista[indice].lastName, "Apellido", "Error, dato invalido", 50);
                retorno = 0;
                break;
            case 3:
                ingresarDecimal(&lista[indice].salary, "Salario", "Error, dato invalio", 1, 20000);
                retorno = 0;
                break;
            case 4:
                ingresarNumero(&lista[indice].sector, "Sector\n1\n2\n3\n4", "Error, dato invalido", 1, 4);
                retorno = 0;
                break;
            }
            system("pause");
        }
        while(opcion != 5);
    }
    return retorno;
}
int informeSalarios(Employee lista[], int len)
{
    float totalSalario = 0;
    float promediSalario;
    int contSalarioPromedio = 0;

    calcularSalarios(lista, len, &totalSalario, &promediSalario);
    contarSalariosPromedio(lista, len, promediSalario, &contSalarioPromedio);

    printf("\n\nEl salario total es: %.2f\nEl salario promedio es: %.2f\n%d empleados superan el salario promedio", totalSalario, promediSalario, contSalarioPromedio);
    return 0;
}
int calcularSalarios(Employee lista[], int len, float* total, float* promedio)
{
    int contador = 0;

    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == FULL)
        {
            *total += lista[i].salary;
            contador++;
        }
    }
    *promedio = *total/contador;
    return 0;
}
int contarSalariosPromedio(Employee lista[], int len, float promedio, int* cantidad)
{
    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == FULL && lista[i].salary > promedio)
        {
            *cantidad = *cantidad + 1;
        }
    }
    return 0;
}

int buscarLleno(Employee* lista, int len)
{
    int retorno = -1;

    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == FULL)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
