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

void swap(int* pPrimerNumero,int* pSegundoNumero);

int main(void)
{
	setbuf(stdout,NULL);

	int numeros[2]={1,2};

	printf("%d--%d \n",numeros[0],numeros[1]);

	swap(&numeros[0],&numeros[1]);

	printf("%d--%d \n",numeros[0],numeros[1]);



	return EXIT_SUCCESS;
}

void swap(int* pPrimerNumero,int* pSegundoNumero)
{
	int aux;

	if(pPrimerNumero != NULL && pSegundoNumero != NULL)
	{
		aux = *pPrimerNumero;
		*pPrimerNumero = *pSegundoNumero;
		*pSegundoNumero = aux;
	}
}
