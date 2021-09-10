/*
 * input.c
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

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
