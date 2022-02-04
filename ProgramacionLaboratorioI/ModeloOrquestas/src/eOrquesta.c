/*
 * eOrquesta.c
 *
 *  Created on: 20 oct. 2021
 *      Author: user
 */


#include "eOrquesta.h"
#include "utn.h"


									//---FUNCIONES---//

//---INICIALIZACION Y BUSQUEDA---//

void eOrquesta_Inicializar(eOrquesta vector[],int tam)
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

int eOrquesta_ObtenerIndexLibre(eOrquesta vector[],int tam)
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

int eOrquesta_BuscarPorID(eOrquesta vector[],int tam,int id)
{
	int i;
	int retorno;

	retorno = -1;

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].idOrquesta == id && vector[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void eOrquesta_MostrarUno(eOrquesta elemento)
{
	printf("%5d\n",elemento.idOrquesta);
}

int eOrquesta_MostrarTodos(eOrquesta vector[],int tam)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;

	puts("\n\t>>Listado Orquesta");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(vector[i].isEmpty == OCUPADO)
			{
				eOrquesta_MostrarUno(vector[i]);
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

int eOrquesta_CargarDatos(eOrquesta* elemento)
{
	int retorno;
	eOrquesta auxiliar;

	retorno = 0;
	//CARGAR DATOS NECESARIOS PARA EL ALTA-->>IMPORTANTE<<--NO CARGAR DATOS NI ESTADO
	/*
	if(elemento != NULL)
	{
		if(utn_getTexto(auxiliar.descripcion, "Ingrese la descripcion del producto: \n", "¡ERROR!\n", TAM_CADENACHAR, 0)==0)
		{
			printf("\n\t>>Listado Nacionalidades\n1. EEUU\n2. CHINA\n3. OTRO\n\n");
			if(utn_getInt(&auxiliar.nacionalidad, "Seleccione una nacionalidad: \n", "¡ERROR!\n", 1, 3, 2)==0)
			{
				printf("\n\t>>Listado Tipos\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\n\n");
				if(utn_getInt(&auxiliar.tipo, "Seleccione un tipo: \n", "¡ERROR!\n", 1, 4, 2)==0)
				{
					if(utn_getFloat(&auxiliar.precio, "Ingrese el precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
					{
						retorno = 1;
						*elemento = auxiliar;
					}
				}
			}
		}
	}
	 */

	return retorno;
}

int eOrquesta_ModificarUno(eOrquesta elementoParaModificar,eOrquesta* elementoModificado)
{
	int retorno;
	int opciones;
	eOrquesta auxiliar;

	auxiliar = elementoParaModificar;
	retorno = 0;

	/*	if(elementoModificado != NULL && elementoParaModificar.isEmpty == OCUPADO)
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
							printf("\n\t>>Listado Tipos\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\n\n");
							if(utn_getInt(&auxiliar.tipo, "Seleccione un nuevo tipo: \n", "¡ERROR!\n", 1, 4, 2)==0)
							{
								if(utn_getFloat(&auxiliar.precio, "Ingrese el nuevo precio del producto: \n", "¡ERROR!\n", 0, 1000000000, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
							}
						}
					}
					break;

				case 2:
					printf("\n¿Que caracteristica desea modificar?\n1. DESCRIPCION\n2. NACIONALIDAD\n3. TIPO\n4. PRECIO\n\n");
					if(utn_getInt(&opciones, "Seleccione una opcion: \n", "¡ERROR!\n", 1, 4, 1)==0)
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
								printf("\n\t>>Listado Tipos\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\n\n");
								if(utn_getInt(&auxiliar.tipo, "Seleccione un nuevo tipo: \n", "¡ERROR!\n", 1, 4, 2)==0)
								{
									retorno = 1;
									*elementoModificado = auxiliar;
									break;
								}
								break;
							case 4:
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
	}*/
	return retorno;
}

int eOrquesta_Alta(eOrquesta vector[],int tam,int* idAutoincremental)
{
	int retorno;
	eOrquesta auxiliar;
	int index;
	int idAux;

	retorno = 0;
	index = eProductos_ObtenerIndexLibre(vector, tam);
	idAux = *idAutoincremental+1;

	if(index != -1)
	{
		if(eProductos_CargarDatos(&auxiliar)==1)
		{
			retorno = 1;
		}

		if(retorno == 1)
		{
			auxiliar.idOrquesta = idAux;

			auxiliar.isEmpty = OCUPADO;

			vector[index] = auxiliar;

			*idAutoincremental = idAux;
		}
	}
	return retorno;
}

int eOrquesta_Baja(eOrquesta vector[],int tam)
{
	int retorno;
	int idBaja;
	int index;
	int flagMostrados;
	char confirmacion;

	retorno = 0;
	flagMostrados = 0;

	if(eOrquesta_MostrarTodos(vector, tam) == 1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eOrquesta_BuscarPorID(vector, tam, idBaja)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idBaja, "Ingrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 0);
			}
		}

		index = eOrquesta_BuscarPorID(vector, tam, idBaja);

		if(utn_getCharParaContinuar(&confirmacion, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirmacion == 'S')
		{
			vector[index].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int eOrquesta_Modificacion(eOrquesta vector[],int tam)
{
	int retorno;
	int idModificacion;
	int index;
	int flagMostrados;
	char confirmacion;
	eOrquesta buffer;

	if(eProductos_MostrarTodos(vector, tam)==1)
	{
		flagMostrados = 1;
	}

	if(flagMostrados == 1)
	{
		if(utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0)==0)
		{
			while(eOrquesta_BuscarPorID(vector, tam, idModificacion)==-1)
			{
				puts("NO EXISTE ID.");
				utn_getInt(&idModificacion, "Ingrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 0);
			}

			index = eOrquesta_BuscarPorID(vector, tam, idModificacion);

			if(eOrquesta_ModificarUno(vector[index], &buffer)==1)
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




//---PROTOTIPOS DE ORDENAMIENTOS Y LISTADOS (PARA CAMBIAR Y AJUSTAR DEPENDENDIENDO LOS CRITERIOS)---//

int eOrquesta_OrdenarOrquestaPorCriterioFIAscendente(eOrquesta vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eOrquesta buffer;
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
 				if(vector[i].idOrquesta > vector[i+1].idOrquesta) //>>>CAMBIAR EL .idOrquesta EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eOrquesta_OrdenarOrquestaPorCriterioFIDescendiente(eOrquesta vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eOrquesta buffer;
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
 				if(vector[i].idOrquesta < vector[i+1].idOrquesta) //>>>CAMBIAR EL .idOrquesta EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eOrquesta_OrdenarOrquestaPorCriterioCharAscendente(eOrquesta vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eOrquesta buffer;
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
 				if(strcmp(vector[i].idOrquesta,vector[i+1].idOrquesta)>0) //>>>CAMBIAR EL .idOrquesta EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eOrquesta_OrdenarOrquestaPorCriterioCharDescendente(eOrquesta vector[], int tam)
{
	int i;
	int retorno;
 	int flagSwap;
 	eOrquesta buffer;
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
 				if(strcmp(vector[i].idOrquesta,vector[i+1].idOrquesta)<0) //>>>CAMBIAR EL .idOrquesta EN FUNCION DEL CRITERIO DE ORDENAMIENTO<<<//
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

int eOrquesta_ListadoOrquestaCriterios(eOrquesta vector[],int tam)
{
	int retorno;
	int i;

	retorno = 0;

	puts("\n\t>>Listado Orquesta");
	printf("%5s\n\n","ID"); //TITULOS DE COLUMNAS

	if(vector != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(1/*vector[i].isEmpty == OCUPADO && vector[i].   ==   */) //>>>SETEAR LOS CRITERIOS PARA FILTRAR<<<//
			{
				eOrquesta_MostrarUno(vector[i]);
			}
		}

		retorno = 1;
	}

	return retorno;
}


