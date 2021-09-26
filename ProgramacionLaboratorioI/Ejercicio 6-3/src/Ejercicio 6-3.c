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
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define TAM 20

int main(void)
{
	setbuf(stdout,NULL);

	char nombre[TAM];
	char apellido[TAM];
	char apellidoNombre[TAM];
	int i;

	utn_getName(nombre, "\nIngrese su nombre: ", "\n¡Error! Ingrese un nombre valido: ", TAM, 0);
	utn_getName(apellido, "\nIngrese su apellido: ", "\n¡Error! Ingrese un apellido valido: ", TAM, 0);

	puts(nombre);
	puts(apellido);

	for(i = 0;i < strlen(nombre);i++)
	{
		if(i == 0)
		{
			nombre[i]= toupper(nombre[i]);
		}
		else
		{
			nombre[i]= tolower(nombre[i]);
		}
	}

	for(i = 0;i < strlen(apellido);i++)
	{
		if(i == 0)
		{
			apellido[i]= toupper(apellido[i]);
		}
		else
		{
			apellido[i]= tolower(apellido[i]);
		}
	}

	strcpy(apellidoNombre,apellido);
	strcat(apellidoNombre,",");
	strcat(apellidoNombre,nombre);

	puts(apellidoNombre);

	return EXIT_SUCCESS;
}
