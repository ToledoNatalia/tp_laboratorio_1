#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int getInt(char mensaje[],char mensajeError[])
{
    char strNumber[32];
    int numero;

    puts(mensaje);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        puts(mensajeError);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    numero=atoi(strNumber);

    return numero;
}

float getFloat(char mensaje[],char mensajeError[])
{
    char strFloat[32];
    float numero;

    puts(mensaje);
    fflush(stdin);
    fgets(strFloat,sizeof(strFloat),stdin);
    strFloat[strlen(strFloat)-1]='\0';

    while(!validatePositiveFloat(strFloat))
    {
        puts(mensajeError);
        fflush(stdin);
        fgets(strFloat,sizeof(strFloat),stdin);
        strFloat[strlen(strFloat)-1]='\0';
    }

    numero=atof(strFloat);

    return numero;
}

int validatePositiveInteger(char numero[])
{
    int returnValue=1;

    for(int i=0;numero[i]!='\0';i++)
    {
        if(numero[i]<'0'||numero[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}

int validatePositiveFloat(char numberFloat[])
{
    int returnValue=1;
    int pointCounter=0;

    for(int i=0;numberFloat[i]!='\0';i++)
    {
        if(numberFloat[i]<'0'||numberFloat[i]>'9')
        {
            if(numberFloat[i]=='.'&&pointCounter==0)
            {
                pointCounter++;
            }else
            {
                returnValue=0;
                break;
            }
        }
    }

    return returnValue;

}

void getString(char string[],int len,char mensaje[],char mensajeError[])
{
    puts(mensaje);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isOnlyLetters(string))
    {
        puts(mensajeError);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

int isOnlyLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

char getChar(char mensaje[],char mensajeError[])
{
    char aux;

    puts(mensaje);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
    {
        puts(mensajeError);
        fflush(stdin);
        scanf("%c",&aux);
    }

    return aux;
}

char getCharTwoOptions(char mensaje[],char mensajeError[],char option1,char option2)
{
    char aux;

    puts(mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);

    while(aux!=option1&&aux!=option2)
    {
        puts(mensajeError);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    return aux;
}

int getIntTwoOptions(char mensaje[],char mensajeError[],int option1,int option2)
{
    char strNumber[32];
    int numero;

    puts(mensaje);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        puts(mensajeError);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    numero=atoi(strNumber);

    while(numero!=option1&&numero!=option2)
    {
        puts(mensajeError);
        scanf("%d",&numero);
    }

    return numero;

}
