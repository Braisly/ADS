#include <stdlib.h>
#include "abin.h"


typedef abin tipoelemPilaPunt;

struct tipo_celda{
    tipoelemPilaPunt elemento;
    struct tipo_celda * sig;
};

typedef struct tipo_celda * pilaPunt;

void creaPilaPunt(pilaPunt *P)
{
    *P=NULL;
}

void destruyePilaPunt(pilaPunt *P)
{
    pilaPunt aux;
    aux=*P;
    while(aux!=NULL)
    {
	   aux=aux->sig;
        free(*P);
	*P=aux;
    }
}

unsigned esVaciaPilaPunt(pilaPunt P)
{
    return P==NULL;
}

tipoelemPilaPunt topePunt(pilaPunt P)
{
    if (!esVaciaPilaPunt(P))  /*si pila no vac�a*/
        return P->elemento; 
}

void pushPunt(pilaPunt *P, tipoelemPilaPunt E)
{
    pilaPunt aux;
    aux=(pilaPunt)malloc(sizeof(struct tipo_celda));
    aux->elemento=E;
    aux->sig=*P;
    *P=aux;
}


void popPunt(pilaPunt *P)
{
    pilaPunt aux;
    if (!esVaciaPilaPunt(*P))  /*si pila no vac�a*/
    {
        aux=*P;
        *P=(*P)->sig;
        free(aux);
    }
}


