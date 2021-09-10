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

#define TAM 10

int main(void)
{
	setbuf(stdout,NULL);

	int listaNumeros[TAM];
	int acumuladorPares = 0;
	int mayorImpar;


	CargarVectorEnteros(listaNumeros, TAM, "\nIngrese un numero entre -1000 y 1000: ", -1000, 1000);

	MostrarCantidadPositivosNegativos(listaNumeros, TAM);

	acumuladorPares = SumarPares(listaNumeros, TAM);
	printf("\nb)El resultado de la suma entre numeros pares ingresados es:%d",acumuladorPares);

	if(BuscarMayorImpar(listaNumeros, TAM, &mayorImpar)==1)
	{
		printf("\nc)El mayor numero impar es:%d",mayorImpar);
	}
	else
	{
		printf("\nc)No se ingreso ningun numero impar");
	}


	printf("\nd)Listado de los numeros ingresados\n");
	MostrarVector(listaNumeros, TAM);

	printf("\ne)Listado de los numeros pares\n");
	ListarNumerosPares(listaNumeros, TAM);

	printf("\nf)Listado de los numeros de las posiciones impares\n");
	ListarNumerosPosicionesImpares(listaNumeros, TAM);

	return EXIT_SUCCESS;
}
