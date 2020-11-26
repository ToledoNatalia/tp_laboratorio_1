#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "validaciones.h"

#define TAM 1000


int menuEmpleados();

int main(void)
{

    eEmployee lista[TAM];

    int id=1000;
    int sector;
    int flag1=0;
    int opcion;
    int idParametro;
    char nombre[50];
    char apellido[50];
    float salario;
    char confirma='n';


    if(!inicializarEmpleado(lista,TAM))
    {
        printf("Empleado inicializado con exito");
    }

    do
    {
        system("cls");
        opcion=menuEmpleados();

        system("cls");

        switch(opcion)
        {
        case 1:
            if(buscarEspacioLibre(lista,TAM)!= -1)
            {
                printf(" ***ALTA EMPLEADOS***\n\n");

                getString(nombre,sizeof(nombre),"Ingrese nombre:\n","ERROR\nIngrese nombre nuevamente:");
                getString(apellido,sizeof(apellido),"Ingrese apellido:\n","ERROR\nIngrese apellido nuevamente:");
                salario=getFloat("Ingrese salario:\n","ERROR\nIngrese salario nuevamente");
                sector=getInt("Ingrese sector(numero):\n","ERROR\nIngrese sector:");

                if(altaEmpleado(lista,TAM,id,nombre,apellido,salario,sector)!=-1)
                {
                    printf("\n Alta exitosa!!\n\n");
                    id++;
                    flag1=1;
                }
                else
                {
                    printf("\nError,no se pudo agregar empleado\n\n");
                }
            }
            break;
        case 2:
            if(flag1)
            {
                printf("*******MODIFICAR  EMPLEADO*********\n\n");
                mostrarEmpleados(lista,TAM);
                idParametro=getInt("Ingrese el ID del empleado que desea modificar:\n","ERROR\nIngrese ID nuevamente:");
                if(modificarEmpleado(lista,TAM,idParametro))
                {
                    printf("\nModificacion exitosa!!...");

                }
                else
                {

                    printf("Problemas al modificar empleado..");
                }
            }

         break;
        case 3:
            if(flag1)
            {
                printf("*******BAJA EMPLEADO*******\n\n");
                mostrarEmpleados(lista,TAM);
                idParametro=getInt("Ingrese ID del empleado que desea dar de baja:","ERROR\n Ingrese el ID nuevamente:");
                if(bajaEmpleado(lista,TAM,idParametro))
                {

                    printf("\nBaja exitosa!!...");

                }
                else
                {

                    printf("Problemas al dar de baja el empleado..");
                }
            }

         break;
        case 4:
            if(flag1)
            {
                informe(lista,TAM);
            }
            else
            {
                printf("\nError primero debe agregar un empleado\n\n");
            }
            break;
        case 5:
            confirma=getCharTwoOptions("seguro que desea salir? (s/n)","ERROR\n Ingrese  s o n:",'s','n');
            break;
        default:
            printf("Opcion invalida\n\n");
            break;
        }

        system("pause");

    }
    while(confirma=='n');

    system("cls");

    return EXIT_SUCCESS;
}

int menuEmpleados()
{
    int opcion;

    printf("***************MENU DE EMPLEADOS*****************\n\n");
    printf("1.Agregar empleado\n");
    printf("2.Modificar empleado\n");
    printf("3.Baja empleado\n");
    printf("4.Informe\n");
    printf("5.Salir\n\n");
    printf("--------------------------------------------------\n\n");
    opcion=getInt("Ingrese una opcion : ","\nERROR\nIngrese una opcion valida: ");

    return opcion;
}


char menuModificacion()
{
    char opcion;

    system("cls");

    printf("   ***MODIFICATION MENU***\n\n");
    printf("a.Modificar nombre\n");
    printf("b.Modificar apellido\n");
    printf("c.Modificar salario\n");
    printf("d.Modificar sector\n");
    printf("_______________________________\n\n");
    opcion=getChar("Elegir una opcion:","ERROR\nIngrese nuevamente una opcion:");

    return opcion;
}


char menuInforme()
{
    char opcion;

    system("cls");

    printf("*******MENU INFORMES*******\n\n");
    printf("a.Lista de empleados ordenados por nombre y sector\n\n");
    printf("b.Informe Salario\n\n");
    printf("c.Salir\n");
    printf("__________________________________________________________\n\n");

    opcion=getChar("Elegir una opcion:","ERROR\n Ingrese nuevamente una opcion:");

    return opcion;
}

