/* 
 * File:   main.c
 * Author: Brais
 *
 * Created on 25 de diciembre de 2012, 21:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "RP.h"


int main() {
    
      int k,j;
      nodo SOLUCION;
    
        printf("\n-----------------------------------\n");
        printf("BACKTRACKING: PODA Y RAMIFICACION");
        printf("\n-----------------------------------\n");

   //Imprimimos la matriz
    for(k=0;k<NU;k++)
    {
        printf("[");
        for(j=0;j<NU;j++)
        {
         printf(" %d ",B[k][j]);
        }
        printf("]\n");  
    }
        R_P(&SOLUCION);
        printf("\nSolucion Optima:  [");
        for(k=0;k<NU;k++)
        {
         printf("%d",SOLUCION.s[k]+1);
         if(k<NU-1) printf(", ");
        }
        printf("]\n\n"); 
}


