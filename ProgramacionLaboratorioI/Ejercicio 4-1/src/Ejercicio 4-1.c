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

int CalcularFactorial(int numeroIngresado);
int IngresoNumero(char* mensaje,int min,int max);

int main(void)
{
	setbuf(stdout,NULL);

	int numeroIngresado;
	int aux;
	int resultadoFactorial;

	resultadoFactorial = 1;

	numeroIngresado = IngresoNumero("\nIngrese un numero entre 0 y 10: ", 0, 15);

	aux = numeroIngresado;

	if(aux == 0)
	{
		resultadoFactorial = 1;
	}
	else
	{
		if (aux > 0)
		{
			while (aux > 0)
			{
				resultadoFactorial = resultadoFactorial * aux;
				aux--;
			}
		}
	}

	printf("\nEl factorial de %d es: %d",numeroIngresado,resultadoFactorial);


	return EXIT_SUCCESS;
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

int CalcularFactorial(int numeroIngresado)
{
	int resultado;

	if(numeroIngresado == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = numeroIngresado * CalcularFactorial(numeroIngresado-1);
	}

	return resultado;
}
