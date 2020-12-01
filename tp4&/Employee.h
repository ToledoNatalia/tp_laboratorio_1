
#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}eEmpleados;



eEmpleados* employee_new();
eEmpleados* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo);
void employee_delete(eEmpleados* this);

int employee_setId(eEmpleados* this,int id);
int employee_setNombre(eEmpleados* this,char* nombre);
int employee_setHorasTrabajadas(eEmpleados* this,int horasTrabajadas);
int employee_setSueldo(eEmpleados* this,int sueldo);

int employee_getId(eEmpleados* this,int* id);
int employee_getNombre(eEmpleados* this,char* nombre);
int employee_getHorasTrabajadas(eEmpleados* this,int* horasTrabajadas);
int employee_getSueldo(eEmpleados* this,int* sueldo);

int employee_ordenarPorId(void* item1, void* item2);
int employee_ordenarPorNombre(void* item1, void* item2);
int employee_ordenarPorSueldo(void* item1, void* item2);
int employee_ordenarPorHorasTrabajadas(void* item1, void* item2);

int findEmployeeById(LinkedList* pArrayEmpleados,int id);
int obtenerId(int* id);
int actualizarId(int id);

int moverUnEmpleado(LinkedList* lista);
int filtrarxRangoSueldo(void* empleado);
int filtrarxRangoHoras(void* empleado);


#endif // EMPLEADOS_H_INCLUDED
