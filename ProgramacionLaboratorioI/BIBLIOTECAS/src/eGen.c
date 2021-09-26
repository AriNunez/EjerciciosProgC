/*
 * eGen.c
 *
 *  Created on: 23 sep. 2021
 *      Author: user
 */

#include "eGen.h"


									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eGen_Inicializar(eGen vector[],int tam)
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

int eGen_ObtenerID(int ID)
{
	ID++;

	return ID;
}

int eGen_ObtenerIndexLibre(eGen vector[],int tam)
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

int eGen_BuscarPorID(eGen vector[],int tam,int id)
{
	int i;
	int retorno;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idGen == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eGen_MostrarUno(eGen elemento)
{
	printf("%5d\n",elemento.idGen);
}

int eGen_MostrarTodos(eGen vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;

	puts("\n\t>>Listado Gen");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eGen_MostrarUno(vector[i]);
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

int eGen_MostrarDadosDeBaja(eGen vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;

	puts("\n\t>>Listado Gen");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == BAJA)
			{
				eGen_MostrarUno(vector[i]);
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

eGen eGen_CargarDatos(void)
{
	eGen auxiliar;

	//CARGAR DATOS NECESARIOS PARA EL ALTA-->>IMPORTANTE<<--NO CARGAR DATOS NI ESTADO


	return auxiliar;
}

eGen eGen_ModificarUno(eGen elemento)
{
	eGen auxiliar;

	auxiliar = elemento;

	return auxiliar;
}

int eGen_Alta(eGen vector[],int tam,int ID)
{
	int retorno;
	eGen auxiliar;
	int index;

	retorno = 0;
	index = eGen_ObtenerIndexLibre(vector, tam);

	if(index != -1)
	{
		auxiliar = eGen_CargarDatos();

		auxiliar.idGen = eGen_ObtenerID(ID);

		auxiliar.isEmpty = OCUPADO;

		vector[index] = auxiliar;

		retorno = 1;
	}
	return retorno;
}

int eGen_Baja(eGen vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eGen_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eGen_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eGen_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = BAJA;
			retorno = 1;
		}
	}
	return retorno;
}

int eGen_Modificacion(eGen vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	eGen buffer;

	//TERMINAR ESTOOOOOOOOOOOO


}

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int eGen_OrdenarGenPorCriterioFIAscendente(eGen vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eGen buffer;
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
 				if(vector[i].idGen > vector[i+1].idGen) //>>>CAMBIAR EL .idGen EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eGen_OrdenarGenPorCriterioFIDescendiente(eGen vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eGen buffer;
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
 				if(vector[i].idGen < vector[i+1].idGen) //>>>CAMBIAR EL .idGen EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eGen_OrdenarGenPorCriterioCharAscendente(eGen vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eGen buffer;
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
 				if(strcmp(vector[i].idGen,vector[i+1].idGen)>0) //>>>CAMBIAR EL .idGen EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eGen_OrdenarGenPorCriterioCharDescendente(eGen vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eGen buffer;
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
 				if(strcmp(vector[i].idGen,vector[i+1].idGen)<0) //>>>CAMBIAR EL .idGen EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eGen_ListadoGenCriterios(eGen vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Gen");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				eGen_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}

