#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    eEmpleados* auxiliar = employee_new();
    char buffer[4][128];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]) == 4)
            {
                auxiliar = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(auxiliar != NULL)
                {
                    ll_add(pArrayListEmployee,auxiliar);
                }
            }
        }
        while(!feof(pFile));
        retorno = 0;
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    return retorno;
}

