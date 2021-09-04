/*
 * utn.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#include "utn.h"

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;
		do
		{
			printf("%s",mensaje);
			if()
			{

			}
		}while(reintentos >= 0);
	}


	return retorno;
}
