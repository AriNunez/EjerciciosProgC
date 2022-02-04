/*
 * eProductos.c
 *
 *  Created on: 25 sep. 2021
 *      Author: user
 */

#include "eProductos.h"

									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eProductos_Inicializar(eProductos vector[],int tam)
{
	int i;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			vector[i].isEmpty = LIBRE;
		}
	}
}

int eProductos_ObtenerIndexLibre(eProductos vector[],int tam)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int eProductos_BuscarPorID(eProductos vector[],int tam,int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idProductos == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eProductos_MostrarUno(eProductos elemento)
{
	printf("%-5d%-20s%-5d%-10.2f%-5d\n",elemento.idProductos,elemento.descripcion,elemento.nacionalidad,elemento.precio,elemento.idTipos);
}

int eProductos_MostrarTodos(eProductos vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	if(vector != NULL && tam > 0)
	{
		puts("\n\t>>Listado Productos");
		printf("%-5s\t%-20s\t%-5s\t%-10s\t%-5s\n\n","ID","DESCRIPCION","NACIONALIDAD","PRECIO","ID TIPOS"); //TITULOS DE COLUMNAS
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eProductos_MostrarUno(vector[i]);
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

//---ABM---//

int eProductos_CargarDatos(eProductos* elemento)
{
	int retorno;
	eProductos auxiliar;

	retorno = 0;

	if(elemento != NULL)
	{
		if(utn_getTexto(auxiliar.descripcion, "Ingrese la descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
		{
			printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
			if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
			{
				if(utn_getFloat(&auxiliar.precio, "Ingrese el precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
				{

					retorno = 1;
					*elemento = auxiliar;
				}
			}
		}
	}

	return retorno;
}

int eProductos_ModificarUno(eProductos elementoParaModificar,eProductos* elementoModificado)
{
	int retorno;
	int opciones;
	eProductos auxiliar;

	auxiliar = elementoParaModificar;
	retorno =  0;

	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
	{
		printf("\n¿Que desea modificar?\n1. TODO EL PRODUCTO\n2. SOLO UNA CARACTERISTICA\n\n");
		if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 2, 2)==0)
		{
			switch(opciones)
			{
				case 1:
					if(utn_getTexto(auxiliar.descripcion, "Ingrese la nueva descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
					{
						printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
						if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nueva nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
						{

							if(utn_getFloat(&auxiliar.precio, "Ingrese el nuevo precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
							{
								retorno = 1;
								*elementoModificado = auxiliar;
								break;
							}
						}
					}
					break;

				case 2:
					printf("\n¿Que caracteristica desea modificar?\n1. DESCRIPCION\n2. NACIONALIDAD\n3. PRECIO\n\n");
					if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 3, 1)==0)
					{
						switch (opciones)
						{
							case 1:
								if(utn_getTexto(auxiliar.descripcion, "Ingrese la nueva descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 2:
								printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
								if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nueva nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 3:
								if(utn_getFloat(&auxiliar.precio, "Ingrese el nuevo precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
						}
					}
					break;
			}
		}
	}
	return retorno;
}

int eProductos_Alta(eProductos vector[],int tam,int idTipos,int* indiceParaRetornar)
{
	int retorno;
	eProductos auxiliar;
	int index;


	retorno = 0;
	index = eProductos_ObtenerIndexLibre(vector, tam);


	if(index != -1)
	{
		if(eProductos_CargarDatos(&auxiliar)==1)
		{
			retorno = 1;
		}

		if(retorno == 1)
		{
			auxiliar.isEmpty = OCUPADO;

			vector[index] = auxiliar;

			vector[index].idTipos = idTipos;

			*indiceParaRetornar = index;
		}
	}
	return retorno;
}

int eProductos_Baja(eProductos vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eProductos_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "\nIngrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eProductos_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eProductos_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int eProductos_Modificacion(eProductos vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	eProductos buffer;

	retorno = 0;
	flagMostrados = 0;

	if(eProductos_MostrarTodos(vector, tam)==1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eProductos_BuscarPorID(vector, tam, idModificacion)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0);
			}

			index = eProductos_BuscarPorID(vector, tam, idModificacion);

			if(eProductos_ModificarUno(vector[index], &buffer)==1)
			{
				if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
				{
					vector[index] = buffer;
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

//---ORDENAMIENTOS Y LISTADOS FUNCIONALES---//

int eProductos_InformarProductoPorPrecio(eProductos vector[],int tam,float precioBuscado)
{
	int i;
	int retorno;

	retorno = 0;

	if(vector != NULL && tam > 0 && precioBuscado >= 0)
	{
		puts("\n\t>>Listado Productos");
		printf("%5s\t%5s\t%5s\t%5s\t%5s\n\n","ID","DESCRIPCION","NACIONALIDAD","TIPO","PRECIO");
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO && vector[i].precio == precioBuscado)
			{
				eProductos_MostrarUno(vector[i]);
				retorno = 1;
			}
		}
	}

	return retorno;
}


int eProductos_BuscarPrecioMasAlto(eProductos vector[],int tam,float* precioBuscado)
{
	int i;
	int retorno;
	float auxiliar;
	int flag;

	retorno = 0;
	flag = 0;

	if(vector != NULL && tam > 0 && precioBuscado != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO && (flag == 0 || vector[i].precio > auxiliar))
			{
				auxiliar = vector[i].precio;
				flag = 1;
				retorno = 1;
			}
		}

		*precioBuscado = auxiliar;
	}
	return retorno;
}


//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int eProductos_OrdenarProductosPorCriterioFIAscendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idProductos > vector[i+1].idProductos) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eProductos_OrdenarProductosPorCriterioFIDescendiente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				if(vector[i].idProductos < vector[i+1].idProductos) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eProductos_OrdenarProductosPorCriterioCharAscendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				//if(strcmp(vector[i].idProductos,vector[i+1].idProductos)>0) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eProductos_OrdenarProductosPorCriterioCharDescendente(eProductos vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eProductos buffer;
 	int nuevoLimite;

 	retorno = 0;

 	if(vector != NULL && tam > 0)
 	{
 		nuevoLimite = tam - 1;
 		retorno = -1;
 		do
 		{
 			flagSwap = 0;

 			for(i = 0; i < nuevoLimite ; i++)
 			{
 				//if(strcmp(vector[i].idProductos,vector[i+1].idProductos)<0) //>>>CAMBIAR EL .idProductos EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
 				{
 					flagSwap = 1;
 					buffer = vector[i];
 					vector[i] = vector[i+1];
 					vector[i+1] = buffer;
 				}
 			}

 			nuevoLimite--;

 		}while(flagSwap);
 		retorno = 1;
 	}
 	return retorno;
}

int eProductos_ListadoProductosCriterios(eProductos vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Productos");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				eProductos_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}
