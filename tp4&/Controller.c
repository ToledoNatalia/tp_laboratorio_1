#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief imprime un empleado en particular
 *
 * \param   el linkedlist de empleados
 * \param   id del empleado que quiero mostrar
 */

void mostrarEmpleado(LinkedList* pArrayListEmployee,int id)
{
    eEmpleados* empleado = (eEmpleados*) employee_new();
    int tam = ll_len(pArrayListEmployee);

    int auxId ;
    int auxHoras ;
    int auxSueldo ;
    char auxNombre[128] ;

    for(int i=0; i<tam; i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        employee_getId(empleado,&auxId);
        if(auxId == id)
        {
            employee_getHorasTrabajadas(empleado,&auxHoras);
            employee_getSueldo(empleado,&auxSueldo);
            employee_getNombre(empleado,auxNombre);

            printf("  Id           Nombre   Horas trabajadas   Sueldo \n");
            printf("--------------------------------------------------------------\n");
            printf("%4d  %15s %10d  %15d\n", auxId, auxNombre, auxHoras, auxSueldo);
            printf("---------------------------------------------------------------\n");
            break;
        }
    }
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))!=NULL)
    {
        retorno = 0;
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    }
    else
    {
        printf("No se pudo leer\n");
    }
    return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    eEmpleados* auxiliar = employee_new();

    int retorno = -1;
    int auxId ;
    int auxHoras ;
    int auxSueldo ;
    char auxNombre[128] ;


    obtenerId(&auxId);
    actualizarId(auxId);

    system("cls");
    printf("*****ALTA EMPLEADO*****\n\n");

    utn_getNombre(auxNombre,128,"Ingrese el nombre: ","Nombre invalido\n",2);
    utn_getNumero(&auxHoras,"Ingrese horas trabajadas(entre 10 y 350): ","Las horas estan entre 10 y 350\n",10,350,2);
    utn_getNumero(&auxSueldo,"Ingrese sueldo entre 10000 y 200000: ","Los sueldos van desde 10000 hasta 200000\n",10000,200000,2);

    employee_setId(auxiliar,auxId);
    employee_setHorasTrabajadas(auxiliar,auxHoras);
    employee_setSueldo(auxiliar,auxSueldo);
    employee_setNombre(auxiliar,auxNombre);

    if(!ll_add(pArrayListEmployee,auxiliar))
    {
        printf("Alta exitosa\n");
        retorno = 0;
    }
    else
    {
        employee_delete(auxiliar);
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    eEmpleados* empleado;

    int retorno = -1;
    int idEmpleado;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    int tam = ll_len(pArrayListEmployee);
    int i;
    int rta;
    char auxNombre[128];


    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("*****MODIFICAR EMPLEADO*****\n\n");

        controller_ListEmployee(pArrayListEmployee);

        utn_getNumero(&auxId,"Ingrese el id del empleado a modificar: ","No se encuentra un empleado con ese id\n",1,tam,2);

        mostrarEmpleado(pArrayListEmployee,auxId);

        for( i=0; i<tam; i++)
        {
            empleado = (eEmpleados*) ll_get(pArrayListEmployee, i);
            employee_getId(empleado,&idEmpleado);

            if( auxId == idEmpleado )
            {
                printf("1) Nombre\n");
                printf("2) Horas trabajadas\n");
                printf("3) Sueldo\n");
                printf("4) Salir\n");
                utn_getNumero(&rta,"Eliga opcion para  modificar ","Opcion invalida\n",1,4,2);

                switch(rta)
                {
                case 1:
                    utn_getNombre(auxNombre,128,"Ingrese el nombre: ","Nombre invalido\n",2);
                    employee_setNombre(empleado, auxNombre);
                    break;

                case 2:
                    utn_getNumero(&auxHorasTrabajadas,"Ingrese nuevas horas trabajadas: ","Cantidad invalida. Van desde 10 hasta 350\n",10,350,2);
                    employee_setHorasTrabajadas(empleado, auxHorasTrabajadas);
                    break;

                case 3:
                    utn_getNumero(&auxSueldo,"Ingrese nuevo sueldo: ","Sueldo incorrecto.Los sueldos van desde 10000 hasta 200000",10000,200000,2);
                    employee_setSueldo(empleado, auxSueldo);
                    break;

                case 4:
                    printf("Modificacion cancelada!\n");
                    break;
                }

   }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxId;
    int indice;
    char confirma='s';
    eEmpleados* auxEmp;
    int tam= ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("   ***BAJA EMPLEADO***\n\n");

        controller_ListEmployee(pArrayListEmployee);

        utn_getNumero(&auxId,"Ingrese el id del empleado a dar de baja:","Ingrese id valido:\n",1,tam,2);

        indice=findEmployeeById(pArrayListEmployee,auxId);

        if(indice!=-1)
        {
            auxEmp=ll_get(pArrayListEmployee,indice);
            printf("\n\n");
            printf("ID      NOMBRE     HORAS   SUELDO\n");
            mostrarEmpleado(pArrayListEmployee,auxId);

          utn_getNumero(&auxId,"ingrese ID  a remover: ","No se encuentra nadie con ese ID\n",1,tam,2);
            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,indice);
                printf("Empleado borrado con exito\n");
                employee_delete(auxEmp);

                retorno=0;
            }
            else
            {
                retorno=1;
            }
        }
    }

    return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    eEmpleados* auxiliar;
    int retorno = -1;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int tamanio = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        if(tamanio > 0)
        {
            printf("  Id          Nombre   Horas Trabajadas    Sueldo \n");

            for(i = 0; i < tamanio; i++)
            {
                auxiliar = (eEmpleados*)ll_get(pArrayListEmployee, i);
                employee_getId(auxiliar, &id);
                employee_getNombre(auxiliar,nombre);
                employee_getHorasTrabajadas(auxiliar,&horasTrabajadas);
                employee_getSueldo(auxiliar,&sueldo);

                printf("%4d  %15s %10d  %15d\n",id, nombre, horasTrabajadas, sueldo);

            }
            retorno = 0;
        }
        else
        {
            printf("No se cargaron los datos\n");
        }
    }
    else
    {
        printf("LISTA VACIA\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rta;
    int orden;
    int retorno = -1;

    if(pArrayListEmployee!= NULL)
    {
        retorno = 0;
        system("cls");
        printf("*****ORDENAR EMPLEADOS*****\n\n");

        printf("1)Ordenar por id\n");
        printf("2)Ordenar por nombre\n");
        printf("3)Ordenar por horas trabajadas\n");
        printf("4)Ordenar por sueldo\n");
        printf("4)Salir\n");

        utn_getNumero(&rta,"Ingrese opcion: ","Error\n",1,5,2);
        switch(rta)
        {
        case 1:
            utn_getNumero(&orden,"\nORDEN:\n1)Ascendente \n0)Descendente\n","ERROR\n",0,1,2);
            ll_sort(pArrayListEmployee,employee_ordenarPorId,orden);
            break;
        case 2:
            utn_getNumero(&orden,"\nORDEN:\n1)Ascendente \n0)Descendente\n","ERROR\n",0,1,2);
            ll_sort(pArrayListEmployee,employee_ordenarPorNombre,orden);
            break;
        case 3:
            utn_getNumero(&orden,"\nORDEN:\n1)Ascendente \n0)Descendente\n","ERROR\n",0,1,2);
            ll_sort(pArrayListEmployee,employee_ordenarPorHorasTrabajadas,orden);
            break;
        case 4:
            utn_getNumero(&orden,"\nORDEN:\n1)Ascendente \n0)Descendente\n","ERROR\n",0,1,2);
            ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,orden);
            break;
        case 5:

            break;


        }

    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    FILE* fpArchivo;

    int len = ll_len(pArrayListEmployee);
    eEmpleados* auxiliar;

    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        fpArchivo = fopen(path,"w");
        if(fpArchivo != NULL)
        {
            fprintf(fpArchivo,"id,nombre,horasTrabajadas,sueldo\n");
            retorno = 0;
            for (i=0; i<len ; i++)
            {
                auxiliar = ll_get(pArrayListEmployee, i);
                if(!employee_getId(auxiliar,&id)&&
                        !employee_getNombre(auxiliar,nombre) &&
                        !employee_getHorasTrabajadas(auxiliar,&horasTrabajadas) &&
                        !employee_getSueldo(auxiliar,&sueldo)
                  )
                {
                    fprintf(fpArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
                }
            }
            fclose(fpArchivo);
        }
    }
    return retorno;
}


