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

void MostrarFloat (float numeroRecibido);

int main(void)
{
	setbuf(stdout,NULL);

	MostrarFloat(150.1999);

	return EXIT_SUCCESS;
}

void MostrarFloat (float numeroRecibido)
{
	printf("El numero ingresado es : %.2f",numeroRecibido);
}
