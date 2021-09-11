/*
 * vectores.c
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//#include "verificaciones.h"

void CargarVectorEnteros(int vector[],int tam,char* mensaje,char* mensajeError,int minimo, int maximo,int reintentos)
{
    int i;
    int bufferInt;

    for(i = 0;i<tam;i++)
    {
       if(utn_getInt(&bufferInt, mensaje, mensajeError, minimo, maximo, reintentos)==0)
       {
    	   vector[i] =  bufferInt;
       }
       else
       {
    	   printf("\n\t�ERROR EN LA CARGA!");
    	   break;
       }
    }
}

int BuscarMaximo(int vector[],int tam)
{
	int i;
	int maximo;

	for(i = 0;i<tam;i++)
	    {
	        if(vector[i] > maximo||i==0)
	        {
	            maximo = vector[i];
	        }
	    }
	return maximo;
}
int BuscarMinimo(int vector[],int tam)
{
	int i;
	int minimo;

	for(i = 0;i<tam;i++)
	    {
	        if(vector[i] < minimo||i==0)
	        {
	        	minimo = vector[i];
	        }
	    }
	return minimo;
}
void MostrarVector(int vector[],int tam)
{
	int i;

	for(i = 0;i<tam;i++)
	{
		printf("%d\t",vector[i]);
	}

}
void MostrarIndicesDelValor(int vector[],int tam,int valor)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(vector[i]==valor)
		{
			printf("\nIndices de Valor: %d",i);
		}
	}
}
void InicializarVector(int vector[],int tam,int valorInicial)
{
	int i;
	for(i=0;i<tam;i++)
	{
		vector[i]=valorInicial;
	}
}

