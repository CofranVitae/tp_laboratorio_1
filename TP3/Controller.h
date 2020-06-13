/** \brief Carga los datos desde un archivo en modo texto
 *
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList* lista
 * \param id int* puntero a id para que, cuando cargo de un archivo, la siguiente alta de empleado
                continue autoincrementando el id correctamente,
 * \return int -1 error
                0 OK
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id);
/** \brief Carga los datos desde un archivo en modo binario
 *
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList* lista
 * \param id int* puntero a id para que, cuando cargo de un archivo, la siguiente alta de empleado
                continue autoincrementando el id correctamente,
 * \return int -1 error
                0 OK
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id);
/** \brief Alta del empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int* puntero a id autoincremental
 * \return int 0 OK
                -1 Error abriendo la lista o algun elemento
                1 cancelo la carga
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
/** \brief Permite modificar un empleado, primero se lo busca por id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 OK
                1 Se cancelo la operacion
                -1 Error con los punteros
                -2 No se encontro el empleado
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de un empleado, primero se lo busca por id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 Ok
                -1 Error con los punteros o se cancela la operacion
                -2 No se encontro
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Lista a todos los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int -1 si esta vacia
                0 Ok
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordena a los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 Ok
                -1 Error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda toda la lista en u archivo en modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 Ok
                -1 Error con los punteros
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda toda la lista en u archivo en modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 Ok
                -1 Error con los punteros
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Permite buscar un empleado dentro de la lista mediante su ID
 *
 * \param lista LinkedList*
 * \return int -2 si no se encuentra el id
                indice del id que se selecciono
 *
 */
int controller_buscarEmployeePorId(LinkedList* lista);



