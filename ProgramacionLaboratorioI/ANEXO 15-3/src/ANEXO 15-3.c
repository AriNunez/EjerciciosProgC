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

typedef struct{
	int legajo;
	char nombre[20];
	int edad;
}est;

int main(void)
{
	setbuf(stdout,NULL);

	est estudiantes[3];

	return EXIT_SUCCESS;
}
