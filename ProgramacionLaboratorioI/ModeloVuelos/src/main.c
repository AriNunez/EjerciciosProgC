/*
 ============================================================================
 Name        : ModeloVuelos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	FILE* pArchivo;
	LinkedList* pLista;
	int option;


	do
	{
		puts("1. Cargar los datos desde el archivo (modo texto)"
				"\n2.Mostrar\n");

		if(utn_getInt(&option, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 3, 3)==0)
			{
				switch(option)
				{
					case 1:
						break;

					case 2:

						break;
				}
			}
	}
	while(option != 3);
	return EXIT_SUCCESS;
}
