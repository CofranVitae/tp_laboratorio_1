#include <stdio.h>
#include <stdlib.h>


/** \brief Pide el ingreso de un numero decimal y lo valida
 *
 * \param char* recibe el mensaje que indica el dato a ingresar
 * \param char* recibe el mensaje para mostrar en caso de error
 * \return float Devuelve el numero validado
 *
 */
float getFloat(char[], char[]);


/** \brief Pide igreso de un entero
 *
 * \param char[] Mensaje que indica el dato a ingresar
 * \return char numero ingresado
 *
 */
int getInt(char[]);



/** \brief suma dos numeros
 *
 * \param numeroUno float el primer operador que le paso
 * \param numeroDos float el segundo operador que le paso
 * \return float el resultado de la suma
 *
 */
float suma(float numeroUno, float numeroDos);



/** \brief resta dos numeros
 *
 * \param numeroUno float el primer operador que le paso
 * \param numeroDos float segundo operador que le paso
 * \return float el resultado de la operacion
 *
 */
float resta(float numeroUno, float numeroDos);



/** \brief divide dos numeros
 *
 * \param numeroUno float el primer operador que le paso
 * \param numeroDos float segundo operador que le paso
 * \return float el resultado de la operacion
 *
 */
float division(float numeroUno, float numeroDos);



/** \brief multiplica dos numeros
 *
 * \param numeroUno float el primer operador que le paso
 * \param numeroDos float segundo operador que le paso
 * \return float el resultado de la operacion
 *
 */
float multiplicacion(float numeroUno, float numeroDos);



/** \brief calcula el factorial de un numero natural
 *
 * \param numeroUno float el numero que quiero calcular el factorial
 * \return float el resultado de la operacion o, en el caso de que el perador
                    no sea un numero natural, devuelve 0.
 *
 */
long long int factorial(float);



/** \brief valida si el numero es natural o no
 *
 * \param float recibe el numero que va a validar
 * \return int devuelve un para que indica si el numero es un entero o no, devuelve 1 si es entero y 0 si es negativo o decimal.
 *
 */
int validarNatural(float);



