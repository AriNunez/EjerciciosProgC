/*
 * eGen.h
 *
 *  Created on: 23 sep. 2021
 *      Author: user
 */

#ifndef EGEN_H_
#define EGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//---ESTRUCTURA---//
typedef struct {
	int idGen;
	int isEmpty;
}eGen;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eGen_Inicializar(eGen vector[],int tam);
int eGen_ObtenerID(int ID);
int eGen_ObtenerIndexLibre(eGen vector[],int tam);
int eGen_BuscarPorID(eGen vector[],int tam,int id);
void eGen_MostrarUno(eGen elemento);
int eGen_MostrarTodos(eGen vector[],int tam);
int eGen_MostrarDadosDeBaja(eGen vector[],int tam);

//---ABM---//

eGen eGen_CargarDatos(void);
eGen eGen_ModificarUno(eGen elemento);
int eGen_Alta(eGen vector[],int tam,int ID);
int eGen_Baja(eGen vector[],int tam);
int eGen_Modificacion(eGen vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eGen_OrdenarGenPorCriterioFIAscendente(eGen vector[], int tam);
int eGen_OrdenarGenPorCriterioFIDescendiente(eGen vector[], int tam);
int eGen_OrdenarGenPorCriterioCharAscendente(eGen vector[], int tam);
int eGen_OrdenarGenPorCriterioCharDescendente(eGen vector[], int tam);

#endif /* EGEN_H_ */
