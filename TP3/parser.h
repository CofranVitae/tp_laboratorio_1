/** \brief Carga los datos de un archivo de texto a la estructura empleado
 *
 * \param pFile FILE* archivo
 * \param pArrayListEmployee LinkedList*
 * \param id int** puntero a puntero de id autoincremental, para que la proxima alta continue
                    autoincrementando desde donde corresponde
 * \return int -1 Error leyendo el archivo o el archivo esta vacio o no se pudieron cargar los campos
                != -1 Si se leyo y se cargo
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int** id);
/** \brief Carga los datos de un archivo binario a la estructura empleado
 *
 * \param pFile FILE* archivo
 * \param pArrayListEmployee LinkedList*
 * \param id int** puntero a puntero de id autoincremental, para que la proxima alta continue
                    autoincrementando desde donde corresponde
 * \return int -1 Error leyendo el archivo o el archivo esta vacio o no se pudieron cargar los campos
                0 Si se leyo y se cargo
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int** id);
