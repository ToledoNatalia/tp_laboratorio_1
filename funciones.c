
    #include "funciones.h"


    int SumarNumeros(int A,int B)
    {
        int suma;

        suma= A + B;

        return suma;

    }

    int RestarNumeros(int A,int B)
    {
        int resta;

        resta= A - B;

        return resta;

    }

    int MultiplicarNumeros(int A,int B)
    {
        int multiplicar;

        multiplicar= A* B;

        return multiplicar;

    }

    float DividirNumeros(float A,int B)
    {
        float dividir;

        dividir= A / B;

        return dividir;
    }

    long int FactorizarNumero(int numeroFactorial)
    {
        int factorial;

        if(numeroFactorial==0)
        {
            return 1;
        }else
            {
               factorial=numeroFactorial*FactorizarNumero(numeroFactorial-1);
            }


        return factorial;

    }
