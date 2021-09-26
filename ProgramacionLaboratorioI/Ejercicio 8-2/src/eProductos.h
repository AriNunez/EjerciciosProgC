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

//---DEFINE---//
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//---ESTRUCTURA---//
typedef struct {
	int idProductos;
	int isEmpty;
}eProductos;

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eGen_Inicializar(eProductos vector[],int tam);
int eGen_ObtenerID(int ID);
int eGen_ObtenerIndexLibre(eProductos vector[],int tam);
int eGen_BuscarPorID(eProductos vector[],int tam,int id);
void eGen_MostrarUno(eProductos elemento);
int eGen_MostrarTodos(eProductos vector[],int tam);
int eGen_MostrarDadosDeBaja(eProductos vector[],int tam);

//---ABM---//

eProductos eGen_CargarDatos(void);
eProductos eGen_ModificarUno(eProductos elemento);
int eGen_Alta(eProductos vector[],int tam,int ID);
int eGen_Baja(eProductos vector[],int tam);
int eGen_Modificacion(eProductos vector[],int tam);

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//
int eGen_OrdenarGenPorCriterioFIAscendente(eProductos vector[], int tam);
int eGen_OrdenarGenPorCriterioFIDescendiente(eProductos vector[], int tam);
int eGen_OrdenarGenPorCriterioCharAscendente(eProductos vector[], int tam);
int eGen_OrdenarGenPorCriterioCharDescendente(eProductos vector[], int tam);

#endif /* EPRODUCTOS_H_ */
