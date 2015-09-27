#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void Crear(LISTA *L)
{
    *L=NULL;
}
void Destruir(LISTA *L)
{
    if(!EsListaVacia(*L))
    {
        LISTA aux,aux2;
        aux=(*L)->sig;
        free(*L);
        do{
            aux2=aux;
            aux=(*aux).sig;
            free(aux2);
        }while((*aux).sig!=NULL);
        free(aux);
    }
}
void InsertarMIN(LISTA *L,nodo n)
{
   struct Tipo_celda *aux;
   LISTA auxL;
   if(EsListaVacia(*L))
   {
       *L=(LISTA)malloc(sizeof(struct Tipo_celda));
        if(L==NULL)
        {
            puts("Error al crear LISTA.\n");
            getchar();
            exit(-1);
        }
       (*L)->info=n;
       (*L)->sig=NULL;
   }else{
       auxL=(*L);

       if((*auxL).sig==NULL)
       {
            //ver insercion por delante o por detras
           if((*auxL).info.BE>n.BE)
           {
               aux=auxL;
               auxL=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig=aux;
               (*auxL).info=n;
               *L=auxL;
           }else{
               (*auxL).sig=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig->sig=NULL;
               (*auxL).sig->info=n;
           }
       }else if((*auxL).info.BE>n.BE)
        {
            //insercion por delante
               aux=auxL;
               auxL=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig=aux;
               (*auxL).info=n;
               *L=auxL;
       }else{
           for(;(!((*auxL).info.BE<n.BE && (*auxL).sig->info.BE>n.BE));auxL=(*auxL).sig)
           {
               if((*auxL).sig->sig==NULL){
                   auxL=(*auxL).sig;
                   break;
               }
           }
           aux=(*auxL).sig;
           (*auxL).sig=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
           (*auxL).sig->sig=aux;
           (*auxL).sig->info=n;
       }
   }
   
}
void InsertarMAX(LISTA *L,nodo n)
{
   struct Tipo_celda *aux;
   LISTA auxL;
   if(EsListaVacia(*L))
   {
       *L=(LISTA)malloc(sizeof(struct Tipo_celda));
        if(L==NULL){
            puts("Error al crear LISTA.\n");
            getchar();
            exit(-1);
        }
       (*L)->info=n;
       (*L)->sig=NULL;
   }else{
       auxL=(*L);

       if((*auxL).sig==NULL){
            //ver insercion por delante o por detras
           if((*auxL).info.BE<n.BE)
           {
               aux=auxL;
               auxL=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig=aux;
               (*auxL).info=n;
               *L=auxL;
           }else{
               (*auxL).sig=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig->sig=NULL;
               (*auxL).sig->info=n;
           }
       }else if((*auxL).info.BE<n.BE)
       {
            //insercion por delante
               aux=auxL;
               auxL=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
               (*auxL).sig=aux;
               (*auxL).info=n;
               *L=auxL;
       }else{
           for(;(!((*auxL).info.BE>n.BE && (*auxL).sig->info.BE<n.BE));auxL=(*auxL).sig)
           {
               if((*auxL).sig->sig==NULL)
               {
                   auxL=(*auxL).sig;
                   break;
               }
           }
           aux=(*auxL).sig;
           (*auxL).sig=(struct Tipo_celda *)malloc(sizeof(struct Tipo_celda));
           (*auxL).sig->sig=aux;
           (*auxL).sig->info=n;
       }
   }

}
void Mostrar(LISTA L)
{
        LISTA auxL;
        if(!EsListaVacia(L))
        {
            printf("\tLNV: ");
            for(auxL=L;(*auxL).sig!=NULL;auxL=(*auxL).sig)
            {
                printf("%f ",auxL->info.BE);
            }
            printf("%f ",auxL->info.BE);
            printf(".\n");
        }else printf("Lista Vacia.\n");
}
void Quitar(LISTA *L)
{
    LISTA aux;
    if(!EsListaVacia(*L))
    {
        aux=(*L);
        (*L)=(*L)->sig;
        free(aux);
    }else printf("Lista Vacia.\n");
}
nodo Comprueba(LISTA L)
{
    if(!EsListaVacia(L))
    {
        return L->info;
    }else puts("No existe ningun elemento.\n");

}
int EsListaVacia(LISTA L)
{
    if(L==NULL)
    {
        return 1;
    }else return 0;
}

