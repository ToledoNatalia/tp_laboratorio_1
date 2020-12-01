#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
void mostrarEmpleado(LinkedList* lista,int indice);
