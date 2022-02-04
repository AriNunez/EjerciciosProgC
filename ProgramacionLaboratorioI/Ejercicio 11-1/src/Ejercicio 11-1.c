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
#include "ProdTipos.h"

#define TAM_ESTRUCTURA 15

int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	eProductos Productos[TAM_ESTRUCTURA];
	eTipos Tipos[TAM_ESTRUCTURA];
	int retornoOpciones;
	int idProductos = 0;
	int idTipos = 100;
	int flagTiposCargados = 0;

	eProductos_Inicializar(Productos, TAM_ESTRUCTURA);
	eTipos_Inicializar(Tipos, TAM_ESTRUCTURA);

	do
	{
		printf("\n==========ABM==========\n");
		printf("1. ALTAS\n2. BAJA\n3. MODIFICACION\n4. LISTADO ALTAS\n5. ORDENAR\n0. SALIR\n");
		retornoOpciones = utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 5, 1);
		if(retornoOpciones==0)
		{
			switch(opciones)
			{
				case 1:
					printf("1. ALTA DE PRODUCTOS\n2. ALTA DE TIPOS\n0. SALIR\n");
					retornoOpciones = utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 2, 1);
					if(retornoOpciones==0)
					{
						switch(opciones)
						{
							case 1:
								if(flagTiposCargados==1)
								{
									if(ProdTipos_Alta(Productos, TAM_ESTRUCTURA, Tipos, TAM_ESTRUCTURA, &idProductos)==1)
									{
										printf("\nProducto DADO DE ALTA EXITOSAMENTE\n");
									}
									else
									{
										printf("\n¡ERROR! NO HAY MAS ESPACIO PARA ALMACENAR Producto\n");
									}
								}
								else
								{
									printf("\nALTA DE producto CANCELADA! SE DEBEN CARGAR TIPOS PRIMERO\n");
								}
								break;

							case 2:
								if(eTipos_Alta(Tipos, TAM_ESTRUCTURA, &idTipos)==1)
								{
									printf("\nTipo DADO DE ALTA EXITOSAMENTE\n");
									flagTiposCargados = 1;
								}
								else
								{
									printf("\n¡ERROR! NO HAY MAS ESPACIO PARA ALMACENAR Tipo\n");
								}

								break;
						}
					}
					break;

				case 2:
					printf("1. BAJA DE PRODUCTOS\n2. BAJA DE TIPOS\n0. SALIR\n");
					retornoOpciones = utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 2, 1);
					if(retornoOpciones==0)
					{
						switch(opciones)
						{
							case 1:
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

							case 2:
								if(eTipos_Baja(Tipos, TAM_ESTRUCTURA)==1)
								{
									printf("\nBAJA DE Tipo EXITOSA\n");
									if(eTipos_MostrarTodos(Tipos, TAM_ESTRUCTURA)==0)
									{
										flagTiposCargados = 0;
									}
								}
								else
								{
									printf("\nBAJA DE Tipo CANCELADA\n");
								}
								break;
						}
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
					printf("1. LISTADO DE PRODUCTOS\n2. LISTADO DE TIPOS\n0. SALIR\n");
					retornoOpciones = utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 0, 2, 1);
					if(retornoOpciones==0)
					{
						switch(opciones)
						{
							case 1:
								ProdTipos_MostrarTodos(Productos, TAM_ESTRUCTURA, Tipos, TAM_ESTRUCTURA);
								break;

							case 2:
								eTipos_MostrarTodos(Tipos, TAM_ESTRUCTURA);
								break;
						}
					}
					break;

				default:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;

			}
		}

	}while(opciones != 0);

	return EXIT_SUCCESS;
}
