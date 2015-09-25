/* 
 * File:   Backtracking.h
 * Author: Brais
 *
 * Created on 5 de diciembre de 2012, 13:14
 */

#define n 3

int MATRIX[n][n];
void Backtracking(int *s);
void Generar(int nivel, int *s, int *bac, int usada[]);
int Criterio(int nivel, int *s, int usada[]);
int MasHermanos(int nivel, int *s);
void Retroceder(int *nivel, int *s, int *bact, int usada[]);
int Solucion(int nivel, int *s,int usada[]);
