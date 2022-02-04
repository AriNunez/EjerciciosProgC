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

int Push(int* pArray,int* tam,int enteroParaIngresar, int indice);

int main(void)
{
	setbuf(stdout,NULL);

    int* pArray;
    int tam;
    int i;

    tam=4;

    pArray = (int*)malloc(sizeof(int)*tam);

    if(pArray != NULL)
    {
    	*(pArray)=1;
    	*(pArray+1)=5;
    	*(pArray+2)=4;
    	*(pArray+3)=9;

    	for(i=0;i<tam;i++)
    	{
    		printf("%d\n",*(pArray+i));
    	}

    	if(Push(pArray, &tam, 10, 10)==1)
    	{
    		printf("\n");
        	for(i=0;i<tam;i++)
        	{
        		printf("%d\n",*(pArray+i));
        	}
    	}
    	else
    	{
    		printf("\n");
        	for(i=0;i<tam;i++)
        	{
        		printf("%d\n",*(pArray+i));
        	}
        	printf("\n%d\n",tam);
    	}
    }

	return EXIT_SUCCESS;
}

int Push(int* pArray,int* tam,int enteroParaIngresar, int indice)
{
	int retorno;
	int i;
	int auxTam;
	int* pArrayAux;

	retorno = 0;

	if(pArray != NULL && tam != NULL && *tam > 0 && indice < *tam)
	{
		auxTam = *tam;
		auxTam+=1;
		pArrayAux = (int*) realloc(pArray,sizeof(int)*auxTam);
		if(pArrayAux != NULL)
		{
			for(i=auxTam-1;i>indice;i--)
			{
				*(pArrayAux+i)=*(pArray+(i-1));

			}

			*(pArrayAux+indice) = enteroParaIngresar;
			pArray = pArrayAux;
			*tam = auxTam;
			retorno = 1;
		}
	}

	return retorno;
}
