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

int VerificarPar (int numeroRecibido);

int main(void)
{
	setbuf(stdout,NULL);

	int esPar;

	esPar = VerificarPar(33);

	if(esPar == 1)
	{
		printf("El numero ingresado es par");
	}
	else
	{
		printf("El numero ingresado es impar");
	}


	return EXIT_SUCCESS;
}

int VerificarPar (int numeroRecibido)
{
	int resultado;
	int esPar;

	resultado = numeroRecibido % 2;

	if(resultado == 0)
	{
		esPar = 1;
	}
	else
	{
		esPar = 0;
	}

	return esPar;
}
