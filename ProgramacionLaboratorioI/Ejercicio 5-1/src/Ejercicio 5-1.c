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

#define T 5

int main()
{
	setbuf(stdout,NULL);

	int arrayNumeros[T];
    int maximo;
    int valorIngresado = 5;

    CargarVector(arrayNumeros,T);
    MostrarVector(arrayNumeros, T);

    maximo = BuscarMaximoo(arrayNumeros, T);

    MostrarIndicesDelValor(arrayNumeros, T, valorIngresado);


    printf("\nEl maximo es: %d",maximo);


    return 0;
}

