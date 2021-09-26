/*
 * funciones.c
 *
 *  Created on: 11 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "verificaciones.h"

void CargarVectorEnteros(int vector[],int tam,int numeroExcluido)
{
    int index;
    int auxiliar;
    char seguir;

    do
    {
    	index = IngresoNumero("\nIngrese una posicion a guardar el numero entre 1 y 10: ",(tam-(tam-1)),tam);
    	auxiliar = IngresoNumeroExcluyente("\nIngrese un numero distinto de 0: ", numeroExcluido);

    	if(VerificarPosicionLibre(vector[index - 1]) == 1)
    	{
    		vector[index - 1] = auxiliar;
    	}
    	else
    	{
    		printf("\nNo es posible cargar el numero en esa posicion!");
    	}

    	ConfirmacionParaSeguir(&seguir);

    }while(seguir == 's');

}
int IngresoNumero(char* mensaje,int min,int max)
{
	int numeroIngresado;

	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max)
	{
		printf("\nError!");
		printf("%s",mensaje);
		scanf("%d",&numeroIngresado);
	}

	return numeroIngresado;
}
int IngresoNumeroExcluyente(char* mensaje,int numeroExcluido)
{
	int numeroIngresado;

	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);

	while(numeroIngresado ==  numeroExcluido)
	{
		printf("\nError!");
		printf("%s",mensaje);
		scanf("%d",&numeroIngresado);
	}

	return numeroIngresado;
}

void InicializarVector(int vector[],int tam,int valorInicial)
{
	int i;
	for(i=0;i<tam;i++)
	{
		vector[i]=valorInicial;
	}
}
void MostrarVector(int vector[],int tam,int estado)
{
	int i;

	for(i = 0;i<tam;i++)
	{
		if(vector[i] != estado)
		printf("%d\t",vector[i]);
	}

}

void ConfirmacionParaSeguir(char* continuar)
{
	char seguir;

	do
	{
		printf("\nDesea ingresar otro? (s o n): ");
		fflush(stdin);
		scanf("%c",&seguir);

	}while(seguir != 's' && seguir != 'n' );

	*continuar = seguir;
}

int VerificarPosicionLibre(int posicionParaVerificar)
{
	int verificado;

	if(posicionParaVerificar == 0)
	{
		verificado = 1;
	}
	else
	{
		verificado = 0;
	}

	return verificado;
}

int PromedioPositivos (int vector[],int tam,float* pResultado)
{
	int i;
	int retorno;
	int acumuladorPositivos;
	int contadorPositivos;
	float promedio;

	acumuladorPositivos = 0;
	contadorPositivos = 0;
	retorno = 0;

	for(i=0;i<tam;i++)
	{
		if(VerificarSigno(vector[i])==1)
		{
			contadorPositivos++;
			acumuladorPositivos = acumuladorPositivos + vector[i];
			retorno = 1;
		}
	}

	promedio = (float)acumuladorPositivos / contadorPositivos;

	*pResultado = promedio;

	return retorno;
}
int SumaAntecesoresNegativos(int vector[],int tam,int* pResultado)
{
	int i;
	int minimo;
	int index;
	int retorno;
	int acumuladorAntecesores;

	retorno = 0;

	if(BuscarMinimoNegativo(vector, tam, &minimo, &index)==1)
	{
		retorno = 1;
		acumuladorAntecesores = minimo;
		for(i = 0;i<tam;i++)
		{
			if(i != index && vector[i] < 0)
			{
				acumuladorAntecesores = acumuladorAntecesores + vector[i];
			}
		}

		*pResultado = acumuladorAntecesores;
	}

	return retorno;
}
int BuscarMinimoNegativo(int vector[],int tam,int* pMinimo,int* pIndex)
{
	int i;
	int bufferMinimo;
	int bufferIndex;
	int flagMinimo;
	int retorno;

	retorno = 0;
	flagMinimo = 0;

	for(i = 0;i<tam;i++)
	    {
			if(VerificarSigno(vector[i])==-1)
			{
				if(vector[i] < bufferMinimo||flagMinimo==0)
				{
					bufferMinimo = vector[i];
					bufferIndex = i;
					flagMinimo = 1;
					retorno = 1;
				}
			}
	    }

	*pMinimo = bufferMinimo;
	*pIndex = bufferIndex;

	return retorno;
}
