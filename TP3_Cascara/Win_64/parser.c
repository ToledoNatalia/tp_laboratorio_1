#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* archivo de texto a parsear
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int 0 si salio todo bien y sino 1
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int cant;
    char buffer[4][128];
    Employee* newEmployee;

    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                newEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

                if(newEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,newEmployee);
                    retorno=0;
                }
            }else
            {
                break;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* archivo binario a parsear
 * \param pArrayListEmployee LinkedList* Array de empleados
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* newEmployee=NULL;

    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        fread(newEmployee,sizeof(Employee),1,pFile);

        while(!feof(pFile))
        {
            newEmployee=employee_new();

            if(newEmployee!=NULL)
            {
                if(fread(newEmployee,sizeof(Employee),1,pFile))
                {
                    ll_add(pArrayListEmployee,newEmployee);
                    retorno=0;
                }

            }else
            {
                break;
            }
        }
    }

    return retorno;


}
