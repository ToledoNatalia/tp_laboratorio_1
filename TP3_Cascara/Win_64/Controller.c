#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "validaciones.h"
#include "menu.h"


/** \brief Obtiene el id a cargar a un empleado y lo carga a un puntero
 *
 * \param id int*
 * \return int -1 si el archivo de proxId no existe y sino 0
 *
 */
static int obtenerId(int* id)
{
    int retorno=-1;
    FILE* f;

    if(id!=NULL)
    {
        *id=1001;
        f=fopen("proxId.bin","rb");
        if(f!=NULL)
        {
            fread(id,sizeof(int),1,f);
            retorno=0;

            fclose(f);
        }
    }

    return retorno;
}

/** \brief actualiza el id y carga lo que sera el proximo id en un archivo binario
 *
 * \param id int Id actual para saber cual sera el proximo
 * \return int 0 si salio todo bien y sino -1
 *
 */
static int actualizarId(int id)
{
    int retorno=-1;
    FILE* f;

    id++;

    f=fopen("proxId.bin","wb");
    if(f!=NULL)
    {
        fwrite(&id,sizeof(int),1,f);
        retorno=0;
        fclose(f);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo del que se cargara info
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si salio todo bien y sino -1
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                retorno=0;
            }

            fclose(pFile);
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo del que se cargara la info
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si salio todo bien y sino -1
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno=0;
            }

            fclose(pFile);
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si salio todo bien y sino -1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* newEmployee=NULL;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("   ***ALTA EMPLEADO**\n\n");

        newEmployee=employee_new();
        if(newEmployee!=NULL)
        {
            getString(auxNombre,sizeof(auxNombre),"Ingrese nombre del empleado:","Ingrese nombre valido:");
            getInt(&auxHoras,"\n Ingrese la cantidad de horas trabajadas:","Ingrese cantidad de horas valida:");
            getInt(&auxSueldo,"\n Ingrese sueldo del empleado:","Ingrese sueldo valido:");
            obtenerId(&auxId);
            actualizarId(auxId);

            if(!employee_setId(newEmployee,auxId)&&
                !employee_setNombre(newEmployee,auxNombre)&&
                !employee_setHorasTrabajadas(newEmployee,auxHoras)&&
                !employee_setSueldo(newEmployee,auxSueldo))
            {
                ll_add(pArrayListEmployee,newEmployee);
                retorno=0;
            }
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si se modifico al empleado, 1 si se cancelo la operacion y -1 si hubo alguna falla
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char bufferNombre[128];
    int bufferInt;
    Employee* auxEmp;
    int auxId;
    int indice;
    char confirma;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("   ***MODIFICACIONES***\n\n");

        controller_ListEmployee(pArrayListEmployee);

        getInt(&auxId,"Ingrese el id del empleado a modificar:","Ingrese id valido:");
        indice=findEmployeeById(pArrayListEmployee,auxId);
        if(indice!=-1)
        {
            auxEmp=ll_get(pArrayListEmployee,indice);
            if(auxEmp!=NULL)
            {
                printf("\n\n");
                printf("ID      NOMBRE   HORAS     SUELDO\n");
                mostrarEmpleado(auxEmp);
                getCharTwoOptions(&confirma,"\n Es este el empleado que desea modificar? (s/n)\n","Ingrese s o n:",'s','n');
                if(confirma=='s')
                {
                    switch(submenuModificar(pArrayListEmployee))
                    {
                    case 'a':
                        getString(bufferNombre,sizeof(bufferNombre),"\nIngrese nuevo nombre:","Ingrese nombre valido:");
                        if(!employee_setNombre(auxEmp,bufferNombre)){
                            retorno=0;
                        }
                        break;
                    case 'b':
                        getInt(&bufferInt,"Ingrese cantidad de horas trabajadas:","Ingrese cantidad valida:");
                        if(!employee_setHorasTrabajadas(auxEmp,bufferInt))
                        {
                            retorno=0;
                        }
                        break;
                    case 'c':
                        getInt(&bufferInt,"Ingrese nuevo sueldo:","Ingrese sueldo valido:");
                        if(!employee_setSueldo(auxEmp,bufferInt))
                        {
                            retorno=0;
                        }
                        break;
                       case 'd':
                            break;


                    default:
                        printf("Opcion no valida\n");

                    }
                }
                else
                {
                    retorno=1;
                }
            }

        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si se dio de baja al empleado, 1 si se cancelo la operacion y -1 si hubo alguna falla
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxId;
    int indice;
    char confirma;
    Employee* auxEmp;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("   ***BAJA EMPLEADO***\n\n");

        controller_ListEmployee(pArrayListEmployee);
        getInt(&auxId,"Ingrese el id del empleado a dar de baja:","Ingrese id valido:");
        indice=findEmployeeById(pArrayListEmployee,auxId);
        if(indice!=-1)
        {
            auxEmp=ll_get(pArrayListEmployee,indice);
            printf("\n\n");
            printf("ID      NOMBRE     HORAS   SUELDO\n");
            mostrarEmpleado(auxEmp);
            getCharTwoOptions(&confirma,"\nEs este el empleado que desea dar de baja? (s/n)\n","Ingrese s o n:",'s','n');
            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,indice);
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
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    Employee* auxEmpleados;
    int flag=0;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("    ***LISTA DE EMPLEADOS***\n\n");
        printf(" ID  NOMBRE  HORAS  SUELDO\n");

        len=ll_len(pArrayListEmployee);
        for(int i=0; i<len; i++)
        {
            auxEmpleados=(Employee*) ll_get(pArrayListEmployee,i);
            if(auxEmpleados!=NULL)
            {
                mostrarEmpleado(auxEmpleados);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("\nNo hay empleados cargados\n\n");
        }

        retorno=0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int orden;
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        opcion=submenuOrdenar();

        getInt(&orden,"\nIngrese 1(ascendente) o 0(descendente):","Ingrese 1 o 0:");
        while(orden!=0&&orden!=1)
        {
            getInt(&orden,"Ingrese 1 o 0:","Ingrese 1 o 0:");
        }

        printf("\nOrdenando...\n");

        switch(opcion)
        {
        case 'a':
            ll_sort(pArrayListEmployee,compararPorId,orden);
            break;
        case 'b':
            ll_sort(pArrayListEmployee,compararPorNombre,orden);
            break;
        case 'c':
            ll_sort(pArrayListEmployee,compararPorHoras,orden);
            break;
        case 'd':
            ll_sort(pArrayListEmployee,compararPorSueldos,orden);
            break;
        case 'e':

            break;

        default:
            printf("Opcion no valida\n");

        }

        retorno=0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo en el que se escribira
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si salio todo bien y sino -1
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    int len;
    Employee* auxEmp;

    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0;i<len;i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                if(auxEmp!=NULL)
                {
                    if(!employee_getId(auxEmp,&auxId)&&
                       !employee_getNombre(auxEmp,auxNombre)&&
                       !employee_getHorasTrabajadas(auxEmp,&auxHoras)&&
                       !employee_getSueldo(auxEmp,&auxSueldo))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
                        retorno=0;
                    }
                }
            }

            fclose(pFile);
        }
    }

    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Nombre del archivo en el que se escribira
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si salio todo bien y sino -1
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    Employee* auxEmp;
    FILE* pFile;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(int i=0;i<len;i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                if(auxEmp!=NULL)
                {
                    fwrite(auxEmp,sizeof(Employee),1,pFile);
                    retorno=0;
                }
            }

            fclose(pFile);
        }
    }

    return retorno;
}
