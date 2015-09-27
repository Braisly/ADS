/* 
 * File:   RP.h
 * Author: Brais
 *
 * Created on 26 de diciembre de 2012, 17:48
 */

#include "Funciones.h"

int B[NU][NU];
void CItrivial(nodo *N);
void BEtrivial(nodo *N);
void CStrivial(nodo *N);
int maxB();
void CIprecisa(nodo *N);
int AsignacionVoraz(nodo *N);
void BEprecisa(nodo *N);
void CSprecisa(nodo *N);
int MaximosTareas(nodo *N);
void R_P(nodo *S);
void iniS(nodo *N);
void iniUSADAS(nodo *N);
int Solucion(nodo N);
int MAXIMIZAR(nodo N,float C);
int MINIMIZAR(nodo N,float C);



