/* 
 * File:   Funciones.h
 * Author: Brais
 *
 * Created on 26 de diciembre de 2012, 17:48
 */

#define NU 5 //Tamaño NU para arrays y para la matriz B de beneficios

typedef struct 
{
    int s[NU];
    int USADAS[NU];
    int nivel;
    int bact;
    float CI,BE,CS;
}nodo;


struct Tipo_celda
{
    nodo info;
    struct Tipo_celda * sig;
};

typedef struct Tipo_celda * LISTA;

void Crear(LISTA *L);
void Destruir(LISTA *L);
void InsertarMIN(LISTA *L,nodo n);
void InsertarMAX(LISTA *L,nodo n);
void Quitar(LISTA *L);
nodo Comprueba(LISTA L);
int EsListaVacia(LISTA L);
void Mostrar(LISTA L);


