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

int IngresoNumero(char* mensaje,int min,int max);

int main(void)
{
	setbuf(stdout,NULL);

	int numero;

	numero = IngresoNumero("\nIngrese un numero entre 0 y 100: ",0,100);

	printf("\nEl numero ingresado en la funcion es: %d",numero);

	return EXIT_SUCCESS;
}

int IngresoNumero(char* mensaje,int min,int max)
{
	int numeroIngresado;

	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("\nError!");
		printf("%s",mensaje);
		scanf("%d",&numeroIngresado);
	}

	return numeroIngresado;
}
