/*
 ============================================================================
 Name        : Ejercicio2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT_NUM 5

int main(void)
{
	setbuf(stdout,NULL);

	  int numeroIngresado;
	    int acumulador = 0;
	    float promedio;
	    int i;

	    for(i=0;i<CANT_NUM;i++)
	    {
	        printf("\nIngrese un numero: ");
	        scanf("%d",&numeroIngresado);
	        acumulador = acumulador + numeroIngresado;
	    }

	    promedio = (float)acumulador / CANT_NUM;

	    printf("El promedio de la suma total entre los numeros ingresados es: %.2f",promedio);

	    return 0;
	return EXIT_SUCCESS;
}
