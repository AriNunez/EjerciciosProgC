/*
 * Productos-Tipos.h
 *
 *  Created on: 7 oct. 2021
 *      Author: user
 */

#ifndef PRODTIPOS_H_
#define PRODTIPOS_H_

#include "eProductos.h"
#include "eTipos.h"


int ProdTipos_Alta(eProductos vectorProductos[],int tamProductos,eTipos vectorTipos[],int tamTipos,int* idAutoincremental);

int ProdTipos_MostrarTodos(eProductos vectorProductos[],int tamProductos,eTipos vectorTipos[],int tamTipos);
void ProdTipos_MostrarUno(eProductos elementoProducto,eTipos elementoTipo);

#endif /* PRODTIPOS_H_ */
