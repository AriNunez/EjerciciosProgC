/*
 * vectores.c
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void CargarVectorEnteros(int vector[],int tam,char* mensaje,int min, int max)
{
    int i;

    for(i = 0;i<tam;i++)
    {
       vector[i] = IngresoNumero(mensaje, min, max);
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

int SumarValoresVector (int vector[],int tam)
{
	int i;
	int acumulador;

	acumulador = 0;

	for(i = 0;i<tam;i++)
	{
		acumulador = acumulador + vector[i];
	}

	return acumulador;
}
