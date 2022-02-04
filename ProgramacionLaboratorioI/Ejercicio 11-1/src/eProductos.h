/*
 * eProductos.h
 *
 *  Created on: 25 sep. 2021
 *      Author: user
 */

#ifndef EPRODUCTOS_H_
#define EPRODUCTOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eTipos.h"

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define TAM_CADENACHAR 50
#define EEUU 1
#define CHINA 2
#define OTRO 3


//---ESTRUCTURA---//
typedef struct {
	int idProductos;
	char descripcion[TAM_CADENACHAR];
	int nacionalidad;
	float precio;
	int isEmpty;
	int idTipos;
}eProductos;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eProductos_Inicializar(eProductos vector[],int tam);
int eProductos_ObtenerIndexLibre(eProductos vector[],int tam);
int eProductos_BuscarPorID(eProductos vector[],int tam,int id);
void eProductos_MostrarUno(eProductos elemento);
int eProductos_MostrarTodos(eProductos vector[],int tam);

//---ABM---//

int eProductos_CargarDatos(eProductos* elemento);
int eProductos_ModificarUno(eProductos elementoParaModificar,eProductos* elementoModificado);
int eProductos_Alta(eProductos vector[],int tam,int idTipos,int* indiceParaRetornar);
int eProductos_Baja(eProductos vector[],int tam);
int eProductos_Modificacion(eProductos vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//

int eProductos_InformarProductoPorPrecio(eProductos vector[],int tam,float precioBuscado);
int eProductos_BuscarPrecioMasAlto(eProductos vector[],int tam,float* precioBuscado);

//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eProductos_OrdenarGenPorCriterioFIAscendente(eProductos vector[], int tam);
int eProductos_OrdenarGenPorCriterioFIDescendiente(eProductos vector[], int tam);
int eProductos_OrdenarGenPorCriterioCharAscendente(eProductos vector[], int tam);
int eProductos_OrdenarGenPorCriterioCharDescendente(eProductos vector[], int tam);




#endif /* EPRODUCTOS_H_ */
