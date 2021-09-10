/*
 * vectores.c
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

void CargarVectorEnteros(int vector[],int tam)
{
    int i;

    for(i = 0;i<tam;i++)
    {
       printf("\nIngrese un numero: ");
       scanf("%d",&vector[i]);
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
