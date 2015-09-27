#include <stdio.h>
#include <stdlib.h>
#include "abin.h"

/* Funci�n auxiliar para calcular altura */
int maxAltura(int a, int b)
{
 int mayorAltura;
   if (a>b) return a;
   else return b;      
}

/* Calcular la altura del �rbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(abin a)
{
    int altura;
   if (a==NULL)
      altura=0;
   else 
      altura=1+maxAltura(AlturaArbol(a->izq),AlturaArbol(a->der));
   return altura;
}

/* Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(abin nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izq) auxContador(nodo->izq, c);
   if(nodo->der)   auxContador(nodo->der, c);
}

/* Contar el n�mero de nodos */
int NumeroNodos(abin a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Funci�n auxiliar */
   return *contador;
}
