#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    TablaHash tabla;
    tipo_alumno aux_alum; 
    char  clav[Tam][20]= { "" };
    colisiones(&tabla,clav,aux_alum);
    busqueda(&tabla,clav,aux_alum);
    return (EXIT_SUCCESS);
}


