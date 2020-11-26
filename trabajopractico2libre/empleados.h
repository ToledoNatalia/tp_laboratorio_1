#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

}eEmployee;


#endif /* ARRAYEMPLOYEES_H_ */

/** \brief Para indicar que todas las posiciones de la matriz están vacías,esta función pone la bandera (isEmpty) en true
* \param lista empleados
* \param len int longitud del array
* \return int Devuelve (-1) si Error [longitud no válida] - (0) si está bien
*
*/
int inicializarEmpleado(eEmployee* vec, int len);

/** \brief Busca un espacio libre en la matriz (isEmpty = 1)
 *
 * \param vec el array
 * \param len longitud del array
 * \return El índice si hay posiciones libres o -1 si no las hay
 *
 */
int buscarEspacioLibre(eEmployee* vec, int len);

/** \brief agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
* \param vec empleados
* \param len int
* \param id int
* \param nombre[] char
* \param apellido[] char
* \param salario float
* \param sector int
* \return int Devuelve (-1) si Error [Longitud no válida  o sin espacio libre] - (0) si está bien
*
*/
int altaEmpleado(eEmployee* vec, int len, int id, char nombre[],char apellido[],float salario,int sector);

/** \brief buscar un empleado por Id en devuelve la posición del índice en la matriz
*
* \param lista empleados
* \param len int
* \param id int
* \return Devuelve la posición del índice de empleado o (-1) si [Longitud no válida o empleado no encontrado]
*
*/
int buscarEmpleadoXId(eEmployee* vec, int len,int id);

/** \brief modifica un empleado (nombre,apellido, sector o salario) retorna -1,1 or 0
 *
 * \param
 * \param
 * \param
 * \return 1 si el empleado fue removido, 0 si el usuario canceló la modificación
y -1 si no se encuentra la identificación, longitud no válida
 *
 */
int modificarEmpleado(eEmployee* vec, int len,int id);


/** \brief Eliminar un empleado por Id (poner isEmpty Flag en 1)
* \param lista empleados*
* \param len int
* \param id int
* \return int Devuelve (-1) si Error [Longitud no válida o si no puede encontrar un empleado] - (0)
si el usuario no confirmó y 1 si está bien
*
*/
int bajaEmpleado(eEmployee* vec, int len, int id);


/** \brief muestra un empleado
 *
 * \param employee el empleado para mostrar
 *
 */
void mostrarEmpleado(eEmployee employee);

/** \brief
 *
 * \param vec Array de empleados
 * \param len longitud del array
 * \return int
 *
 */
int mostrarEmpleados(eEmployee* vec, int len);

/** \brief Permite al usuario conocer más sobre los salarios y los empleados.
 *
 * \param vec Array de empleados
 * \param len longitud del  array
 *
 */
void informe(eEmployee vec[],int len);

/** \brief Agrega todos los salarios de las empleadas
 *
 * \param vec array de empleados
 * \param len longitud del array
 * \return La suma de todos los salarios
 *
 */
float agregarSalario(eEmployee vec[],int len);

/** \brief Cuenta la cantidad de empleados
 *
 * \param vec array de empleados
 * \param len longitud del array
 * \return cantidad de empleados
 *
 */
int contarEmpleados(eEmployee vec[],int len);

/** \brief Cuenta la cantidad de empleados que ganan más dinero que el promedio
 *
 * \param vec Array de empleados
 * \param len longitud del array
 * \param Promedio de salario, promedio de todos los salarios
 * \return La cantidad de empleados que ganan más dinero que el promedio.
 *
 */
int contarEmpleadosSalarioMasAlto(eEmployee vec[],int len,float salarioPromedio);

/** \brief Ordene los elementos en la matriz de empleados, el orden de los argumentos
indicar orden ARRIBA o ABAJO
*
* \param lista empleados
* \param len int
* \param orden int [1] indica ARRIBA - [0] indica ABAJO
* \return int Devuelve (-1) si hay error [longitud no válida ] - (0) si está bien
*
*/
int ordenarEmpleados(eEmployee* vec, int len, int order);

/** \brief Muestra los informes sobre los salarios de los empleados.
*
* \param lista empleados
* \param la suma de todos los salario
* \param salario promedio
* \param la cantidad de empleados que ganan más que el promedio
*
*/
void salarioInforme(float salarioTotal,float promedioSalarios,int salarioMasAlto);


char menuModificacion();


char menuInforme();

