#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "validaciones.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee=employee_new();

    if(newEmployee!=NULL)
    {
        if(employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr))==-1||
           employee_setId(newEmployee,atoi(idStr))==-1||
           employee_setNombre(newEmployee,nombreStr)==-1||
           employee_setSueldo(newEmployee,atoi(sueldoStr))==-1)
        {
            employee_delete(newEmployee);
        }
    }

    return newEmployee;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}

int findEmployeeById(LinkedList* pArrayEmpleados,int id)
{
    int retorno=-1;
    int len;
    Employee* auxEmp;
    int auxId;

    if(pArrayEmpleados!=NULL)
    {
        len=ll_len(pArrayEmpleados);
        for(int i=0;i<len;i++)
        {
            auxEmp=ll_get(pArrayEmpleados,i);
            employee_getId(auxEmp,&auxId);
            if(auxEmp!=NULL&&auxId==id)
            {
                retorno=i;
                break;
            }
        }
    }

	return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;

    if(this!=NULL&&id>=0)
    {
        this->id=id;
        retorno=0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if(this!=NULL&&horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }

    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;

    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL&&sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }

    return retorno;
}

int mostrarEmpleado(Employee* empleado)
{
    int retorno=-1;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(empleado!=NULL)
    {
        if(!employee_getId(empleado,&auxId)&&
           !employee_getNombre(empleado,auxNombre)&&
           !employee_getHorasTrabajadas(empleado,&auxHoras)&&
           !employee_getSueldo(empleado,&auxSueldo))
        {
            printf("%03d %10s  %-3d   %d\n",auxId,auxNombre,auxHoras,auxSueldo);
            retorno=0;
        }
    }

    return retorno;
}

int compararPorId(void* emp1,void* emp2)
{
    int retorno;
    Employee* a=(Employee*) emp1;
    Employee* b=(Employee*) emp2;
    int auxIdA;
    int auxIdB;

    employee_getId(a,&auxIdA);
    employee_getId(b,&auxIdB);

    if(auxIdA>auxIdB)
    {
        retorno=1;
    }else if(auxIdA==auxIdB)
    {
        retorno=0;
    }else
    {
        retorno=-1;
    }

    return retorno;
}

int compararPorNombre(void* emp1,void* emp2)
{
    int retorno;
    Employee* a=(Employee*) emp1;
    Employee* b=(Employee*) emp2;
    char bufferA[128];
    char bufferB[128];

    employee_getNombre(a,bufferA);
    employee_getNombre(b,bufferB);

    retorno=stricmp(bufferA,bufferB);

    return retorno;
}

int compararPorHoras(void* emp1,void* emp2)
{
    int retorno;
    Employee* a=(Employee*) emp1;
    Employee* b=(Employee*) emp2;
    int auxHorasA;
    int auxHorasB;

    employee_getHorasTrabajadas(a,&auxHorasA);
    employee_getHorasTrabajadas(b,&auxHorasB);

    if(auxHorasA>auxHorasB)
    {
        retorno=1;
    }else if(auxHorasA==auxHorasB)
    {
        retorno=0;
    }else
    {
        retorno=-1;
    }

    return retorno;
}

int compararPorSueldos(void* emp1,void* emp2)
{
    int retorno;
    Employee* a=(Employee*) emp1;
    Employee* b=(Employee*) emp2;
    int auxSueldoA;
    int auxSueldoB;

    employee_getSueldo(a,&auxSueldoA);
    employee_getSueldo(b,&auxSueldoB);

    if(auxSueldoA>auxSueldoB)
    {
        retorno=1;
    }else if(auxSueldoA==auxSueldoB)
    {
        retorno=0;
    }else
    {
        retorno=-1;
    }

    return retorno;
}
