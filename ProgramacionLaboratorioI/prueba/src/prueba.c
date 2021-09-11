/*
 ============================================================================
 Name        : prueba.c
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

int main(void)
{
	setbuf(stdout,NULL);

	int listaNumeros[TAM];

	CargarVectorEnteros(listaNumeros, TAM, "\nIngrese un numero entre 0 y 10", "\nError! No se encuentra dentro del rango", 0, 10, 2);
	MostrarVector(listaNumeros, TAM);

	return EXIT_SUCCESS;
}
