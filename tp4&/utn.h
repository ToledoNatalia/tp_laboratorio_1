#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED




 int getString(char* cadena, int longitud);
 int getInt(int* pResultado);
 int esNumerica(char* cadena);
 int getFloat(float* pResultado);
 int esFlotante(char cadena[]);
 int getNombre(char* pResultado, int longitud);
 int esNombre(char* cadena, int longitud);
 int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
 int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError,int reintentos);
 int getCharTwoOptions(char* pChar,char message[],char errorMessage[],char option1,char option2);
 int validatePositiveInteger(char number[]);
 int getChar(char* pChar,char message[],char errorMessage[]);
 int validatePositiveInteger(char number[]); int getFloat(float* pResultado); int esFlotante(char cadena[]);
 int isValidName(char* cadena,int longitud);
 int isOnlyLetters(char string[]);



#endif // UTN_H_INCLUDED
