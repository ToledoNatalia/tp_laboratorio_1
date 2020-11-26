
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/** \brief Pide un numero y lo devuelve validado
 *
 * \param mensaje Mensaje para el usuario
 * \param mensajeError un mensaje de error en caso que el usuario no ingrese un numero valido
 * \return el numero valido
 *
 */
int getInt(char mensaje[],char mensajeError[]);

/** \brief Pide un numero flotante  y lo devuelve validado
 *
 * \param mensaje Mensaje para el usuario
 * \param mensajeError A mensaje in case the usuario enters a non validated float numero
 * \return
 *
 */
float getFloat(char mensaje[],char mensajeError[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param mensaje Mensaje para el  usuario
 * \param mensajeError , mensaje en caso que el usuario no ingrese solo letras
 *
 */
void getString(char str[],int len,char mensaje[],char mensajeError[]);

/** \brief Pide un personaje, lo valida y lo devuelve validado
 *
 * \param mensaje Mensaje para el usuario
 * \param mensajeError un mensaje en caso de que el usuario no ingrese solo caracteres
  * \return el caracter validado
 *
 */
char getChar(char mensaje[],char mensajeError[]);

/** \brief Pide al usuario que elija una opción entre dos caracteres, valida que es una de las opciones y la devuelve validada
 *
 * \param mensaje Mensaje para el usuario
 * \param mensajeError Un mensaje en caso de que el usuario ingrese un carácter que no es una de las opciones
 * \return el caracter validado
 *
 */
char getCharTwoOptions(char mensaje[],char mensajeError[],char option1,char option2);

/** \brief Pide al usuario que elija una opción entre dos números, valida que es una de las opciones y la devuelve validada
 *
 * \param mensaje Mensaje para  el usuario
 * \param mensajeError Un mensaje en caso de que el usuario ingrese un numero que no es una de las opciones
 * \return  el numero validado
 *
 */
int getIntTwoOptions(char mensaje[],char mensajeError[],int option1,int option2);

/** \brief Valida que una cadena solo tiene números
 *
 * \param numero  que se valida
 * \return 1 en caso que el string sea solo numeros y 0 en caso de error
 *
 */
int validatePositiveInteger(char numero[]);

/** \brief Valida que una cadena solo tenga números
 *
 * \param numero flotante que se valida
 * \return 1 en caso de que la cadena sea solo números y 0 si no lo es
 *
 */
int validatePositiveFloat(char numberFloat[]);

/** \brief valida que el string sea solo letras
 *
 * \param string el string que se valida
 * \return 1 en caso que sea solo letra  0 en caso de que no sea solo letras
 *
 */
int isOnlyLetters(char str[]);
