#include <stdio.h>
#include <stdlib.h>
#include "abin.h"

/* Función auxiliar para calcular altura */
int maxAltura(int a, int b)
{
 int mayorAltura;
   if (a>b) return a;
   else return b;      
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(abin a)
{
    int altura;
   if (a==NULL)
      altura=0;
   else 
      altura=1+maxAltura(AlturaArbol(a->izq),AlturaArbol(a->der));
   return altura;
}

/* Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(abin nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izq) auxContador(nodo->izq, c);
   if(nodo->der)   auxContador(nodo->der, c);
}

/* Contar el número de nodos */
int NumeroNodos(abin a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}
