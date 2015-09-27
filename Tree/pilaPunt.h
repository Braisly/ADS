/* 
 * File:   pila.h
 * Author: puri
 *
 * Created on 13 de octubre de 2009, 13:11
 */

typedef void *pilaPunt; /*tipo opaco*/
typedef abin tipoelemPilaPunt;

void creaPilaPunt(pilaPunt *P);
void destruyePilaPunt(pilaPunt *P);
unsigned esVaciaPilaPunt(pilaPunt P);
tipoelemPilaPunt topePunt(pilaPunt P);
void pushPunt(pilaPunt *P, tipoelemPilaPunt E);
void popPunt(pilaPunt *P);
