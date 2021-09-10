/*
 * vectores.h
 *
 *  Created on: 8 sep. 2021
 *      Author: user
 */

#ifndef VECTORES_H_
#define VECTORES_H_

void CargarVectorEnteros(int vector[],int tam,char* mensaje,int min, int max);
int BuscarMaximo(int vector[],int tam);
void MostrarIndicesDelValor(int vector[],int tam,int valor);
void MostrarVector(int vector[],int tam);

void MostrarCantidadPositivosNegativos (int vector[],int tam);
int SumarPares(int vector[],int tam);
int BuscarMayorImpar(int vector[],int tam,int* pMaximo);
void ListarNumerosPares(int vector[],int tam);
void ListarNumerosPosicionesImpares(int vector[],int tam);


#endif /* VECTORES_H_ */
