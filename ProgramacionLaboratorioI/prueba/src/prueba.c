/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	char direccion[50];
	char cuit[15];

	if(utn_getDireccion(direccion, "\nIngrese una direccion (no se admiten caracteres especiales): \n", "\nERROR\n", 50, 5)==0)
	{
		puts(direccion);
	}

	if(utn_getCuitCuil(cuit, "\nIngrese el CUIT: \n", "\nERROR\n", 15, 5)==0)
	{
		puts(cuit);
	}


	return EXIT_SUCCESS;
}
