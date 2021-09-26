/*
 * operacionesAritmeticas.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesAritmeticas.h"

/**ENTEROS**/

int oper_DividirInt(int numeroA, int numeroB,float *pResultado)
{
	int retorno;

	if(pResultado != NULL)
	{
		if(numeroB == 0)
		{
			retorno = 0;
		}
		else
		{
			*pResultado =(float) numeroA / numeroB;
			retorno = 1;
		}
	}
	return retorno;
}


int oper_SumarInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA + numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_RestarInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA - numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_MultiplicacionInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA * numeroB;
		retorno = 1;
	}
	return retorno;
}

unsigned long long CalcularFactorialInt(int numeroIngresado)
{
	int resultado;

	resultado = -1;

	if(numeroIngresado == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = numeroIngresado * CalcularFactorialInt(numeroIngresado-1);
	}

	return resultado;
}

/**FLOTANTES**/

int oper_DividirFloat(float numeroA, float numeroB,float *pResultado)
{
	int retorno;

	if(pResultado != NULL)
	{
		if(numeroB == 0)
		{
			retorno = 0;
		}
		else
		{
			*pResultado = numeroA / numeroB;
			retorno = 1;
		}
	}
	return retorno;
}


int oper_SumarFloat(float numeroA, float numeroB, float *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA + numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_RestarFloat(float numeroA, float numeroB, float *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA - numeroB;
		retorno = 1;
	}
	return retorno;
}

int oper_MultiplicacionFloat(float numeroA, float numeroB, double *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA * numeroB;
		retorno = 1;
	}
	return retorno;
}

double oper_FactorialFloat(float numeroIngresado)
{
	double resultado;
	int verificacion;

	resultado = 0;
	verificacion = VerificarNumeroEntero(numeroIngresado);

	if(verificacion==1)
	{
		if(numeroIngresado == 0)
		{
			resultado = 1;
		}
		else
		{
			resultado = (int)numeroIngresado * oper_FactorialFloat((int)numeroIngresado-1);
		}
	}
	return resultado;
}

int VerificarNumeroEntero(float numeroIngresado)
{
	int retorno;
	int numeroIngresadoEntero;
	float resultadoParaVerificar;

	numeroIngresadoEntero = numeroIngresado;
	retorno = 0;

	resultadoParaVerificar = numeroIngresado - numeroIngresadoEntero;

	if(resultadoParaVerificar == 0.0)
	{
		retorno = 1;
	}

	return retorno;
}
