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

#define TAM 5
#define INICIAL -1

void CargarVectorEnteros(int vector[],int tam);
int IngresoNumero(char* mensaje,int min,int max);
void InicializarVector(int vector[],int tam,int valorInicial);
void MostrarVector(int vector[],int tam,int estado);

int main(void)
{
	setbuf(stdout,NULL);

	int listaNumeros[TAM];
	InicializarVector(listaNumeros, TAM, -1);




	return EXIT_SUCCESS;
}
void CargarVectorEnteros(int vector[],int tam)
{
    int index;
    int auxiliar;
    char seguir;

    do
    {
    	index = IngresoNumero("\nIngrese un numero entre -1000 y 1000: ", -1000, 1000)
    	auxiliar = IngresoNumero("\nIndique la posicion a guardar: ", 1, 5);
    	vector[index - 1] = auxiliar;

    	printf("\nDesea ingresar otro?");
    	fflush(stdin);
    	scanf("%c",&seguir);

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
