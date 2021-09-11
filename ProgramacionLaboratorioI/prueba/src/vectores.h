/*
 * vectores.h
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#ifndef VECTORES_H_
#define VECTORES_H_

void CargarVectorEnteros(int vector[],int tam,char* mensaje,char* mensajeError,int minimo, int maximo,int reintentos);
int BuscarMaximo(int vector[],int tam);
int BuscarMinimo(int vector[],int tam);
void MostrarIndicesDelValor(int vector[],int tam,int valor);
void MostrarVector(int vector[],int tam);
void InicializarVector(int vector[],int tam,int valorInicial);

#endif /* VECTORES_H_ */
