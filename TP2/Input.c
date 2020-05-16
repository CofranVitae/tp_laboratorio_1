#include "input.h"

int cancelarOperacion(char mensaje[])
{
    int retorno;
    char opcion;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &opcion);

        if(opcion == 'n' || opcion == 'N')
        {
            retorno = 1;
        }
        else if(opcion == 's' || opcion == 'S')
        {
            retorno = 0;
        }
    }
    while(opcion != 's' && opcion != 'n' && opcion != 'S' && opcion != 'N');
    return retorno;
}

int generarId(int id)
{
    id++;
    return id;
}

//VALIDAR INGRESO DE UN NUMERO ENTERO, SOLAMENTE CON CARACTERES NUMERICOS EN UN RANGO DETERMINADO
int ingresarNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int auxCarga;
    int retorno = -1;
    if(pResultado != NULL)
    {
        retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

        while((retorno == 0) && (getInt(&auxCarga, mensaje) != 1 || auxCarga < minimo || auxCarga > maximo))
        {
            fflush(stdin);
            printf("\n%s: ", mensajeError);
            retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
        }
        if(retorno == 0)
        {
            *pResultado = auxCarga;
        }
    }
    return retorno;
}

//RECIBE UN NUMERO ENTERO
int getInt(int* carga, char mensaje[])
{
    int retorno = 0;
    char buffer[100];

    printf("\nIngrese %s: ", mensaje);
    fflush(stdin);
    gets(buffer);

    if(esNumero(buffer) == 1)
    {
        *carga = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}

//VERIFICA QUE TODOS LOS CARACTERES DEL NUMERO SEAN NUMEROS
int esNumero(char cadena[])
{
    int i;
    int retorno = 1;

    for(i = 0; i < strlen(cadena); i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')//si no es un numero devuelve 0
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


//INGRESA NUMEROS DECIMALES
int ingresarDecimal(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    float auxCarga;
    int retorno = -1;
    if(pResultado != NULL)
    {
    retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

    while((retorno == 0) && (getFloat(&auxCarga, mensaje) != 1 || auxCarga < minimo || auxCarga > maximo))
    {
        fflush(stdin);
        printf("\n%s", mensajeError);
        retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
    }
    if(retorno == 0)
    {
        *pResultado = auxCarga;
    }
    }
    return retorno;
}

//CARGA UN NUMERO FLOAT
int getFloat(float* carga, char mensaje[])
{
    int retorno = 0;
    char buffer[100];

    printf("\nIngrese %s: ", mensaje);
    fflush(stdin);
    gets(buffer);

    if(esDecimal(buffer) == 1)
    {
        *carga = atof(buffer);
        retorno = 1;
    }
    return retorno;
}


//VERIFICA SI LOS CARACTERES SON NUMEROS O '.', PORQUE ES UN DECIMAL
int esDecimal(char cadena[])
{
    int i;
    int retorno = 1;

    for(i = 0; i < strlen(cadena); i++)
    {
        if(!(cadena[i] >= '0' && cadena[i] <= '9') && !(cadena[i] == '.'))//si no es un numero decimal devuelve 0
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getPalabra_Nombre(char cadena[],char mensaje[], char mensajeError[], int tam)
{
    char auxCarga[200];
    int retorno = -1;
    if(cadena != NULL)
    {
    retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

    while((retorno == 0) && (sonLetras(auxCarga, mensaje) != 1 || strlen(auxCarga) > tam))
    {
        printf("\n%s", mensajeError);
        retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
    }
    //retorno = cancelarOperacion();
    if(retorno == 0)
    {
        strcpy(cadena, auxCarga);
    }
    }
    return retorno;
}

int getLetras_Numeros(char cadena[],char mensaje[], char mensajeError[], int tam)
{
    char auxCarga[200];
    int retorno = -1;
    if(cadena != NULL)
    {
    retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

    while((retorno == 0) && (sonLetrasNumeros(auxCarga, mensaje) != 1 || strlen(auxCarga) > tam))
    {
        printf("\n%s", mensajeError);
        retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
    }
    //retorno = cancelarOperacion();
    if(retorno == 0)
    {
        strcpy(cadena, auxCarga);
    }
    }
    return retorno;
}

int getMail(char cadena[],char mensaje[], char mensajeError[], int tam)
{
    char auxCarga[200];
    int retorno = -1;
    if(cadena != NULL)
    {
    retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

    while((retorno == 0) && (esMail(auxCarga, mensaje) != 1 || strlen(auxCarga) > tam))
    {
        printf("\n%s", mensajeError);
        retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
    }
    //retorno = cancelarOperacion();
    if(retorno == 0)
    {
        strcpy(cadena, auxCarga);
    }
    }
    return retorno;
}

int getNumeros_Simbolos(char cadena[],char mensaje[], char mensajeError[], int tam)//-, _, /, \, etc.
{
    char auxCarga[200];
    int retorno = -1;
    if(cadena != NULL)
    {
    retorno = cancelarOperacion("\nQuiere realizar el ingreso? s(si), n(no)");

    while((retorno == 0) && (esNumeroSigno(auxCarga, mensaje) != 1 || strlen(auxCarga) > tam))
    {
        printf("\n%s", mensajeError);
        retorno = cancelarOperacion("\nQuiere reintentar la operacion? s(si), n(no)");
    }
    //retorno = cancelarOperacion();
    if(retorno == 0)
    {
        strcpy(cadena, auxCarga);
    }
    }
    return retorno;
}

void cargarString(char carga[], char mensaje[])
{
    printf("\nIngrese su %s: ", mensaje);
    fflush(stdin);
    gets(carga);
}

int sonLetras(char cadena[], char mensaje[])
{
    int i;
    int retorno = 1;

    cargarString(cadena, mensaje);
    for(i = 0; i < strlen(cadena); i++)
    {
        if(!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || cadena[i] == ' '))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int sonLetrasNumeros(char cadena[], char mensaje[])
{
    int i;
    int retorno = 1;

    cargarString(cadena, mensaje);
    for(i = 0; i < strlen(cadena); i++)
    {
        if(!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ' '))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int esMail(char cadena[], char mensaje[])
{
    int largo;
    int i;
    int retorno = 0;

    cargarString(cadena, mensaje);
    largo = strlen(cadena);

    for(i = 0; i < largo; i++)
    {
        if(cadena[i] == 64)
        {
            retorno = 1;
            break;
        }
        if(cadena[i] == ' ')
        {
            retorno = 0;
            break;
        }
    }
    if(!(cadena[largo-4] == '.' && cadena[largo-3] == 'c' && cadena[largo-2] == 'o' && cadena[largo-1] == 'm'))
    {
        retorno = 0;
    }

    return retorno;
}

int esNumeroSigno(char cadena[], char mensaje[])
{
    int i;
    int retorno = 1;

    cargarString(cadena, mensaje);
    for(i = 0; i < strlen(cadena); i++)
    {
        if(!((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ' ' || cadena[i] == '-' || cadena[i] == '/' || cadena[i] == '.' || cadena[i] == '_'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
