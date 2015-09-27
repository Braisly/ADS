typedef int tipoelem;

struct celda{
	tipoelem info;
	struct celda *izq, *der;
};

typedef struct celda *abin;


void crea(abin *A);
void destruye(abin *A);
unsigned esVacio(abin A);
abin izq(abin A);
abin der(abin A);
void info(abin A, tipoelem *E);
void insizq(abin *A, tipoelem E);
void insder(abin *A, tipoelem E);
void supizq(abin *A);
void supder(abin *A);
void modifica(abin *A, tipoelem E);
