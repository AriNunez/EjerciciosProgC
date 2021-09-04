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

int Sumar1 (int primerNumero,int segundoNumero);
int Sumar2 (void);
void Sumar3 (int primerNumero,int segundoNumero);
void Sumar4 (void);

int main(void)
{
	setbuf(stdout,NULL);

	int primerNumero;
	int segundoNumero;
	int resultado;

	//PRIMER CASO
	printf("\nIngrese un numero: ");
	scanf("%d",&primerNumero);
	printf("\nIngrese otro numero: ");
	scanf("%d",&segundoNumero);

	resultado = Sumar1(primerNumero, segundoNumero);

	printf("\nEl resultado de la suma es: %d",resultado);

	//SEGUNDO CASO
	resultado = Sumar2();

	printf("\nEl resultado de la suma es: %d",resultado);

	//TERCER CASO
	printf("\nIngrese un numero: ");
	scanf("%d",&primerNumero);
	printf("\nIngrese otro numero: ");
	scanf("%d",&segundoNumero);

	Sumar3(primerNumero, segundoNumero);

	//CUARTO CASO
	Sumar4();

	return EXIT_SUCCESS;
}

int Sumar1 (int primerNumero,int segundoNumero)
{
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;
}

int Sumar2 (void)
{
	int resultado;
	int primerNumero;
	int segundoNumero;

	printf("\nIngrese un numero: ");
	scanf("%d",&primerNumero);
	printf("\nIngrese otro numero: ");
	scanf("%d",&segundoNumero);

	resultado = primerNumero + segundoNumero;

	return resultado;
}

void Sumar3 (int primerNumero,int segundoNumero)
{
	int resultado;

	resultado = primerNumero + segundoNumero;

	printf("\nEl resultado de la suma es: %d",resultado);
}

void Sumar4 (void)
{
	int resultado;
	int primerNumero;
	int segundoNumero;

	printf("\nIngrese un numero: ");
	scanf("%d",&primerNumero);
	printf("\nIngrese otro numero: ");
	scanf("%d",&segundoNumero);

	resultado = primerNumero + segundoNumero;

	printf("\nEl resultado de la suma es: %d",resultado);
}
