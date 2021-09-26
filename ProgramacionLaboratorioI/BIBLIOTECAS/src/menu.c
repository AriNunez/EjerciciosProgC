/*
 * menu.c
 *
 *  Created on: 15 sep. 2021
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include "eGen.h"

#define TAM_ESTRUCTURA 5

void MenuOpcionesVectores()
{

	printf("==========OPCIONES==========\n");
	printf("1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n");


	/*switch(opcion)
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
	}*/
}

void MenuOpcionesEstructuras()
{
	int opciones;
	int idAutoincremental;
	eGen Gen[TAM_ESTRUCTURA];

	idAutoincremental = 0;

	eGen_Inicializar(Gen, TAM_ESTRUCTURA);

	do
	{
		printf("\n==========ABM==========\n");
		printf("1. ALTA\n2. BAJA\n3. MODIFICACION\n4. LISTADO ALTAS\n5. ORDENAR\n0. SALIR\n");
		if(utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 5, 1)==0)
		{
			switch(opciones)
			{
				case 1:
					if(eGen_Alta(Gen, TAM_ESTRUCTURA, idAutoincremental)==1)
					{
						printf("\nGen DADO DE ALTA EXITOSAMENTE\n");
					}
					else
					{
						printf("\n¡ERROR! NO HAY MAS ESPACIO PARA ALMACENAR Gen\n");
					}
					break;

				case 2:
					if(eGen_Baja(Gen, TAM_ESTRUCTURA)==1)
					{
						printf("\nBAJA DE Gen EXITOSA\n");
						eGen_MostrarTodos(Gen, TAM_ESTRUCTURA);
					}
					else
					{
						printf("\nBAJA DE Gen CANCELADA\n");
					}
					break;

				case 3:
					if(eGen_Modificacion(Gen, TAM_ESTRUCTURA)==1)
					{
						printf("\nGen MODIFICADO EXITOSAMENTE\n");
						eGen_MostrarTodos(Gen, TAM_ESTRUCTURA);
					}
					else
					{
						printf("\nMODIFICACION DE Gen CANCELADA\n");
					}
					break;

				case 4:
					eGen_MostrarTodos(Gen, TAM_ESTRUCTURA);
					break;

				case 5:

					break;

				case 0:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;
			}
		}

	}while(opciones != 0);
}
