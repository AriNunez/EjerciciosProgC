/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int CargarValorPorPuntero(int* numero);


int main(void)
{
	setbuf(stdout,NULL);

	int numero;

	if(CargarValorPorPuntero(&numero)==1)
	{
		printf("\nEl numero ingresado es: %d",numero);
	}
	else
	{
		printf("\nNO SE PUDO CARGAR NINGUN NUMERO\n");
	}

	return EXIT_SUCCESS;
}

int CargarValorPorPuntero(int* pEntero)
{
	int retorno;
	int auxNumero;

	retorno = 0;

	if(pEntero != NULL)
	{
		printf("Ingrese un numero: \n");
		scanf("%d",&auxNumero);
		*pEntero = auxNumero;
		retorno = 1;
	}

	return retorno;
}
