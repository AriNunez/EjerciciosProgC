/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Remover(int* pArray,int* tam,int enteroParaBorrar);

int main(void)
{
	setbuf(stdout,NULL);

    int* pArray;
    int tam;
    int i;

    tam=5;

    pArray = (int*)malloc(sizeof(int)*tam);

    if(pArray != NULL)
    {
    	*(pArray)=5;
    	*(pArray+1)=4;
    	*(pArray+2)=2;
    	*(pArray+3)=1;
    	*(pArray+4)=3;

    	for(i=0;i<tam;i++)
    	{
    		printf("%d\n",*(pArray+i));
    	}

    	if(Remover(pArray, &tam, 2)==1)
    	{
    		printf("\n");
        	for(i=0;i<tam;i++)
        	{
        		printf("%d\n",*(pArray+i));
        	}
    	}


    }

	return EXIT_SUCCESS;
}

int Remover(int* pArray,int* tam,int enteroParaBorrar)
{
	int retorno;
	int indice;
	int i;

	retorno = 0;
	indice = -1;

	if(pArray != NULL && tam != NULL && *tam > 0)
	{
		for(i=0;i<*tam;i++)
		{
			if(*(pArray+i)==enteroParaBorrar)
			{
				indice = i;
				break;
			}
		}

		if(indice>=0)
		{
			for(i=indice;i<*tam;i++)
			{
				*(pArray+i) = *(pArray+(i+1));
			}
			*tam-=1;
			pArray=(int*)realloc(pArray,sizeof(int)* *tam);
			retorno = 1;
		}
	}

	return retorno;
}
