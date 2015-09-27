#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abin.h"

void crea(abin *A){
	*A=NULL;
}

void destruye(abin *A){
	abin aux;
	aux=*A;
	if(!esVacio(aux)){
	  supizq(&aux);
	  supder(&aux);
	  free(aux);
	  *A=NULL;
	}	
}

unsigned esVacio(abin A){
	return (A==NULL);
}

abin izq(abin A){
	return A->izq;
}

abin der(abin A){
	return A->der;
}

void info(abin A, tipoelem *E){
	*E=A->info;
}

void modifica(abin *A, tipoelem E){
	(*A)->info=E;
}

void insizq(abin *A, tipoelem E){
	abin aux;
	aux=(abin)malloc(sizeof(struct celda));
	aux->info=E;
	aux->izq=NULL;
	aux->der=NULL;	

	if(esVacio(*A))
	  *A=aux; 	
	else
	  (*A)->izq=aux;	
}

void insder(abin *A, tipoelem E){
	abin aux;
	aux=(abin)malloc(sizeof(struct celda));
	aux->info=E;
	aux->izq=NULL;
	aux->der=NULL;	
	if(esVacio(*A))
	  *A=aux;
	else
	  (*A)->der=aux;	
}

void supizq(abin *A){
	abin aux;
	aux=izq(*A);
	if(!esVacio(aux)){
	  supizq(&aux);
	  supder(&aux);	
	  (*A)->izq=NULL;
	  free(aux);
	}	
}

void supder(abin *A){
	abin aux;
	aux=der(*A);
	if(!esVacio(aux)){
	  supizq(&aux);
	  supder(&aux);	
	  (*A)->der=NULL;
	  free(aux);
	}	
}

