/*
 ============================================================================
 Name        : Ejercicio2-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/******************************************************************************
Ariel Nuñez 1E-Ejercicio 2-3

Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y Genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PRECIO_PASAJERO 600


int main()
{
	setbuf(stdout, NULL);
    int continuar;
    int numeroCliente;
    char estadoCivil;
    int edad;
    float tempCorporal;
    char Genero;

    int contadorPasajeros = 0;

    int contadorMayores = 0;
    int contadorViudosMayores = 0;

    int flagMujerSolteraJoven = 0;
    int edadMujerSolteraJoven;
    int numeroClienteSoltera;

    int totalSinDescuento;
    float totalConDescuento;

    float porcentajePasajerosMayores;


    do
    {
        printf("Ingrese Numero de Cliente: ");
        scanf("%d",&numeroCliente);


        printf("\nIngrese el Estado Civil (s/c/v): ");
        fflush(stdin);
        scanf("%c",&estadoCivil);
        while(estadoCivil!='s' && estadoCivil!='c' && estadoCivil!='v')
        {
            printf("\nError! Ingrese el Estado Civil (s/c/v): ");
            fflush(stdin);
            scanf("%c",&estadoCivil);
        }

        printf("\nIngrese la Edad (Solo mayores de 17 años): ");
        scanf("%d",&edad);
        while(edad < 18 || edad > 110)
        {
            printf("\nError! Ingrese la Edad (Solo mayores de 17 años): ");
            scanf("%d",&edad);
        }

        printf("\nIngrese la Temperatura Corporal: ");
        scanf("%f",&tempCorporal);
        while(tempCorporal < 35 || tempCorporal > 42)
        {
            printf("\nError! Ingrese la Temperatura Corporal: ");
            scanf("%f",&tempCorporal);
        }

        printf("\nIngrese el Genero (f/m/o): ");
        fflush(stdin);
        scanf("%c",&Genero);
        while(Genero != 'f' && Genero != 'm' && Genero != 'o')
        {
            printf("\nError! Ingrese el Genero (f/m/o): ");
            fflush(stdin);
            scanf("%c",&Genero);
        }

        contadorPasajeros++;

        if(edad >= 60)
        {
            contadorMayores++;
            if(estadoCivil == 'v')
            {
                contadorViudosMayores++;
            }
        }

        if(Genero == 'f' && estadoCivil == 's')
        {
            if(flagMujerSolteraJoven == 0 || edad < edadMujerSolteraJoven)
            {
                edadMujerSolteraJoven = edad;
                numeroClienteSoltera = numeroCliente;
                flagMujerSolteraJoven = 1;
            }

        }

        printf("\nDesea continuar ingresando Pasajeros? (1 o 0):");
        scanf("%d",&continuar);
        while(continuar != 1 && continuar != 0)
        {
            printf("\nError! Desea continuar ingresando Pasajeros? (1 o 0):");
            scanf("%d",&continuar);
        }

    }while(continuar == 1);

    totalSinDescuento = contadorPasajeros * PRECIO_PASAJERO;

    porcentajePasajerosMayores = (contadorMayores * 100) / contadorPasajeros;

    printf("\n================INFORMES================");

    if(contadorViudosMayores > 0)
    {
        printf("\nCantidad de personas Viudas mayores de 60 años: %d",contadorViudosMayores);
    }

    if(flagMujerSolteraJoven==1)
    {
        printf("\nMujer Soltera Mas Joven--> Edad: %d||Numero de Cliente: %d",edadMujerSolteraJoven,numeroClienteSoltera);
    }

    printf("\nPrecio Total sin Descuento: %d",totalSinDescuento);

    if(porcentajePasajerosMayores >= 50)
    {
        totalConDescuento = totalSinDescuento * 0.75;
        printf("\nPrecio Total con Descuento por Mayores de 60: %.2f",totalConDescuento);
    }
    return 0;
}
