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

int IngresoNumero(void);

int main(void)
{
	setbuf(stdout,NULL);

	int numero;

	numero = IngresoNumero();

	printf("\nEl numero ingresado en la funcion es: %d",numero);

	return EXIT_SUCCESS;
}

int IngresoNumero(void)
{
	int numeroIngresado;

	printf("Ingrese un numero entero: ");
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}
