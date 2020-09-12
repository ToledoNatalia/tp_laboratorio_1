#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


    int main()
    {
        int A;
        int B;
        int suma;
        int resta;
        int multiplicar;
        int factorialA;
        int factorialB;
        int opcion;
        int flagOpcion1=0;
        int flagOpcion2=0;
        float dividir;
        char salir='s';
        char seguir='s';

     do
      {
        printf( "   >>> MENU CALCULADORA <<<\n\n" );
        printf ("  1.Ingresar primer numero \n");
        printf ("  2.Ingresar segundo numero \n");
        printf ("  3.Calcular \n");
        printf ("  4.Mostrar \n");
        printf ("  5.Salir \n");
        fflush(stdin);
        printf("\n  Seleccione  una opcion: \n");
         scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                    system("cls");
                    printf("Ingrese el primer numero: \n\n");
                    scanf("%d", &A);
                    flagOpcion1=1;

                break;

            case 2:
                system("cls");
                   if (flagOpcion1==1)
                   {
                        printf("Ingrese el segundo numero: \n\n");
                        scanf("%d", &B);
                        flagOpcion2=1;


                   } else {
                            printf("Error , debe ingresar el primer numero\n\n");
                          }

                break;

            case 3:
                 system("cls");
                    if (flagOpcion1==0)
                    {

                      printf("Error , intente nuevamente\n\n");
                    }

                     else if(flagOpcion2==1 )
                      {
                        suma= SumarNumeros(A,B);
                        printf("El resultado de A+B es: %d\n", suma);

                        resta= RestarNumeros(A,B);
                        printf("El resultado de A-B es: %d\n", resta);

                        multiplicar= MultiplicarNumeros(A,B);
                        printf("El resultado de A*B es: %d\n", multiplicar);

                        dividir= DividirNumeros(A,B);
                        printf("El resultado de A/B es: %.2f\n", dividir);

                        if (B==0)
                        {
                            printf("Error,No es posible dividir por 0.\n");
                            printf("Ingrese el primer numero: ");
                            scanf("%d", &A);

                            printf("Ingrese el segundo numero: ");
                            scanf("%d", &B);

                         }
                            factorialA= FactorizarNumero(A);
                            factorialB= FactorizarNumero(B);
                            printf("\nEl factorial de %d es %d,el factorial de %d es %d",A, factorialA, B,factorialB);

                        }else
                           {
                             printf("Error , debe ingresar los numeros antes de calcular\n\n");
                            }

                    break;

            case 4:
                system("cls");
                if(flagOpcion2==1)
                {
                    suma= SumarNumeros(A,B);
                    printf("\nEl resultado de %d+%d es: %d",A, B, suma);

                    resta= RestarNumeros(A,B);
                    printf("\nEl resultado de %d-%d es: %d",A, B, resta);

                    multiplicar= MultiplicarNumeros( A ,B);
                    printf("\nEl resultado de %d*%d es: %d",A, B, multiplicar);

                    dividir= DividirNumeros(A,B);
                    printf("\nEl resultado de %d/%d es: %.2f",A , B, dividir);

                    if(B ==0)
                    {
                        printf("Error, No es posible dividir por 0.\n");
                        printf("Ingrese el primer numero: ");
                        scanf("%d", &A);
                        printf("Ingrese el segundo numero: ");
                        scanf("%d", &B);
                    }

                    factorialA= FactorizarNumero(A);
                    factorialB= FactorizarNumero(B);
                    printf("\nEl factorial de %d es %d,el factorial de %d es %d",A, factorialA, B,factorialB);


                    flagOpcion2=0;


                   } else{
                          printf("Error, numeros no ingresados \n\n");

                        }
                    break;

            case 5:
                system("cls");
                printf("Esta seguro que desea salir ? (s/n)\n\n");
                fflush(stdin);
                scanf("%c",&salir);
                salir = tolower(salir);

                if (salir == 's')
                {
                    return 0;
                }

                    break;

             default:
                    system("cls");
                    printf("Opcion incorrecta\n\n");

                    break;


           }

            system("pause");



        }while(seguir ='s');

         return 0;
        }



