/*
 * verificaciones.c
 *
 *  Created on: 9 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

int VerificarSigno (int numeroParaVerificar)
{
	int verificado;

	if(numeroParaVerificar > 0)
	{
		verificado = 1;
	}
	else
	{
		if(numeroParaVerificar < 0)
		{
			verificado = -1;
		}
		else
		{
			verificado = 0;
		}
	}

	return verificado;
}

int VerificarParidad (int numeroParaVerificar)
{
	int verificado;
	int resultado;

	resultado = numeroParaVerificar % 2;

	if(resultado == 0)
	{
		verificado = 1;
	}
	else
	{
		verificado = 0;
	}

	return verificado;
}
