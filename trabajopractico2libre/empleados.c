#include "empleados.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"




int inicializarEmpleado(eEmployee* vec, int len)
{
    int error= -1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            vec[i].isEmpty=1;
        }

        error=0;
    }

    return error;
}

int buscarEspacioLibre(eEmployee* vec, int len)
{
    int error= -1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(vec[i].isEmpty==1)
            {
                error=i;
                break;
            }
        }
    }

    return error;
}

int buscarEmpleadoXId(eEmployee* vec, int len,int id)
{
    int error= -1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(vec[i].id==id&&vec[i].isEmpty==0)
            {
                error=i;
                break;
            }
        }
    }

    return error;
}


int altaEmpleado(eEmployee* vec, int len, int id, char nombre[],char apellido[],float salario,int sector)
{
    int index;
    int error= -1;

    index=buscarEspacioLibre(vec,len);//looks for a free position in the array

    if(index!=-1&&len>0&&vec!=NULL)
    {
        vec[index].id=id;
        strcpy(vec[index].nombre,nombre);
        strcpy(vec[index].apellido,apellido);
        vec[index].salario=salario;
        vec[index].sector=sector;
        vec[index].isEmpty=0;

        printf("\n%s %s ID : %d\n\n",vec[index].nombre,vec[index].apellido,id);

        error=0;
    }

    return error;
}

int modificarEmpleado(eEmployee* vec, int len,int id)
{
    int indice;
    int error = -1;
    char confirma;

    indice=buscarEmpleadoXId(vec,len,id);

    if(len>0&&vec!=NULL)
    {
        if(indice!=-1)
        {
            printf("\n");
            mostrarEmpleado(vec[indice]);
            confirma=getCharTwoOptions("\n Este es el empleado que desea modificar? s/n","ERROR\n Ingrese s o n:",'s','n');
            if(confirma=='s')
            {
                switch(menuModificacion())
                {
                case 'a':
                    getString(vec[indice].nombre,sizeof(vec[indice].nombre),"Ingrese nombre:","ERROR\n Ingrese nombre nuevamente:");
                    break;
                case 'b':
                    getString(vec[indice].apellido,sizeof(vec[indice].apellido),"Ingrese apellido:","ERROR\nIngrese apellido:");
                    break;
                case 'c':
                    vec[indice].salario=getFloat("Ingrese salario:","ERROR\n Ingrese salario nuevamente");
                    break;
                case 'd':
                    vec[indice].sector=getInt("Ingrese sector (number):","ERROR\nIngrese sector nuevamente:");
                    break;
                default:
                    printf("Opcion invalida\n\n");
                    break;
                }
                error=1;
            }
            else
            {
                error=0;
            }
        }
    }

    return error;
}


int bajaEmpleado(eEmployee* vec, int len, int id)
{
    int indice;
    char confirma;
    int error=-1;

    indice=buscarEmpleadoXId(vec,len,id);

    if(indice!=-1&&vec!=NULL&&len>0)
    {
        mostrarEmpleado(vec[indice]);
        confirma=getCharTwoOptions("\nEsta seguro que desea dar de baja este empleado? (s/n)","ERROR\nIngrese s o n:",'s','n');
        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            error=1;
        }
        else
        {
            error=0;
        }
    }

    return error;
}




int mostrarEmpleados(eEmployee* vec, int len)
{
    int error=-1;

    if(len>0&&vec!=NULL)
    {
        system("cls");
        printf("           ***LISTA DE EMPLEADOS***\n\n");
        printf("  ID         Nombre     Apellido    Salario   Sector\n");
        for(int i=0; i<len; i++)
        {
            if(vec[i].isEmpty==0)
            {
                mostrarEmpleado(vec[i]);
            }
        }

        error=0;
    }

    return error;
}

void mostrarEmpleado(eEmployee employee)
{
    printf(" %4d | %10s | %10s |  %5.2f  | %1d\n",employee.id,employee.nombre,employee.apellido,employee.salario,employee.sector);
}




void informe (eEmployee vec[],int len)
{
    char opcion;
    float salarioTotal;
    int cantidadEmpleados;
    int salarioMasAlto;
    float salarioPromedio;
    int orden;

    do
    {
        opcion= menuInforme();

        switch(opcion)
        {
        case 'a':
            printf("\nSi desea que los empleados sean ordenados en orden descendente ingrese 0, de lo contrario ingrese 1 \n");
            orden=getIntTwoOptions("\nEliga el orden:","ERROR\n Ingrese 1 o 0:",1,0);
            ordenarEmpleados(vec,len,orden);
            mostrarEmpleados(vec,len);
            break;
        case 'b':
            salarioTotal=agregarSalario(vec,len);
            cantidadEmpleados=contarEmpleados(vec,len);
            salarioPromedio=salarioTotal/cantidadEmpleados;
            salarioMasAlto=contarEmpleadosSalarioMasAlto(vec,len,salarioPromedio);
            salarioInforme(salarioTotal,salarioPromedio,salarioMasAlto);
            break;
        case 'c':
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(opcion!='c');

}



float agregarSalario(eEmployee vec[],int len)
{
    int total=0;

    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0)
        {
            total=total+vec[i].salario;
        }
    }

    return total;
}

int contarEmpleados(eEmployee vec[],int len)
{
    int error=0;

    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0)
        {
            error++;
        }
    }

    return error;
}

int contarEmpleadosSalarioMasAlto(eEmployee vec[],int len,float salarioPromedio)
{
    int error=0;

    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0&&vec[i].salario>salarioPromedio)
        {
            error++;
        }
    }

    return error;
}



void salarioInforme(float salarioTotal,float promedioSalarios,int salarioMasAlto)
{
    system("cls");
    printf("   ***Informe Salario***\n\n")  ;
    printf("Salario Total: %.3f\n\n Promedio salarios: %.3f\n\nSalario mas alto: %d\n\n",salarioTotal,promedioSalarios,salarioMasAlto);
}

int ordenarEmpleados(eEmployee* vec, int len, int orden)
{
    eEmployee auxEmployee;
    int retorno=-1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(vec[i].isEmpty==0&&vec[j].isEmpty==0)
                {
                    switch(orden)
                    {
                    case 0:
                        if(vec[i].sector>vec[j].sector)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        else if(vec[i].sector==vec[j].sector&&stricmp(vec[i].nombre,vec[j].nombre)>0)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        break;
                    case 1:
                        if(vec[i].sector<vec[j].sector)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        else if(vec[i].sector==vec[j].sector&&stricmp(vec[i].nombre,vec[j].nombre)<0)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        break;
                    }

                    retorno=0;

                }

            }
        }
    }

    return retorno;
}
