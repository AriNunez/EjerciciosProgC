/*
 ============================================================================
 Name        : Paraprobar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	int numero;

	if(utn_getIntSinLimite(&numero, "Ingrese un numero: ", "\nERROR\n", 10)==0)
	{
		printf("%d",numero);
	}
	else
	{
		puts("\nERROR EN ELSE\n");
	}

	return EXIT_SUCCESS;
}
