/*
 * ordenamiento.c
 *
 *  Created on: 15 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

int or_OrdenarVectorEnterosAscendente(int vector[], int tam)
 {
 	int flagSwap;
 	int i;
 	int retorno;
 	int bufferInt;
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
 				if(vector[i] > vector[i+1])
 				{
 					flagSwap = 1;
 					bufferInt = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = bufferInt;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
 }

int or_OrdenarVectorEnterosDescendente(int vector[], int tam)
 {
 	int flagSwap;
 	int i;
 	int retorno;
 	int bufferInt;
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
 				if(vector[i] < vector[i+1])
 				{
 					flagSwap = 1;
 					bufferInt = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = bufferInt;
 				}
 			}
 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
 }
