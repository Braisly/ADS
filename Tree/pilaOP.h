/* 
 * File:   pila.h
 * Author: puri
 *
 * Created on 13 de octubre de 2009, 13:11
 */

typedef void *pilaOP; /*tipo opaco*/
typedef char tipoelemPilaOP; //Temos que cambiar abin por char, por ser operando

void creaPilaOP(pilaOP *P);
void destruyePilaOP(pilaOP *P);
unsigned esVaciaPilaOP(pilaOP P);
tipoelemPilaOP topeOP(pilaOP P);
void pushOP(pilaOP *P, tipoelemPilaOP E);
void popOP(pilaOP *P);
