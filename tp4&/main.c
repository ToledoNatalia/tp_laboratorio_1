#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int menu();

int main()
{
    int opcion = 0;
    int flag = 0;
    char aux;
    int filter;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* subLista = NULL;
    LinkedList* listaFiltrada = NULL;
    LinkedList* listaClonada = NULL;

    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1:
            if(!flag && !controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("\nCarga exitosa!\n");
                flag = 1;
            }
            else
            {
                printf("\nError al cargar archivo\n");
            }

            break;

        case 2:
            if( !ll_isEmpty(listaEmpleados) && !controller_addEmployee(listaEmpleados))
            {
                printf("Se dio de alta al empleado\n");
            }
            else
            {
                printf("Error, archivo no cargado...\n");
            }

            break;

        case 3:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar el archivo\n");
            }

            break;

        case 4:

          if(!ll_isEmpty(listaEmpleados))
                {
                    switch(controller_removeEmployee(listaEmpleados))
                    {
                    case -1:
                        printf("\nProblemas para dar de baja\n\n");
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
        case 5:
            if( !ll_isEmpty(listaEmpleados) && !controller_ListEmployee(listaEmpleados))
            {
                printf(".\n");
            }
            else
            {
                printf("No se cargaron los datos\n");
            }
            break;

        case 6:
            if( !ll_isEmpty(listaEmpleados) && !controller_sortEmployee(listaEmpleados))
            {
                printf("Empleados ordenados\n");
            }
            else
            {
                printf("No se pudieron ordenar los empleados\n");
            }

            break;

        case 7:
            if(!ll_isEmpty(listaEmpleados) && !controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Datos guardados en modo texto\n");
            }
            else
            {
                printf("No se pudo guardar los datos en modo texto\n");
            }
            break;



        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                subLista = ll_createSublist(listaEmpleados);
                if(subLista!=NULL)
                {
                    printf("Sublista creada correctamente\n");
                }
            }
            else
            {
                printf("No se cargo la lista\n");
            }
            break;

        case 9:
            if( ll_isEmpty(subLista) || controller_ListEmployee(subLista))
            {
                printf("Fallo al imprimir sublista\n");
            }
            break;

        case 10:
            if(!ll_isEmpty(listaEmpleados))
            {
                listaClonada = ll_clone(listaEmpleados);
                if(listaClonada != NULL)
                {
                    printf("Se clono la listaEmpleados con exito\n");
                }
            }
            else
            {
                printf("No se cargo la lista\n");
            }
            break;

        case 11:
            if(!ll_isEmpty(listaClonada))
            {
                controller_ListEmployee(listaClonada);
            }
            break;

        case 12:
            if(!ll_isEmpty(listaEmpleados))
            {
                utn_getNumero(&filter,"Desea filtrar por Sueldo(1) o por horas trabajadas(0)? ", "Error\n",0,1,2 );
                if(filter)
                {
                    listaFiltrada = ll_filter(listaEmpleados,filtrarxRangoSueldo);
                    printf("Se filtro a los empleados que tienen sueldos entre 30.000 y 40.000");
                }
                else if(!filter)
                {
                    listaFiltrada = ll_filter(listaEmpleados,filtrarxRangoHoras);
                    printf("Se filtro a los empleados que tienen entre 100 y 200 horas trabajadas\n");
                }
                else
                {
                    printf("NO SE PUDO FILTRAR\n");
                }
            }
            else
            {
                printf("No se cargo la lista\n");
            }
            break;

        case 13:
            if(!ll_isEmpty(listaFiltrada))
            {
                controller_ListEmployee(listaFiltrada);
            }
            break;

        case 14:
            if(!ll_isEmpty(subLista))
            {
                moverUnEmpleado(subLista);
            }
            else
            {
                printf("No se cargo la subLista\n");
            }
            break;

        case 15:
            if(!ll_isEmpty(subLista) && !ll_isEmpty(listaFiltrada))
            {
                if(ll_containsAll(subLista,listaFiltrada))
                {
                    printf("La SubLista contiene a todos los elementos de ListaFiltrada\n");
                }
                else
                {
                    printf("La SubLista NO CONTIENE a todos los elementos de la ListaFiltrada\n");
                }
            }
            else
            {
                printf("Alguna de las 2 listas no esta cargada\n");
            }
            break;

        case 16:
            if(!ll_isEmpty(subLista) && !controller_saveAsText("subLista.csv",subLista))
            {
                printf("Datos guardados en subLista.csv ");
            }
            else
            {
                printf("No se pudo guardar la subLista\n");
            }

        case 17:
            if(!ll_isEmpty(listaFiltrada) && !controller_saveAsText("listaFiltrada.csv",listaFiltrada))
            {
                printf("Datos guardados en listaFiltrada.csv");
            }
            else
            {
                printf("No se pudo guardar la listaFlitrada\n");
            }




        case 18:
            if(!ll_isEmpty(listaClonada) && !controller_saveAsText("listaClonada.csv",listaClonada))
            {
                printf("Datos guardados en lista Clonada.csv \n");
            }
            else
            {
                printf("No se pudo guardar la listaClonada\n");
            }

            break;

        case 19:
            printf("Seguro que desea salir? ");
            fflush(stdin);
            scanf("%c", &aux);
            while(aux != 's' && aux != 'n')
            {
                printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                printf(" s/n : \n");
                fflush(stdin);
                scanf("%c", &aux);
            }

            if(aux == 's')
            {
                printf("Gracias.!!!\n");
                return 0;
            }
            system("pause");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion != 0);




    ll_deleteLinkedList(listaEmpleados);
    ll_deleteLinkedList(listaClonada);
    ll_deleteLinkedList(listaFiltrada);
    ll_deleteLinkedList(subLista);
    return 0;
}

int menu()
{
    int opcion;
    printf("1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2) Alta de empleado\n");
    printf("3) Modificar datos de empleado\n");
    printf("4) Baja de empleado\n");
    printf("5) Listar empleados\n");
    printf("6) Ordenar empleados\n");
    printf("7) Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("8) Crear sublista de empleados\n");
    printf("9) Imprimir sublista\n");
    printf("10) Clonar lista de empleados\n");
    printf("11) Imprimir lista de empleados Clonada\n");
    printf("12) Filtrar empleados por sueldo o horas trabajadas\n");
    printf("13) Imprimir lista de empleados filtrados\n");
    printf("14) Mover un empleado en la subLista a una posicion determinada\n");
    printf("15) Verificar si la SubLista contiene a todos los elementos de la ListaFiltrada\n");
    printf("16) Guardar SubLista\n");
    printf("17) Guardar listaFiltrada\n");
    printf("18) Guardar listaClonada\n");
    printf("19) Salir\n");


  utn_getNumero(&opcion,"Elija la opcion deseada: ","Error, respuesta invalida\n",0,19,2);
    return opcion;

    return opcion;
}
