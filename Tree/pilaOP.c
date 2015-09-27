#include <stdlib.h>
#include "abin.h"
typedef char tipoelemPilaOP;

struct tipo_celda{
    tipoelemPilaOP elemento;
    struct tipo_celda * sig;
};

typedef struct tipo_celda * pilaOP;

void creaPilaOP(pilaOP *P)
{
    *P=NULL;
}

void destruyePilaOP(pilaOP *P)
{
    pilaOP aux;
    aux=*P;
    while(aux!=NULL)
    {
	   aux=aux->sig;
        free(*P);
	*P=aux;
    }
}

unsigned esVaciaPilaOP(pilaOP P)
{
    return P==NULL;
}

tipoelemPilaOP topeOP(pilaOP P)
{
    if (!esVaciaPilaOP(P))  /*si pila no vac�a*/
        return P->elemento; 
}

void pushOP(pilaOP *P, tipoelemPilaOP E)
{
    pilaOP aux;
    aux=(pilaOP)malloc(sizeof(struct tipo_celda));
    aux->elemento=E;
    aux->sig=*P;
    *P=aux;
}


void popOP(pilaOP *P)
{
    pilaOP aux;
    if (!esVaciaPilaOP(*P))  /*si pila no vac�a*/
    {
        aux=*P;
        *P=(*P)->sig;
        free(aux);
    }
}


