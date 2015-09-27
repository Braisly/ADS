#include "tabla_hash_recolocacion.h"

/* TABLA HASH CON RECOLOCACION */

void InicializarTablaHash(TablaHash t) {
    int i;

    for (i = 0; i < Tam; i++)
        t[i].login[0]=VACIO;

}

int Hash(char *cad) {
    int valor;
    unsigned char *c;

    for (c = cad, valor = 0; *c; c++)
        valor += (int) *c;

    return (valor % Tam);
}


/* OTRA FUNCION HASH */
  int OtherHashFunction (char *cad){
     int i,suma=0;
     for (i=strlen(cad);i>=0;i--){
         suma=(suma*256+cad[i])%Tam;
     }
     return suma;
 }


int Localizar(TablaHash t, char *x) {
    /* Devuelve el sitio donde esta x  o donde deberia de estar. */
    /* No tiene en cuenta los borrados.                          */

    int ini, i, aux;

    ini = Hash(x);

    for (i = 0; i < Tam; i++) {
        aux = (ini + i) % Tam;
        if (t[aux].login[0] == VACIO)
            return aux;
        if (!strcmp(t[aux].login, x))
            return aux;
    }
    return ini;
  
}

/* RECOLOCACION LINEAL */
int LocalizarLineal(TablaHash t, char *x,int *contadore) {
    // Devuelve el sitio donde podriamos poner x 

    int ini, aux, i;

    ini = Hash(x);
    for (i = 0; i < Tam; i++) {
        aux = (ini + i) % Tam;
        if (t[aux].login[0] == VACIO || t[aux].login[0] == BORRADO){
             //(*contadore)++; 
            return aux;
        }
        if (!strcmp(t[aux].login, x)){
            return aux;
        }
        (*contadore)++; 
    }

    return ini;
}


/* RECOLOCACION CUADRATICA */

int LocalizarCuadratica(TablaHash t, char *x,int *contadore) {
   //Devuelve el sitio donde podriamos poner x (recolocación cuadrática)
    int ini, i, aux;

    ini = OtherHashFunction(x);

    for (i = 0; i < Tam; i++) {
        aux = (ini + i*i) % Tam;
        if (t[aux].login[0] == VACIO || t[aux].login[0] == BORRADO)
            return aux;
        if (!strcmp(t[aux].login, x))
            return aux;
        (*contadore)++;
      /*  else
            return 0;*/
    }
    return ini;
}



int MiembroHash(TablaHash t, char *cad) {
    int pos = Localizar(t,cad);

    if (t[pos].login[0] == VACIO)
        return 0;
    else
        return (!strcmp(t[pos].login, cad));
}

int Busqueda(TablaHash t, char *cad, tipo_alumno *e) {
    int pos = Localizar(t,cad);

    if (t[pos].login[0] == VACIO)
        return 0;
    else {
        if (strcmp(t[pos].login, cad) == 0) {
            *e = t[pos];
            return 1;
        } else return 0;
    }
}

void InsertarHash(TablaHash t, tipo_alumno e,int *contadore) {
    int pos;
    //int contadore;
    if (!MiembroHash(t, e.login)) {
        pos = LocalizarLineal(t,e.login,contadore);
        if(t[pos].login[0] == VACIO || t[pos].login[0] == BORRADO) 
          {
            t[pos] = e;
          } 
        else 
            {
            printf("Tabla Llena. \n");
            }
    }
}

void BorrarHash(TablaHash t, char *cad) {
    int pos = Localizar(t,cad);

    if (t[pos].login[0] != VACIO && t[pos].login[0] != BORRADO) {
        if (!strcmp(t[pos].login, cad)) {
            t[pos].login[0]= BORRADO;
            t[pos].login[1]= VACIO;
        }
    }
}

