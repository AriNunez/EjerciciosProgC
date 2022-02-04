/*
 * eTipos.c
 *
 *  Created on: 6 oct. 2021
 *      Author: user
 */

#include "eTipos.h"
#include "utn.h"

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eTipos_Inicializar(eTipos vector[],int tam)
{
	int i;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			vector[i].isEmpty = LIBRE;
		}
	}
}

int eTipos_ObtenerIndexLibre(eTipos vector[],int tam)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int eTipos_BuscarPorID(eTipos vector[],int tam,int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idTipos == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eTipos_MostrarUno(eTipos elemento)
{
	printf("%5d\t%5s\n",elemento.idTipos,elemento.descripcion);
}

int eTipos_MostrarTodos(eTipos vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Tipos");
	printf("%5s\t%5s\n\n","ID","DESCRIPCION"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eTipos_MostrarUno(vector[i]);
				cantidad++;
			}
		}
	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

//---ABM---//

int eTipos_CargarDatos(eTipos* elemento)
{
	int retorno;
	eTipos auxiliar;

	retorno = 0;

	if(elemento != NULL)
	{
		if(utn_getTexto(auxiliar.descripcion, "Ingrese la descripcion del tipo de producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
		{
			retorno = 1;
			*elemento = auxiliar;
		}
	}

	return retorno;
}

int eTipos_ModificarUno(eTipos elementoParaModificar,eTipos* elementoModificado)
{
	int retorno;
	int opciones;
	eTipos auxiliar;

	auxiliar = elementoParaModificar;
	retorno = 0;

	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
	{
		printf("\n¿Que desea modificar?\n1. TODO EL TIPO DE PRODUCTO\n2. SOLO UNA CARACTERISTICA\n\n");
		if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 2, 2)==0)
		{
			switch(opciones)
			{
				case 1:
					if(eTipos_CargarDatos(&auxiliar)==1)
					{
						retorno = 1;
						*elementoModificado = auxiliar;
					}

					break;

				case 2:
					printf("\n¿Que caracteristica desea modificar?\n1. DESCRIPCION\n\n");
					if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 1, 1)==0)
					{
						switch (opciones)
						{
							case 1:
								if(utn_getTexto(auxiliar.descripcion, "Ingrese la nueva descripcion: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
								}
								break;
						}
					}
					break;
			}
		}

	}
	return retorno;
}

int eTipos_Alta(eTipos vector[],int tam,int* idAutoincremental)
{
	int retorno;
	eTipos auxiliar;
	int index;
	int idAux;

	retorno = 0;
	index = eTipos_ObtenerIndexLibre(vector, tam);
	idAux = *idAutoincremental+1;

	if(index != -1)
	{
		if(eTipos_CargarDatos(&auxiliar)==1)
		{
			retorno = 1;
		}

		if(retorno == 1)
		{
			auxiliar.idTipos = idAux;

			auxiliar.isEmpty = OCUPADO;

			vector[index] = auxiliar;

			*idAutoincremental = idAux;
		}
	}
	return retorno;
}

int eTipos_Baja(eTipos vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eTipos_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eTipos_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eTipos_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int eTipos_Modificacion(eTipos vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	eTipos buffer;

	if(eTipos_MostrarTodos(vector, tam)==1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eTipos_BuscarPorID(vector, tam, idModificacion)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0);
			}

			index = eTipos_BuscarPorID(vector, tam, idModificacion);

			if(eTipos_ModificarUno(vector[index], &buffer)==1)
			{
				if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
				{
					vector[index] = buffer;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

/*int eTipos_OrdenarTiposPorCriterioFIAscendente(eTipos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eTipos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idTipos > vector[i+1].idTipos) //>>>CAMBIAR EL .idTipos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eTipos_OrdenarTiposPorCriterioFIDescendiente(eTipos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eTipos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idTipos < vector[i+1].idTipos) //>>>CAMBIAR EL .idTipos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eTipos_OrdenarTiposPorCriterioCharAscendente(eTipos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eTipos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(strcmp(vector[i].idTipos,vector[i+1].idTipos)>0) //>>>CAMBIAR EL .idTipos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eTipos_OrdenarTiposPorCriterioCharDescendente(eTipos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eTipos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(strcmp(vector[i].idTipos,vector[i+1].idTipos)<0) //>>>CAMBIAR EL .idTipos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}
*/


