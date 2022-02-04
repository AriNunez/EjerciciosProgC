/*
 * Productos-Tipos.c
 *
 *  Created on: 7 oct. 2021
 *      Author: user
 */

#include "ProdTipos.h"

int ProdTipos_Alta(eProductos vectorProductos[],int tamProductos,eTipos vectorTipos[],int tamTipos,int* idAutoincremental)
{
	int retorno;
	int flagMostrados;
	int idTipos;
	int idAux;
	int index;

	retorno = 0;
	flagMostrados = 0;
	idAux = *idAutoincremental+1;

	if(vectorProductos != NULL && tamProductos > 0 && vectorTipos != NULL && tamTipos > 0)
	{
		if(eTipos_MostrarTodos(vectorTipos, tamTipos)==1)
		{
			flagMostrados = 1;
		}

		if(flagMostrados == 1)
		{
			if(utn_getInt(&idTipos, "\nIngrese un ID de Tipos para asignar al producto: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
			{
				while(eTipos_BuscarPorID(vectorTipos, tamTipos, idTipos)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idTipos, "\nIngrese un ID de Tipos para asignar al producto: \n", "¡ERROR!\n", 1, 3000000, 0);
				}

				if(eProductos_Alta(vectorProductos, tamProductos,idTipos,&index)==1)
				{
					vectorProductos[index].idProductos = idAux;
					*idAutoincremental = idAux;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

void ProdTipos_MostrarUno(eProductos elementoProducto,eTipos elementoTipo)
{
	printf("%-5d%-20s%-5d%-10.2f%-5s\n",elementoProducto.idProductos,elementoProducto.descripcion,elementoProducto.nacionalidad,elementoProducto.precio,elementoTipo.descripcion);
}

int ProdTipos_MostrarTodos(eProductos vectorProductos[],int tamProductos,eTipos vectorTipos[],int tamTipos)
{
	int i;
	int retorno;
	int cantidad;
	int index;

	retorno = 0;
	cantidad = 0;

	if(vectorProductos != NULL && tamProductos > 0 && vectorTipos != NULL && tamTipos > 0)
	{
		puts("\n\t>>Listado Productos");
		printf("%-5s\t%-20s\t%-5s\t%-10s\t%-5s\n\n","ID","DESCRIPCION","NACIONALIDAD","PRECIO","TIPO"); //TITULOS DE COLUMNAS
		for(i=0;i<tamProductos;i++)
		{
			if(vectorProductos[i].isEmpty == OCUPADO)
			{
				index = eTipos_BuscarPorID(vectorTipos,tamTipos, vectorProductos[i].idTipos);
				ProdTipos_MostrarUno(vectorProductos[i],vectorTipos[index]);
				cantidad++;
			}
		}
	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}
