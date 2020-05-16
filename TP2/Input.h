#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Pregunta si se desea continuar con la operacion
 *
 * \return int 1 si se desea cancelar
                0 si se continua con la operacion
 *
 */
int cancelarOperacion(char mensaje[]);
/** \brief recibe un id y le suma 1
 *
 * \param int
 * \return int id que recibio+1
 *
 */
int generarId(int);

/** \brief Permite el ingreso de numeros enteros
 *
 * \param int* puntero a variable que guarda el numero que se ingresa
 * \param char[] mensaje de que se esta ingresando
 * \param char[] mensaje de error
 * \param int maximo permitido
 * \param int minimo permitido
 * \return int -1 en caso de error
                1 si se cancela
                0 si esta todo bien
 *
 */
int ingresarNumero(int*, char[], char[], int, int);
/** \brief Carga una cadena, si es un numero lo transforma a numero y lo guarda en el puntero resultado
 *
 * \param int* puntero a variable que guarda el resultado
 * \param char[] mensaje de que se va a cargar
 * \return int 0 si el dato es invalido
                1 si esta todo bien
 *
 */
int getInt(int*, char[]);
/** \brief valida que la cadena ingresada sea un numero entero
 *
 * \param char[]
 * \return int 0 si nmo es u numero
                1 si es un numero
 *
 */
int esNumero(char[]);





/** \brief Permite el ingreso de numeros enteros
 *
 * \param float* puntero a variable que guarda el numero que se ingresa
 * \param char[] mensaje de que se esta ingresando
 * \param char[] mensaje de error
 * \param int minimo
 * \param int maximo
 * \return int -1 en caso de error
                1 si se cancela
                0 si esta todo bien
 *
 */
int ingresarDecimal(float* ,char[], char[], int, int);
/** \brief Carga una cadena, si es un numero lo transforma a numero y lo guarda en el puntero resultado
 *
 * \param float* puntero a numero que guarda el resultado
 * \param char[] mensaje de que se ingresa
 * \return int 0 si el dato es invalido
                1 si esta todo bien
 *
 */
int getFloat(float*, char[]);
/** \brief valida que la cadena ingresada sea un numero decimal
 *
 * \param char[]
 * \return int 0 si no es un numero
                1 si es un numero
 *
 */
int esDecimal(char[]);





/** \brief Permite el ingreso de cadenas de letras o espacios solamente, llama a esLetra para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getPalabra_Nombre(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de letras o numeros solamente, llama a sonLetrasNumeros para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getLetras_Numeros(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de con formato de mail , llama a esMail para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getMail(char cadena[],char mensaje[], char mensajeError[], int tam);
/** \brief Permite el ingreso de cadenas de numeros o simbolos como guiones, guiones bajos, llama a sonLetrasNumeros para validar
            Valida que la cadena tenga un largo determinado
            En caso de dato invalido, muestra error y pregunta si se desa seguir con la operacion (Funcion  CancelarOperacion)
 *
 * \param cadena[] char Puntero a cadena en la que se escribe el dato
 * \param mensaje[] char Mensaje que indica que dato se esta ingresando
 * \param mensajeError[] char Mensaje que se muestra en caso de error al ingresar el dato
 * \param tam int Tamaño maximo de caracteres que puede tener la cadena
 * \return int Si el ingreso fue valido, la cadena se carga con los datos y devuelve 0,
                Si se decidio cancelar la operacion devuelve 1, y la cadena no se carga con ningun dato
 *
 */
int getNumeros_Simbolos(char cadena[],char mensaje[], char mensajeError[], int tam);


/** \brief Ingresa una cadena en un auxiliar
 *
 * \param char[] auxiliar de carga
 * \param mensaje[] char mensaje con la info de la carga
 *
 */
void cargarString(char[], char mensaje[]);

/** \brief Funcion que es llamada por getString, valida que todos los caracteres sean letras o espacios
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int sonLetras(char[], char[]);
/** \brief valida que todos los caracteres sean letras o numeros
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int sonLetrasNumeros(char[], char[]);
/** \brief valida que la cadena respete el formato de mail
 *
 * \param char[] auxiliar de carga
     Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int esMail(char[], char[]);
/** \brief valida que todos los caracteres sean numeros o simbolos como guiones, guiones bajos, etc.
 *
 * \param char[] auxiliar de carga
    Mensaje que indica que dato se esta ingresando
 * \return int devuelve 1 si la carga fue valida, 0 si fue invalida
 *
 */
int esNumeroSigno(char[], char[]);
