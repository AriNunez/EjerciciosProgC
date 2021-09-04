/*
 ============================================================================
 Name        : Ejercicio2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);

    int numeroIngresado;
    int i;
    int flagMenor = 0;
    int menorIngresado;
    int contadorPares = 0;
    int contadorImpares = 0;
    int parMayor;
    int flagMayorPar = 0;
    int acumuladorPositivos = 0;
    int acumuladorNegativos = 1;

    for(i=0;i<10;i++)
    {
        printf("\nIngrese un numero distinto de cero: ");
        scanf("%d",&numeroIngresado);

        if(numeroIngresado == 0)
        {
            printf("\nError! Debe ingresar un numero distinto de cero");
            i--;
        }
        else
        {
            if(flagMenor == 0 || numeroIngresado < menorIngresado)
            {
                menorIngresado = numeroIngresado;
                flagMenor = 1;
            }

            if((numeroIngresado%2)==0)
            {
                contadorPares++;
                if(flagMayorPar == 0 || numeroIngresado > parMayor)
                {
                    parMayor = numeroIngresado;
                    flagMayorPar = 1;
                }
            }
            else
            {
                contadorImpares++;
            }

            if(numeroIngresado > 0)
            {
                acumuladorPositivos = acumuladorPositivos + numeroIngresado;
            }
            else
            {
                acumuladorNegativos = acumuladorNegativos * numeroIngresado;
            }
        }
    }

    printf("\n==================RESULTADOS=================\n");
    printf("a. Cantidad de pares: %d\tCantidad de impares: %d\n",contadorPares,contadorImpares);
    printf("b. El menor numero ingresado: %d\n",menorIngresado);
    printf("c. Mayor numero par: %d\n",parMayor);
    printf("d. Suma de los positivos: %d\n",acumuladorPositivos);
    printf("e. Producto de los negativos: %d",acumuladorNegativos);

    return 0;
}
