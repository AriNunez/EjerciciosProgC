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
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;

	printf("==========OPCIONES==========\n");
	printf("1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n");

	if(utn_getInt(&opcion, "\nSeleccione una opcion: ", "\nError! Seleccione una opcion valida: ", 1, 5, 2)==0)
	{
		switch(opcion)
		{
			case 1:
				printf("\nUsted ha seleccionado la opcion 1-Inicializar");
				break;
			case 2:
				printf("\nUsted ha seleccionado la opcion 2-Cargar");
				break;
			case 3:
				printf("\nUsted ha seleccionado la opcion 3-Mostrar");
				break;
			case 4:
				printf("\nUsted ha seleccionado la opcion 4-Calcular Promedio");
				break;
			case 5:
				printf("\nUsted ha seleccionado la opcion 5-Ordenar");
				break;
		}
	}

	return EXIT_SUCCESS;
}
