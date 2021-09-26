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

int main(void)
{
	setbuf(stdout,NULL);

	int listaNumeros[2]={2,5};
	int buffer;

	for(int i = 0;i<2;i++)
	{
		printf("%d\t",listaNumeros[i]);
	}

	printf("\n");
	buffer=listaNumeros[0];
	listaNumeros[0] = listaNumeros[1];
	listaNumeros[1]=buffer;

	for(int i = 0;i<2;i++)
	{
		printf("%d\t",listaNumeros[i]);
	}




	return EXIT_SUCCESS;
}
