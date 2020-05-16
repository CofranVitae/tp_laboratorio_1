#include "input.h"
#define LENEMPLOYEES 1000
#define EMPTY 0
#define FULL 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Para indicar que todas las posiciones del array están vacías,
  esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
 *
 * \param list Employee* puntero a array de empleados
 * \param len int cantidad de empleados
 * \return int -1 en caso de error, 0 si todo esta bien
 *
 */
int initEmployees(Employee* list, int len);
/** \brief Agrega en un array de empleados existente los
 valores recibidos como parámetro en la primer posición libre.

 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int -1 en caso de error, 1 sis e cancela la operacion, 0 si esta todo bien
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.

 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int -1 en caso de erroro que no se encuentre el id, El indice del empleado si se encuentra el id
 *
 */
int findEmployeeById(Employee* list, int len, int id);
/** \brief Elimina de manera lógica
(isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.

 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int -1 en caso de error,
                1 sis e cancela la operacion,
                0 si esta todo bien
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief Ordena el array de empleados por
 apellido y sector de manera ascendente o descendente.

 *
 * \param list Employee*
 * \param len int
 * \param order int indica si se ordena de forma ascendente o decreciente
 * \return int  -1 si hay error
                0 si esta todo bien
 *
 */
int sortEmployees(Employee* list, int len, int order);
/** \brief Imprime el array de empleados de forma encolumnada.

 *
 * \param list Employee*
 * \param length int
 * \return int 0
 *
 */
int printEmployees(Employee* list, int length);



/** \brief Muestra el menu de opciones
 *
 * \param int* puntero a variable utilizada para elegir opcion
 * \return int
 *
 */
int menu(int*);
/** \brief Carga datos al array de employees para hacer las pruebas
 *
 * \param lista Employee* array
 * \return void
 *
 */
void hardcodearEmployees(Employee* lista);
/** \brief Realiza el alta de un empleado, le pasa a la funcion addEmployee los datos que tiene que cargar
 *
 * \param lista Employee*
 * \param len int
 * \param id int* puntero a variable id en el main, para poder generar un id automatico
 * \return int
 *
 */
int altaEmpleado(Employee* lista, int len, int *id);
/** \brief Realiza la carga de datos en un auxiliar de carga
 *
 * \param lista Employee*
 * \param id int** puntero al puntero de id de altaEmpleado, para poder generar un id autoincrementable
 * \return int
 *
 */
int cargarEmployee(Employee* lista, int** id);
/** \brief Busca la primer posicion libre (isEmpty 0)
 *
 * \param lista Employee*
 * \param len int
 * \return int
 *
 */
int buscarLibre(Employee *lista, int len);
/** \brief Muestra los datos de un solo empleado
 *
 * \param empleado Employee
 * \return void
 *
 */
void mostrarempleado(Employee empleado);
/** \brief Permite llevar a cabo la eliminacion de un empleado
            utiliza internamente findEmployeeById y removeEmployee,
            para pasarle el id que tiene que eliminar
 *
 * \param lista Employee*
 * \param len int
 * \return int -1 en caso de error
                1 si se cancela la operacion
                0 si esta todo bien
 *
 */
int bajaEmpleado(Employee* lista, int len);
/** \brief REaliza el swap para el ordenamiento
 *
 * \param Employee* posicion i del array
 * \param Employee* posicion i+1 del array
 * \return int 0
 *
 */
int ordenar(Employee*, Employee*);
/** \brief Permite modificar los datos de un empleado, utiliza internamente modificarDatos
            y findEmployeesById
 *
 * \param lista Employee*
 * \param len int
 * \return int -1 en caso de error
                1 si se cancela
                0 si esta todo bien
 *
 */
int modificarEmpleado(Employee* lista, int len);
/** \brief Permite llevar a cabo la modificacion de los datos
 *
 * \param lista Employee*
 * \param len int
 * \param id int recibe un id, que si verifica con findEmployeesById permite realizar la modificacion
 * \return int -1 si no se encuentra el empleado o hay error
                1 si se cancela la operacion
                0 si esta todo bien
 *
 */
int modificarDatos(Employee* lista, int len, int id);
/** \brief Muestra el menu de opciones para modificar los datos
 *
 * \param opcion int* puntero a variable para elegir las opciones
 * \return int 0
 *
 */
int menuModificacion(int* opcion);
/** \brief Muestra los informes solicitados sobre los salarios
            (promedio, total, y cantidad de personas que superan el promedio)
 *
 * \param Employee[]
 * \param len int
 * \return int  0
 *
 */
int informeSalarios(Employee[], int len);
/** \brief Calcula el total de todos los salarios del array y el promedio
 *
 * \param Employee[]
 * \param len int
 * \param float* puntero a variable que guarda el total de slarios
 * \param float* puntero a variable que guarda el promedio de los salarios
 * \return int 0
 *
 */
int calcularSalarios(Employee[], int len, float*, float*);
/** \brief Cuenta la cantidad de empleados que superan el salario promedio
 *
 * \param Employee[]
 * \param len int
 * \param float salario promedio
 * \param int* puntero a contador que guarda la cantidad
                de empleados que superan el salario promedio
 * \return int 0
 *
 */
int contarSalariosPromedio(Employee[], int len, float, int*);
/** \brief Busca el primer indice lleno (isEmpty 1), para validar
 en caso de que la lista no tenga ningun empleado cargado
 *
 * \param lista Employee*
 * \param len int
 * \return int
 *
 */
int buscarLleno(Employee* lista, int len);


