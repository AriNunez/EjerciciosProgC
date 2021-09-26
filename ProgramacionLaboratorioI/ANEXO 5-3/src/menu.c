/*
 * menu.c
 *
 *  Created on: 15 sep. 2021
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "vectores.h"

#define TAM 5

void MenuOpciones()
{
	int opcion;
	int listaEdades[TAM];

	do
	{
		printf("\n==========OPCIONES==========\n");
		printf("1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n0-Salir\n");

		if(utn_getInt(&opcion, "\nSeleccione una opcion: ", "\nError! Seleccione una opcion valida: ", 0, 5, 2)==0)
		{
			switch(opcion)
			{
				case 1:
					printf("\nUsted ha seleccionado la opcion 1-Inicializar");
					if(InicializarVector(listaEdades, TAM, -1) == 1)
					{
						printf("\n¡Inicializacion exitosa!\n");
					}
					else
					{
						printf("\n¡Error al Inicializar!\n");
					}
					break;
				case 2:
					printf("\nUsted ha seleccionado la opcion 2-Cargar");
					CargarVectorEnteros(listaEdades, TAM, "\nIngrese una edad: ", "\n!Error! Ingrese una edad valida: ", 0, 120, 2);
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
	}while(opcion != 0);
}
