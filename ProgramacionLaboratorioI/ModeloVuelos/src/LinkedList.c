#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;

	if(this != NULL && (nodeIndex >= 0 && nodeIndex < ll_len(this)))
	{
		pNode=this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode = NULL;
    Node* pUltimoNode = NULL;

    if(this != NULL && (nodeIndex >= 0 && nodeIndex <= ll_len(this))) //�POR QUE nodeIndex funciona si es <= ll_len(this)? �ES PORQUE QUIERE AGREGARLO AL FINAL DE LA LISTA?
    {
    	pNewNode = (Node*) malloc(sizeof(Node));

    	if(pNewNode != NULL)
    	{
    		pNewNode->pElement = pElement;
    		pNewNode->pNextNode = NULL;

			if(nodeIndex == 0)
			{
				pNewNode->pNextNode = this->pFirstNode; // Es por el push
				this->pFirstNode = pNewNode;
				this->size+=1;
				returnAux = 0;
			}
	    	else
	    	{
				pUltimoNode = getNode(this, nodeIndex-1); //ESTO SERIA EL NODO ANTERIOR
				if(pUltimoNode != NULL)
				{
					pNewNode->pNextNode = pUltimoNode->pNextNode;
					pUltimoNode->pNextNode = pNewNode;
					this->size+=1;
					returnAux = 0;
				}

	    	}
    	}


    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(addNode(this, ll_len(this), pElement)==0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && (index >= 0 && index < ll_len(this)))  //�POR QUE index funciona no es <= ll_len(this)?
	{
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    	}
	}

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL && (index >= 0 && index < ll_len(this)))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pAnteriorNode = NULL;

    if(this != NULL && (index >= 0 && index < ll_len(this)))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		if(index == 0)
    		{
    			this->pFirstNode = pNode->pNextNode;
    			this->size-=1;
    			free(pNode);
    			returnAux = 0;
    		}
    		else
    		{
    			pAnteriorNode = getNode(this, index-1);
    			if(pAnteriorNode != NULL)
    			{
    				pAnteriorNode->pNextNode = pNode->pNextNode;
    				this->size-=1;
    				free(pNode);
    				returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	while(ll_len(this)!=0)
    	{
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this)==0)
    	{
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int i;

    if(this != NULL)
    {
    	//pNode = getNode(this, 0); //this->pFirstNode;

    	if(1)//pNode != NULL)
    	{
			for(i=0;i<ll_len(this);i++)
			{
				pNode = getNode(this, i);

				if(pNode != NULL)
				{
					if(pNode->pElement == pElement)
					{
						returnAux = i;
						break;
					}
				}
			}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0; // ll_len PUEDE DEVOLVER -1 PERO LO AHCE SI this == NULL, en este caso yo ya verifico que no sea NULL
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int lenAnterior;

    if(this != NULL && (index >= 0 && index <= ll_len(this))) //�POR QUE index funciona si es <= ll_len(this)? �ES POR si QUIERE AGREGARLO AL FINAL DE LA LISTA?
    {
    	lenAnterior = ll_len(this);

    	if(addNode(this, index, pElement)==0)
    	{
    		if(lenAnterior < ll_len(this)) //ESTA VERIFICACION ES PORQUE DABA UN ERROR DE NO VERIFICAR QUE EL SIZE SE HAYA AUMENTADO
    		{
				returnAux = 0;

    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && (index >= 0 && index < ll_len(this)))
    {
    	pNode = getNode(this, index);

    	if(pNode != NULL)
    	{
    		returnAux = pNode->pElement;
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;

    void* pElement2 = NULL;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	for(i=0;i<ll_len(this2);i++)
    	{
    		pElement2 = ll_get(this2, i);

    		if(ll_contains(this, pElement2)==0) //ll_contain devuelve 0 si el elemento no esta contenido en la lista
    		{
    			returnAux = 0;
    			break;
    		}
    	}



    	/*
    	 * >Caso [Verifica retorno con parametros correctos]

			Setup...

			assert not equals failed '-1' != '-1'


			Error en el valor de retorno de <containsAll> si los parametros son correctos
			 debe retornar 0 o 1


			TEST FAILED

			FILE:containsAllTest.c LINE:53

    	for(i=0;i<ll_len(this2);i++)
    	{
    		pElement2 = ll_get(this2, i);

    		if(ll_contains(this, pElement2)==1)				//DE ESTA FORMA ME DA EL 75%  Y EL ERROR DE ARRIBA
    		{
    			returnAux = 1;
    		}
    		else
    		{
    			if(ll_contains(this, pElement2)==0)
    			returnAux = 0;
    			break;
    		}
    	}*/

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int i;

    if(this != NULL && (from >= 0 && from < ll_len(this)) && (to > from && to <= ll_len(this))) // si pongo to < ll_len(this) me tira error
	{
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from;i<=to;i++) // si pongo to < ll_len(this) me tira error
    		{
				pElement = ll_get(this, i);
				addNode(cloneArray, i, pElement);
    		}
    	}
	}

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this, 0, ll_len(this));
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement1 = NULL;
    void* pElement2 = NULL;
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	for(i=0;i<ll_len(this)-1;i++)
    	{
    		for(j=i+1;j<ll_len(this);j++)
    		{
    			pElement1 = ll_get(this, i);
    			pElement2 = ll_get(this, j);

    			if(pElement1 != NULL && pElement2 != NULL)
    			{
    				if((pFunc(pElement1,pElement2)>0 && order == 1) || (pFunc(pElement1,pElement2)<0 && order == 0))
					{
						ll_set(this, i, pElement2);
						ll_set(this, j, pElement1);
					}

    			}
    		}
    	}
    	returnAux = 0;
    }

    return returnAux;

}
