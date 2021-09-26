/*
 * operacionesAritmeticas.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef OPERACIONESARITMETICAS_H_
#define OPERACIONESARITMETICAS_H_

/**ENTEROS**/
int oper_DividirInt(int numeroA, int numeroB,float *pResultado);
int oper_SumarInt(int numeroA, int numeroB, long *pResultado);
int oper_RestarInt(int numeroA, int numeroB, long *pResultado);
int oper_MultiplicacionInt(int numeroA, int numeroB, long *pResultado);
unsigned long long CalcularFactorialInt(int numeroIngresado);

/**FLOTANTES**/
int oper_DividirFloat(float numeroA, float numeroB,float *pResultado);
int oper_SumarFloat(float numeroA, float numeroB, float *pResultado);
int oper_RestarFloat(float numeroA, float numeroB, float *pResultado);
int oper_MultiplicacionFloat(float numeroA, float numeroB, double *pResultado);
double oper_FactorialFloat(float numeroIngresado);

/**VERIFICACIONES**/
int VerificarNumeroEntero(float numeroIngresado);

#endif /* OPERACIONESARITMETICAS_H_ */
