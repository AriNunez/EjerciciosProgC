/*
 * vectores.c
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "verificaciones.h"

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


void MostrarCantidadPositivosNegativos (int vector[],int tam)

{
	int i;
	int contadorPositivos = 0;
	int contadorNegativos = 0;

	for(i = 0;i<tam;i++)
	{
		if(VerificarSigno(vector[i])==1)
		{
			contadorPositivos++;
		}
		else
		{
			if(VerificarSigno(vector[i])==-1)
			{
				contadorNegativos++;
			}
		}
	}
	printf("\na)Cantidad de positivos:%d\tCantidad de negativos:%d",contadorPositivos,contadorNegativos);
}

int SumarPares(int vector[],int tam)
{
	int i;
	int acumuladorPares = 0;

	for(i = 0; i<tam;i++)
	{
		if(VerificarParidad(vector[i])==1)
		{
			acumuladorPares = acumuladorPares + vector[i];
		}
	}
	return acumuladorPares;
}

int BuscarMayorImpar(int vector[],int tam,int* pMaximo)
{
	int i;
	int flagMayorImpar;

	flagMayorImpar = 0;

	for(i = 0;i<tam;i++)
	{
		if(VerificarParidad(vector[i])==0 && (flagMayorImpar==0 || vector[i]>*pMaximo))
		{
				*pMaximo = vector[i];
				flagMayorImpar = 1;
		}
	}

	return flagMayorImpar;
}

void ListarNumerosPares(int vector[],int tam)
{
	int i;

	for(i = 0;i<tam;i++)
	{
		if(VerificarParidad(vector[i])==1)
		{
			printf("%d\t",vector[i]);
		}
	}
}

void ListarNumerosPosicionesImpares(int vector[],int tam)
{
	int i;

	for(i = 0;i<tam;i++)
	{
		if(VerificarParidad(i)==0)
		{
			printf("%d\t",vector[i]);
		}
	}
}
