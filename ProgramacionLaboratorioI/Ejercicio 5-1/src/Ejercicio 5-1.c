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
#include "vectores.h"

#define TAM 5

int main()
{
	setbuf(stdout,NULL);

	int listaNumeros[TAM];
	int acumuladorVector;

	CargarVectorEnteros(listaNumeros, TAM, "\n Ingrese un numero: ", -100000, 100000);
	MostrarVector(listaNumeros, TAM);
	acumuladorVector = SumarValoresVector(listaNumeros, TAM);
	printf("\nLa sumatoria de los numeros ingresados es: %d",acumuladorVector);

	return EXIT_SUCCESS;
}

