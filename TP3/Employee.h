#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un nuevo elemento de tipo Employee* en memoria
 *
 * \return Employee* puntero al empleado que se creo
 *
 */
Employee* employee_new();
/** \brief Crea un nuevo elemento de tipo Employee* en memoria y le asigna valores a traves de datos
            guardados como string
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* puntero al empleado que se creo
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief Crea un nuevo elemento de tipo Employee* en memoria y le asigna valores a traves de datos
            guardados como su respectivo tipo de dato
 *
 * \param id int
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee* puntero al empleado que se creo
 *
 */
Employee* employee_newParametrosInt(int id,char* nombre,int horasTrabajadas,int sueldo);
/** \brief Elimina un employee de memoria
 *
 * \param this Employee* empleado que se elimina
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief Setter para id de empleado como entero
 *
 * \param this Employee* empleado al que se le carga el id
 * \param id int id que se va a cargar
 * \return int -1 error
                0 OK
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Getter para id de empleado como entero
 *
 * \param this Employee* empleado del que se saca el id
 * \param id int* puntero a variable donde se guarda el id que se quiere obtener
 * \return int-1 error
                0 OK
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setter para nombre
 *
 * \param this Employee* empleado al que se le carga el nombre
 * \param nombre char* nombre que se va a cargar
 * \return int-1 error
                0 OK
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief  Getter para nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int-1 error
                0 OK
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setter para cargar horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int-1 error
                0 OK
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Getter para obtener horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int-1 error
                0 OK
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setter para cargar sueldo a un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int-1 error
                0 OK
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Getter para obtener el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int-1 error
                0 OK
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Setter para cargar un sueldo a un empleado que viene como string, para cargar los datos que vienen desde archivos
 *
 * \param this Employee*
 * \param sueldo char* string que contiene el sueldo, se pasa a int y se carga
 * \return int-1 error
                0 OK
 *
 */
int employee_setSueldoTxt(Employee* this,char* sueldo);
/** \brief Getter Para extraer el sueldo de un empleado y pasarlo a string
 *
 * \param this Employee*
 * \param sueldo char*
 * \return int-1 error
                0 OK
 *
 */
int employee_getSueldoTxt(Employee* this,char* sueldo);
/** \brief Setter para cargar un id a un empleado que viene como string, para cargar los datos que vienen desde archivos
 *
 * \param this Employee*
 * \param id char*
 * \return int-1 error
                0 OK
 *
 */
int employee_setIdTxt(Employee* this,char* id);
/** \brief Getter Para extraer el id de un empleado y pasarlo a string
 *
 * \param this Employee*
 * \param id char*
 * \return int-1 error
                0 OK
 *
 */
int employee_getIdTxt(Employee* this,char* id);
/** \brief Setter para cargar las horas de trabajo a un empleado desde un string, para cargar los datos que vienen desde archivos
 *
 * \param this Employee*
 * \param horasTrabajadas char*
 * \return int
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
/** \brief Getter Para extraer las horas trabajadas de un empleado y pasarlo a string
 *
 * \param this Employee*
 * \param horasTrabajdas char*
 * \return int
 *
 */
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajdas);
/** \brief Compara los nombres de dos empleados, establece el criterio para el ordenamiento
 *
 * \param e1 void*
 * \param e2 void*
 * \return int 1 se cumple e criterio
                -1 No se cumple el criterio
                0 Son iguales
 *
 */
int employee_CompareByName(void* e1, void* e2);
/** \brief Compara los ids de dos empleados, establece el criterio para el ordenamiento
 *
 * \param e1 void*
 * \param e2 void*
 * \return int 1 se cumple e criterio
                -1 No se cumple el criterio
                0 Son iguales
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief Carga todos los datos a un empleado, utiliza todos los setters internamente
 *
 * \param this Employee* empleado al que se le van a cargar los datos
 * \param id int dato que se le pasa al setter de id
 * \param nombre char* dato que se le pasa al setter de nombre
 * \param horasTrabajadas int dato que se le pasa al setter de horas
 * \param sueldo int dato que se le pasa al setter de sueldo
 * \return int-1 error
                0 OK
 *
 */
int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);
/** \brief Carga todos los datos a un empleado, utiliza todos los setters internamente
            Los datos los carga desde strings, para cuando vengan de archivos de texto
 *
 * \param this Employee*
 * \param id char*
 * \param nombre char*
 * \param horasTrabajadas char*
 * \param sueldo char*
 * \return int-1 error
                0 OK
 *
 */
int employee_setAllTxt(Employee* this, char* id, char* nombre, char* horasTrabajadas, char* sueldo);
/** \brief Extrae todos los datos de un empleado
 *
 * \param this Employee*
 * \param id int*
 * \param nombre char*
 * \param horasTrabajadas int*
 * \param sueldo int*
 * \return int-1 error
                0 OK
 *
 */
int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);

/** \brief Muestra el menu donde se realiza la modificacion de un empleado
 *
 * \param aux Employee* empleado que se esta modificando
 * \param id int  los datos que se ingresan se guardan aca para cargarlos al aux con los setters
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return int 1 se cancelo la operacion
                0 OK
 *
 */
int controller_menuModificarEmpleado(Employee* aux, int id, char* nombre, int horasTrabajadas, int sueldo);
/** \brief Muestra todos los datos de un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_MostrarEmployee(Employee* this);

#endif // employee_H_INCLUDED
