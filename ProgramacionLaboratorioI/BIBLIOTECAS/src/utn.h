/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>


/// \brief
///
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param reintentos
/// \return

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif /* UTN_H_ */
