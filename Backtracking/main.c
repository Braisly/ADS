/* 
 * File:   main.c
 * Author: Brais
 *
 * Created on 5 de diciembre de 2012, 12:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Backtracking.h"

int main() 
{
    int result[n],k,j;
    
    
      printf("\n-------------------------\n");
        printf("BACKTRACKING AUTOMATICO");
        printf("\n-------------------------\n");
        //Inicializamos  
        for(k=0;k<n;k++)
        {
            result[k] = -1;
        }
  
      //Imprimimos a matriz
    for(k=0;k<n;k++)
    {
        printf("[");
        for(j=0;j<n;j++)
        {
         printf(" %d ",MATRIX[k][j]);
        }
        printf("]\n",MATRIX[k][j]);  
    }
       Backtracking(result);
}
