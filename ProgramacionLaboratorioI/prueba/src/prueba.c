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
#include <ctype.h>
#include "vectores.h"

int main(void) {

	setbuf(stdout,NULL);

	char caracter[10]= "Hola";

	MostrarString(caracter);
	return EXIT_SUCCESS;
}
