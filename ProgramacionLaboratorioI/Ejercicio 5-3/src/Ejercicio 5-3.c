/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 10
#define INICIAL 0

int main(void)
{
	setbuf(stdout,NULL);

	int listaNumeros[TAM];
	float promedioPositivos;
	int sumaAntecesores;

	InicializarVector(listaNumeros, TAM, INICIAL);
	CargarVectorEnteros(listaNumeros, TAM, INICIAL);
	printf("\n-------------NUMEROS CARGADOS----------------\n");
	MostrarVector(listaNumeros, TAM, INICIAL);
	if(PromedioPositivos(listaNumeros, TAM, &promedioPositivos)==1)
	{
		printf("\nEl promedio de los positivos ingresados es: %.2f",promedioPositivos);
	}
	else
	{
		printf("\nNo fue posible calcular el promedio de los positivos!");
	}

	if(SumaAntecesoresNegativos(listaNumeros, TAM, &sumaAntecesores)==1)
	{
		printf("\nEl resultado de la suma entre el menor negativo y sus antecesores es: %d",sumaAntecesores);
	}
	else
	{
		printf("\nNo fue posible calcular el resultado de la suma entre el menor negativo y sus antecesores!");
	}

	return EXIT_SUCCESS;
}

