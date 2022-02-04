/*
 ============================================================================
 Name        : ANEXO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReemplazarEnCadena(char* pCadena, char primerCaracter, char segundoCaracter);

int main(void)
{
	setbuf(stdout,NULL);

	char cadena[20]="ariel nicolas";

	if(ReemplazarEnCadena(cadena, 'a', 'x')>0)
	{
		printf("%s",cadena);
	}
	else
	{
		puts("ERRORRRRRR");
	}



	return EXIT_SUCCESS;
}

int ReemplazarEnCadena(char* pCadena, char primerCaracter, char segundoCaracter)
{
	int cantidadReemplazos;
	int i;

	cantidadReemplazos = 0;

	if(pCadena != NULL)
	{
		for(i=0;i<strlen(pCadena);i++)
		{
			if(pCadena[i]==primerCaracter)
			{
				pCadena[i] = segundoCaracter; // ARITMETICA DE PUNTEROS *(pCadena + i) = segundoCaracter;
				cantidadReemplazos++;
			}
		}
	}

	if(cantidadReemplazos == 0)
	{
		cantidadReemplazos = -1;
	}

	return cantidadReemplazos;
}
