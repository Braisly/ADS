#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Backtracking.h"


int MATRIX[n][n]={{4,9,1},{7,2,3},{6,3,5}};
int MasHermanos(int nivel, int *s)
{
    if (s[nivel] < 2)
    return 1;
    else
    return 0;
}

void Retroceder(int *nivel, int *s, int *bact,int usada[])
{   
  *bact = *bact - MATRIX[*nivel][s[*nivel]];
   usada[s[*nivel]]--;
   s[*nivel] = -1;
   *nivel = *nivel - 1;   
}


int Solucion(int nivel,int s[n],int usada[])
{
    if (nivel == 2 && Criterio(nivel, s,usada))
    return 1;
    else
    return 0;
}



void Generar(int nivel, int *s, int *bac, int usada[])
{        
    if(s[nivel]>=0)
        usada[s[nivel]]--;
    s[nivel] = s[nivel] + 1;
   usada[s[nivel]]++;
    if (s[nivel] == 0)
        *bac = *bac + MATRIX[nivel][s[nivel]];
    else
        *bac = *bac + (MATRIX[nivel][s[nivel]] - MATRIX[nivel][s[nivel] - 1]);
            
}

int Criterio(int nivel, int *s, int usada[])
{
    return usada[s[nivel]]==1;
}

void Backtracking(int *s)
{    
  int nivel = 0;
  int bact = 0;
  int soa[] = {-1, -1, -1};
  int voa = -1;
  int i;
  int usada[n]={0};
  
    do {
        Generar(nivel, s, &bact,usada);
        if (Solucion(nivel, s,usada) == 1 && bact > voa) {
            voa = bact;
            for (i = 0; i < 3; i++)
                soa[i] = s[i];
        }
        if (Criterio(nivel, s,usada) == 1 && nivel < 2) {
            nivel = nivel + 1;
        } else {
            while (MasHermanos(nivel, s) == 0 && nivel >= 0) {
                Retroceder(&nivel, s, &bact,usada);
            }
        }
    } while (nivel > -1);
    printf("Asignacion por columnas: [%d, %d, %d]\n", soa[0], soa[1], soa[2]);
}

