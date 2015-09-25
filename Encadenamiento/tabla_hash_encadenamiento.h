#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define Tam 10000 /*DEFINIR NUMERO de entradas en la tabla.*/

typedef lista TablaHash[Tam];

void InicializarTablaHash (TablaHash t);
void DestruirTablaHash (TablaHash t);
int Hash (char *cad);
int OtherHashFunction (char *cad);
int Busqueda(TablaHash t, char *clave, tipoelem *e);
int MiembroHash (TablaHash t, tipoelem e,int *contadore);
void InsertarHash (TablaHash *t, tipoelem elemento,int *contadore);
void BorrarHash (TablaHash *t, char *cad);
