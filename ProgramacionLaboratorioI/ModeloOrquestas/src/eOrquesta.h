/*
 * eOrquesta.h
 *
 *  Created on: 20 oct. 2021
 *      Author: user
 */

#ifndef EORQUESTA_H_
#define EORQUESTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define TAM_CADENACHAR 30

//---ESTRUCTURA---//
typedef struct {
	int idOrquesta;
	char nombreOrquesta[TAM_CADENACHAR];
	char lugar[TAM_CADENACHAR];
	int tipoOrquesta;
	int isEmpty;
}eOrquesta;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eOrquesta_Inicializar(eOrquesta vector[],int tam);
int eOrquesta_ObtenerIndexLibre(eOrquesta vector[],int tam);
int eOrquesta_BuscarPorID(eOrquesta vector[],int tam,int id);
void eOrquesta_MostrarUno(eOrquesta elemento);
int eOrquesta_MostrarTodos(eOrquesta vector[],int tam);

//---ABM---//

int eOrquesta_CargarDatos(eOrquesta* elemento);
int eOrquesta_ModificarUno(eOrquesta elementoParaModificar,eOrquesta* elementoModificado);
int eOrquesta_Alta(eOrquesta vector[],int tam,int* idAutoincremental);
int eOrquesta_Baja(eOrquesta vector[],int tam);
int eOrquesta_Modificacion(eOrquesta vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eOrquesta_OrdenarOrquestaPorCriterioFIAscendente(eOrquesta vector[], int tam);
int eOrquesta_OrdenarOrquestaPorCriterioFIDescendiente(eOrquesta vector[], int tam);
int eOrquesta_OrdenarOrquestaPorCriterioCharAscendente(eOrquesta vector[], int tam);
int eOrquesta_OrdenarOrquestaPorCriterioCharDescendente(eOrquesta vector[], int tam);

#endif /* EORQUESTA_H_ */
