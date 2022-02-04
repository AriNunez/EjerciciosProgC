/*
 ============================================================================
 Name        : ANEXO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int CalcularValorMaximo(int* pArray,int tam, int* pEntero);

int main(void)
{
	setbuf(stdout,NULL);

	int vector[3]={3,9,6};
	int valorMaximo;

	if(CalcularValorMaximo(vector, 3, &valorMaximo)==1)
	{
		printf("%d",valorMaximo);
	}


	return EXIT_SUCCESS;
}

int CalcularValorMaximo(int* pArray,int tam, int* pEntero)
{
	int i;
	int valorMaximo;
	int retorno;

	retorno = 0;

	if(pArray != NULL && tam > 0 && pEntero != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(i==0 || *(pArray+i) > valorMaximo)
			{
				valorMaximo = *(pArray+i);

			}
		}

		*pEntero = valorMaximo;
		retorno = 1;
	}

	return retorno;
}
