/* 
 * Universidad de Santiago de Compostela
 * 
 * 
 * PRACTICA 2 ALGORITMOS E ESTRUCTURAS DE DATOS
 * 
 * 
 * Autor: Brais López Yáñez
 *
 * Created on 26 de septiembre de 2012, 13:18
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilaOP.h"
#include "pilaPunt.h"
#include "abin.h"



//Función que devuelve cierto (1) si un carácter en la expresión es un operador
unsigned esOperador(char c){
    unsigned ope;
    switch(c){
        case '^': case '*': case '/': case '+': case '-': case '(':
            ope=1; break;
        default:
            ope=0;
    }
    return ope;
}

//Función que devuelve cierto (1) si el carácter es un operando

// (letra mayúscula o minúscula, podéis modificarla para aceptar números


unsigned esOperando(char c){
        if ((c>=65 && c<=90) || (c>=97 && c<=122))
            return 1;
        else
            return 0;
}


//Prioridad de un operador cuando está dentro de la pila
int prioridad_dentro(char op){
    int prioridad;
    switch(op){
        case '^': prioridad=3; break;
        case '*': case '/': prioridad=2; break;
        case '+': case '-': prioridad=1; break;
        case '(': prioridad=0; break;
    }
    return prioridad;
}

//Prioridad de un operador en la expresión infija (antes de entrar en la pila)
int prioridad_fuera(char op){
    int prioridad;
    switch(op){
        case '^': prioridad=4; break;
        case '*': case '/': prioridad= 2; break;
        case '+': case '-': prioridad=1; break;
        case '(': prioridad=5; break;
    }
    return prioridad;
}




/*
 * 
 */
int main(int argc, char** argv) {
  
    pilaOP pilaOP;
    pilaPunt pilaPunt;
    abin c_abin;
    int contadore=0,exit=1;  
    char operacion[100],caux;
  
    
    //Creamos as pilas
    creaPilaOP(&pilaOP);
    creaPilaPunt(&pilaPunt);
    //Pedimos a operacion
    printf("\nCREACION DE UN ARBOL DE EXPRESION\n\n:");
    do{
        printf("\nIntroduzca la expresion a realizar:");
        scanf("%s",&operacion);
        if("operacion==''") exit=0;
    }while(exit!=0);
            
    do{//Recheamos as pilas e movemos elementos
        if(esOperando(operacion[contadore])==1)
        {//esOperando como os elementos das operacións
            crea(&c_abin);
            insizq(&c_abin,operacion[contadore]);
            pushPunt(&pilaPunt,c_abin);
        }
        else
        {
            if(esOperador(operacion[contadore])==1)//Si os datos están introducidos ben teria que ser sempre operador, a menos que sea operando ou )
            {
                while(!esVaciaPilaOP(pilaOP)&&prioridad_fuera(operacion[contadore])<=prioridad_dentro(topeOP(pilaOP)))
                {
                    caux=topeOP(pilaOP);//Auxiliar da cadena de texto, gardamos o que temos
                    
                    crea(&c_abin);//Creamos o nodo
                    
                    insizq(&c_abin,caux);
                    popOP(&pilaOP);
                    
                    c_abin->der=topePunt(pilaPunt);
                    popPunt(&pilaPunt);
                   
                    c_abin->izq=topePunt(pilaPunt);
                    popPunt(&pilaPunt);//Eliminamos porque ao mover o operador c, movemos o resto
                    
                    pushPunt(&pilaPunt,c_abin);
                }
            }   
            else
            {
                if(operacion[contadore]==')')
                {
                    while(topeOP(pilaOP)!='(')
                    {
                        caux=topeOP(pilaOP);
                        popOP(&pilaOP);
                       
                        crea(&c_abin);//Creamos o nodo
                        insizq(&c_abin,caux);
                        popOP(&pilaOP);
                        
                        c_abin->der=topePunt(pilaPunt);
                        popPunt(&pilaPunt);
                       
                        c_abin->izq=topePunt(pilaPunt);
                        popPunt(&pilaPunt);//Eliminamos porque ao mover o operador c, movemos o resto
                        
                        pushPunt(&pilaPunt,c_abin);            
                    }
                    popOP(&pilaOP);
                }        
            }
        }
    contadore++;    
    }while(contadore<strlen(operacion));
    
    
    while(!esVaciaPilaOP(pilaOP))
    {//Destruimos pila operadores
        caux=topeOP(pilaOP);
        popOP(&pilaOP);
        
        crea(&c_abin);
        insizq(&c_abin,caux);
        
        c_abin->der=topePunt(pilaPunt); //Primeiro sacamos a dereita, sempre se faría así
        popPunt(&pilaPunt);
        
        c_abin->izq=topePunt(pilaPunt);
        popPunt(&pilaPunt);
        
        pushPunt(&pilaPunt,c_abin);
    }
    
    //Imprimimos
    preorden(topePunt(pilaPunt));
    printf("\n\n");
    postorden(topePunt(pilaPunt));
    
    //Liberamos memoria
    destruye(&c_abin);
    destruyePilaPunt(&pilaPunt);
    destruyePilaOP(&pilaOP);
    return (EXIT_SUCCESS);
}

