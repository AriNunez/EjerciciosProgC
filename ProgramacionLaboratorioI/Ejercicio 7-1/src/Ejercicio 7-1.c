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
#include "utn.h"

#define

typedef struct{
	int idProducto;
	char descripcion[100];
	char nacionalidad[3]={"EEUU","CHINA","OTRO"};
	char tipo[4]={"IPHONE","MAC","IPAD","ACCESORIOS"};
	float precio;
}producto;

int main(void)
{
	setbuf(stdout,NULL);

	producto prod;
	int opciones;

	do
	{
		printf("\n==========ABM==========\n");
		printf("1. INICIALIZACION\n2. ALTA\n3. BAJA\n4. MODIFICACION\n5. LISTADO Gen\n"
				"6. LISTADO ORDENADO POR PRECIO\n7. LISTADO ORDENADO POR DESCRIPCION\n8. SALIR\n");
		if(utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 1, 8, 1)==0)
		{
			switch(opciones)
			{
				case 1:
					prod.idProducto = 1;
					strcpy(prod.descripcion,"Modelo S21");
					prod.precio = 1500;
					break;

				case 2:

					break;

				case 3:

					break;

				case 4:

					break;

				case 5:

					break;

				case 6:

					break;

				case 7:

					break;

				case 8:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;
			}
		}

	}while(opciones != 8);


	return EXIT_SUCCESS;
}
