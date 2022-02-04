/*
 * eTipos.h
 *
 *  Created on: 6 oct. 2021
 *      Author: user
 */

#ifndef ETIPOS_H_
#define ETIPOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define TAM_CADENACHAR 50

//---ESTRUCTURA---//
typedef struct {
	int idTipos;
	char descripcion[TAM_CADENACHAR];
	int isEmpty;
}eTipos;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eTipos_Inicializar(eTipos vector[],int tam);
int eTipos_ObtenerIndexLibre(eTipos vector[],int tam);
int eTipos_BuscarPorID(eTipos vector[],int tam,int id);
void eTipos_MostrarUno(eTipos elemento);
int eTipos_MostrarTodos(eTipos vector[],int tam);

//---ABM---//

int eTipos_CargarDatos(eTipos* elemento);
int eTipos_ModificarUno(eTipos elementoParaModificar,eTipos* elementoModificado);
int eTipos_Alta(eTipos vector[],int tam,int* idAutoincremental);
int eTipos_Baja(eTipos vector[],int tam);
int eTipos_Modificacion(eTipos vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eTipos_OrdenarTiposPorCriterioFIAscendente(eTipos vector[], int tam);
int eTipos_OrdenarTiposPorCriterioFIDescendiente(eTipos vector[], int tam);
int eTipos_OrdenarTiposPorCriterioCharAscendente(eTipos vector[], int tam);
int eTipos_OrdenarTiposPorCriterioCharDescendente(eTipos vector[], int tam);

#endif /* ETIPOS_H_ */
