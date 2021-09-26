/*
 * eProductos.c
 *
 *  Created on: 25 sep. 2021
 *      Author: user
 */

#include "eProductos.h"


									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eProductos_Inicializar(eProductos vector[],int tam)
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

int eProductos_ObtenerID(int ID)
{
	ID++;

	return ID;
}

int eProductos_ObtenerIndexLibre(eProductos vector[],int tam)
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

int eProductos_BuscarPorID(eProductos vector[],int tam,int id)
{
	int i;
	int retorno;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idProductos == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eProductos_MostrarUno(eProductos elemento)
{
	printf("%5d\n",elemento.idProductos);
}

int eProductos_MostrarTodos(eProductos vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;

	puts("\n\t>>Listado Productos");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eProductos_MostrarUno(vector[i]);
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

int eProductos_MostrarDadosDeBaja(eProductos vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;

	puts("\n\t>>Listado Productos");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == BAJA)
			{
				eProductos_MostrarUno(vector[i]);
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

eProductos eProductos_CargarDatos(void)
{
	eProductos auxiliar;

	//CARGAR DATOS NECESARIOS PARA EL ALTA-->>IMPORTANTE<<--NO CARGAR DATOS NI ESTADO


	return auxiliar;
}

eProductos eProductos_ModificarUno(eProductos elemento)
{
	eProductos auxiliar;

	auxiliar = elemento;

	return auxiliar;
}

int eProductos_Alta(eProductos vector[],int tam,int ID)
{
	int retorno;
	eProductos auxiliar;
	int index;

	retorno = 0;
	index = eProductos_ObtenerIndexLibre(vector, tam);

	if(index != -1)
	{
		auxiliar = eProductos_CargarDatos();

		auxiliar.idProductos = eProductos_ObtenerID(ID);

		auxiliar.isEmpty = OCUPADO;

		vector[index] = auxiliar;

		retorno = 1;
	}
	return retorno;
}

int eProductos_Baja(eProductos vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eProductos_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eProductos_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eProductos_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = BAJA;
			retorno = 1;
		}
	}
	return retorno;
}

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int eProductos_OrdenarProductosPorCriterioFIAscendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
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
 				if(vector[i].idProductos > vector[i+1].idProductos) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eProductos_OrdenarProductosPorCriterioFIDescendiente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
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
 				if(vector[i].idProductos < vector[i+1].idProductos) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eProductos_OrdenarProductosPorCriterioCharAscendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
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
 				if(strcmp(vector[i].idProductos,vector[i+1].idProductos)>0) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eProductos_OrdenarProductosPorCriterioCharDescendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
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
 				if(strcmp(vector[i].idProductos,vector[i+1].idProductos)<0) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eProductos_ListadoProductosCriterios(eProductos vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Productos");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				eProductos_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}

