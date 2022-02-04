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
#include "eProductos.h"
#include "utn.h"

#define TAM_ESTRUCTURA 15

int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	eProductos Productos[TAM_ESTRUCTURA];
	int retornoOpciones;

	eProductos_Inicializar(Productos, TAM_ESTRUCTURA);

	do
	{
		printf("\n==========ABM==========\n");
		printf("1. ALTA\n2. BAJA\n3. MODIFICACION\n4. LISTADO ALTAS\n5. ORDENAR\n0. SALIR\n");
		retornoOpciones = utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 5, 1);
		if(retornoOpciones==0)
		{
			switch(opciones)
			{
				case 1:
					if(eProductos_Alta(Productos, TAM_ESTRUCTURA)==1)
					{
						printf("\nProducto DADO DE ALTA EXITOSAMENTE\n");
					}
					else
					{
						printf("\n¡ERROR! NO HAY MAS ESPACIO PARA ALMACENAR Producto\n");
					}
					break;

				case 2:
					if(eProductos_Baja(Productos, TAM_ESTRUCTURA)==1)
					{
						printf("\nBAJA DE Producto EXITOSA\n");
						eProductos_MostrarTodos(Productos, TAM_ESTRUCTURA);
					}
					else
					{
						printf("\nBAJA DE Producto CANCELADA\n");
					}
					break;

				case 3:
					if(eProductos_Modificacion(Productos, TAM_ESTRUCTURA)==1)
					{
						printf("\nProducto MODIFICADO EXITOSAMENTE\n");
						eProductos_MostrarTodos(Productos, TAM_ESTRUCTURA);
					}
					else
					{
						printf("\nMODIFICACION DE Producto CANCELADA\n");
					}
					break;

				case 4:
					eProductos_MostrarTodos(Productos, TAM_ESTRUCTURA);
					break;

				default:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;

			}
		}

	}while(opciones != 0);

	return EXIT_SUCCESS;
}
