#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/** ex mygets(Ahora se llama getString) lee hasta un /0 o hasta el limite-1 para guardar el caracter terminador del array
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud -1' caracteres.
* \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* \param longitud Define el tamaño de cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*/
 int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud >0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {

            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString)<= longitud)
            {

                strncpy(cadena,bufferString,longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
 int esNombre(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */

 int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if( getString(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strlen(buffer) < longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */

int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError,int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strlen(bufferString) < longitud)
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
*/

 int esNumerica(char* cadena)
{
    int retorno = 1;
    int i=0;

    if(cadena[0] == '-')
    {
        i=1;
    }
    for( ; cadena[i] != '\0' ; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

/**
* \brief Obtiene un numero entero
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/

 int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[64];

    if(pResultado != NULL)
    {
        if(getString(bufferString,sizeof(bufferString))==0 && esNumerica(bufferString) == 1)
        {
            *pResultado = atoi(bufferString);
            retorno = 0;
        }
    }

    return retorno;
}

/**
* \brief Verifica si la cadena ingresada es flotante
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (verdadero) si la cadena es flotante y 0 (falso) si no lo es
*/

 int esFlotante(char cadena[])
{
    int retorno = 1;
    int i;
    int flag = 0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0; cadena[i] != '\0' ; i++)
        {
            if(i==0)
            {
                if(cadena[i] == '-' || cadena[i] == '+')
                {
                    continue;
                }
            }
            if(cadena[i]< '0' || cadena[i]>'9')
            {
                if(cadena[i] == '.' && flag == 0)
                {
                    flag = 1;
                    continue;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Verifica si la cadena ingresada es solo numerica Flotante
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/

 int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado puntero a la variable en la que se asignara el numero ingresado
 * \param mensaje Mensaje a mostrar
 * \param mensajeError Mensaje que se muestra en caso de error
 * \param minimo Numero minimo permitido
 * \param maximo Numero maximo permitido
 * \param reintentos Cantidad de reintentos
 *
 * \return 0 si la funcion se ejecuto perfectamente y -1 en caso de que haya habido un error
 */

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >=0)
    {
        while(reintentos>=0)
        {
            reintentos--;
            printf("%s",mensaje);
            if(getInt(&bufferInt) == 0)
            {
                if(bufferInt >= minimo && bufferInt <= maximo)
                {
                    *pResultado = bufferInt;
                    retorno = 0;
                    break;
                }
            }
            printf("%s",mensajeError);
        }
    }
    return retorno;
}

/**
* \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
*
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero minimo a ser aceptado
* \param maximo Es el minimo maximo a ser aceptado
*
* \return Retorna 0 si se obtuvo el numero flotante y -1 si no se encontro
*/

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;

    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

/** \brief Obtiene un caracter entre un rango determinado, con reintentos limitados
 *
 * \param puntero a la variable en la que se asignara el caracter ingresado
 * \param Mensaje a mostrar
 * \param Mensaje que se muestra en caso de error
 * \param Caracter minimo permitido
 * \param Caracter maximo permitido
 * \param Cantidad de reintentos
 *
 * \return 0 si la funcion se ejecuto perfectamente y -1 en caso de que haya habido un error
 */

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >=0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&buffer);
            if(buffer>=minimo && buffer<=maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }

    return retorno;
}


/** \brief Busca un numero dentro de un array de numeros
 *
 * \param  Numero a buscar dentro del array
 * \param  El array en el que voy a buscar el numero
 * \param  El tamaño del array
 *
 * \return Si lo encontro: devuelve el indice donde se encuentra el numero. Si no lo encontro devuelve -1
 */

int utn_buscarNumeroEnArray(int numero, int array[], int len)
{
    int indice = -1;
    int i;

    for(i=0; i<len; i++)
    {
        if(array[i]==numero)
        {
            indice=i;
            break;
        }
    }
    return indice;
}



/** \brief Imprime los indices y sus valores dentro de un array de enteros
 *
 * \param El array que quieras imprimir
 * \param El tamaño del array
 *
 * \return
 */

void utn_printArrayInt(int pArray[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        printf("Indice: %d --- Valor: %d\n",i,pArray[i]);
    }
}


/** \brief Inicializa un array de enteros con un valor inicial
 *
 * \param El array que voy a inicializar
 * \param El tamaño del array
 * \param El valor con el que voy a inicializar todos los elementos del array
 *
 * \return Devuelve 0 Si pudo inicializar el array y -1 Si no pudo inicializar el array(xq es nulo o con tamaño invalido)
 */

int utn_initArrayInt(int pArray[], int longitud, int valorInicial)
{
    int respuesta = -1;
    int i;
    if(pArray!= NULL && longitud > 0)
    {
        respuesta = 0;
        for(i=0; i<longitud; i++)
        {
            pArray[i] = valorInicial;
        }
    }
    return respuesta;
}






 int isValidName(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

