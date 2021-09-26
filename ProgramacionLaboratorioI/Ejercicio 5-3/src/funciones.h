/*
 * funciones.h
 *
 *  Created on: 11 sep. 2021
 *      Author: user
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void CargarVectorEnteros(int vector[],int tam,int numeroExcluido);
int IngresoNumero(char* mensaje,int min,int max);
int IngresoNumeroExcluyente(char* mensaje,int numeroExcluido);
void InicializarVector(int vector[],int tam,int valorInicial);
void MostrarVector(int vector[],int tam,int estado);

void ConfirmacionParaSeguir(char* continuar);
int VerificarPosicionLibre(int posicionParaVerificar);
int PromedioPositivos (int vector[],int tam,float* pResultado);
int SumaAntecesoresNegativos(int vector[],int tam,int* pResultado);
int BuscarMinimoNegativo(int vector[],int tam,int* pMinimo,int* pIndex);

#endif /* FUNCIONES_H_ */
