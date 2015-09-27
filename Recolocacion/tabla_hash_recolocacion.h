#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tam 10000 /*DEFINIR NUMERO de entradas en la tabla.*/
#define VACIO '\0'
#define BORRADO ' '

typedef struct{
    char nombre[20];
    char apellido1[20];
    char apellido2[20];
    char login[20];
}tipo_alumno;

typedef tipo_alumno TablaHash[Tam];

void InicializarTablaHash(TablaHash t);
int Hash(char *cad);
int OtherHashFunction(char *cad);
int Localizar(TablaHash t, char *x);
int LocalizarLineal(TablaHash t, char *x,int *contadore);
int LocalizarCuadratica(TablaHash t, char *x,int *contadore);
int MiembroHash(TablaHash t, char *cad) ;
int Busqueda(TablaHash t, char *cad, tipo_alumno *e);
void InsertarHash(TablaHash t, tipo_alumno e, int *contadore);
void BorrarHash(TablaHash t, char *cad);
