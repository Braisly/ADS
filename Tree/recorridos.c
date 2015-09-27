#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abin.h"
#include "pilaPunt.h"
#include "pilaOP.h"

void inorden(abin A){
	tipoelem E;
	if(!esVacio(A)){
	  inorden(izq(A));
	  info(A,&E); printf("%d\n",E);	
	  inorden(der(A));
	}	
}

void preorden(abin A){
	tipoelem E;
	if(!esVacio(A)){
	  info(A,&E); printf("%d\n",E);
	  preorden(izq(A));	
	  preorden(der(A));
	}	
}

void postorden(abin A){
	tipoelem E;
	if(!esVacio(A)){
	  postorden(izq(A));	
	  postorden(der(A));
	  info(A,&E); printf("%c\n",E);
	}	
}

void inordenNR(abin A){
	tipoelem E;
	abin aux;
	pilaPunt p;
	aux=A;
	creaPilaPunt(&p);
	do{
	  while(!esVacio(aux)){
	    info(aux,&E);
		 pushPunt(&p,aux);
		 aux=izq(aux);
	  }
	  if(!esVaciaPilaPunt(p)){
	    aux=topePunt(p);
	    popPunt(&p);
	    info(aux,&E); printf("%d\n",E);	
	    aux=der(aux);
	  }
	}while(!esVaciaPilaPunt(p) || !esVacio(aux));
	destruyePilaPunt(&p);
}

