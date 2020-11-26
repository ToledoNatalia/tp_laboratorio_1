#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{


    int option=0;
    int flagTxt=0;
    int flagBinario=0;
    int flagAdd=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option=menu();

        switch(option)
        {
            case 1:
                if(flagBinario||flagTxt)
                {
                    printf("\nLos empleados ya fueron cargados\n\n");
                }else
                {
                    if(!controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("\nEmpleados cargados exitosamente!\n\n");
                        flagTxt=1;
                    }else
                    {
                        printf("\nProblemas para cargar los empleados\n\n");
                    }
                }
                break;
            case 2:
                if(flagTxt||flagBinario)
                {
                    printf("\nLos empleados ya fueron cargados\n\n");
                }else
                {
                    if(!controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("\nEmpleados cargados exitosamente!\n\n");
                        flagBinario=1;
                    }else
                    {
                        printf("\nProblemas para cargar los empleados\n\n");
                    }
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nAlta exitosa!!!\n\n");
                    flagAdd=1;
                }else
                {
                    printf("\nProblemas para dar de alta\n\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados))
                {
                    switch(controller_editEmployee(listaEmpleados))
                    {
                    case -1:
                        printf("\nProblemas para modificar\n\n");//algun parametro es null o el id no existe
                        break;
                    case 0:
                        printf("\nModificacion exitosa!\n\n");
                        break;
                    case 1:
                        printf("\nOperacion cancelada\n\n");
                        break;
                    }
                }else
                {
                    printf("\nPrimero debe cargar un empleado\n\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados))
                {
                    switch(controller_removeEmployee(listaEmpleados))
                    {
                    case -1:
                        printf("\nProblemas para dar de baja\n\n");//algun parametro es null o el id no existe
                        break;
                    case 0:
                        printf("\nBaja exitosa!\n\n");
                        break;
                    case 1:
                        printf("\nOperacion cancelada\n\n");
                        break;
                    }
                }else
                {
                    printf("\nPrimero debe cargar un empleado\n\n");
                }
                break;
            case 6:
               if(!ll_isEmpty(listaEmpleados))
                {
                    controller_ListEmployee(listaEmpleados);
                }else
                {
                    printf("\nPrimero debe cargar un empleado\n\n");
                }
                break;
            case 7:
               if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_sortEmployee(listaEmpleados))
                    {
                        printf("\nEmpleados ordenados!\n\n");
                    }else
                    {
                        printf("\nProblemas para ordenar a los empleados\n\n");
                    }
                }else
                {
                    printf("\nPrimero debe cargar un empleado\n\n");
                }
                break;
            case 8:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("\nEmpleados guardados exitosamente\n\n");
                    }else
                    {
                        printf("\nProblemas para guardar a los empleados\n\n");
                    }
                }else
                {
                    printf("\nNo hay empleados para guardar\n\n");
                }
                break;
            case 9:
                if(flagBinario)
                {
                    if(!controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("\nEmpleados guardados exitosamente\n\n");
                    }else
                    {
                        printf("\nProblemas para guardar a los empleados\n\n");
                    }
                }else
                {
                    printf("\nNo hay empleados para guardar\n\n");
                }
                break;
            case 10:
                break;//porque es la opcion para salir
            default:
                printf("\nOpcion no valida\n\n");
                break;
        }

        system("pause");//pauso la pantalla

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

