#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "Funciones.h"
 
    


void colisiones(TablaHash *tabla,char clav[Tam][20],tipo_alumno aux_alum)
{   
    FILE * fp;
    char guion[4];
    int contadore=0,cont;   
    fp = fopen("t10000.txt","r");
    InicializarTablaHash(*tabla);//Creamos tabla hash
    cont=0;
    while((!feof(fp)) && (cont<Tam))
    {
        //fscanf(fp,"%[^ ] %[^ ] %[^ ] - %[^\n]\n", aux_alum.nombre, aux_alum.apellido1, aux_alum.apellido2, aux_alum.login);//Gardamos todo na estructura 
        
        fscanf(fp,"%s",aux_alum.nombre);
        fscanf(fp,"%s",aux_alum.apellido1);
        fscanf(fp,"%s",aux_alum.apellido2);
        fscanf(fp,"%s",guion);
        fscanf(fp,"%s",aux_alum.login);

        InsertarHash(tabla,aux_alum,&contadore);
        cont++;
        strcpy((clav[cont]),aux_alum.login);
    }
   
    printf("COLISIONES: %d\n",contadore);
}


void busqueda(TablaHash *tabla,char clav[Tam][20],tipo_alumno aux_alum)
{
     double tiempoconsumido;
     int cont;
     clock_t inicio, fin;
     for(cont=0;cont<Tam;cont++)
     {
        inicio=clock();
        Busqueda(*tabla,(clav[cont]),&aux_alum);
        fin=clock(); 
        tiempoconsumido=tiempoconsumido+(((double)(fin-inicio))/CLOCKS_PER_SEC); 
        //printf("%s\n",aux_alum.login);
    }  
       printf("Tiempo: %lf\n", tiempoconsumido);
}

