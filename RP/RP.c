#include "RP.h"

/*
 Para cambiar el algoritmo a calculos de maximización/minimización habría que usar de Funciones.h, las funciones
 de maximizacion/minimizar al insertar y cambiar en este TAD la función minimizar/maximizar por MAXIMIZAR/MINIMIZAR
 en el codigo de la función R_P
 */


int B[NU][NU]={{11,17,8,16,20},{9,7,12,6,15},{13,16,15,12,16},{21,24,17,28,26},{14,10,12,11,15}};
void CItrivial(nodo *N)
{
    N->CI=N->bact;
}
void BEtrivial(nodo *N)
{
    N->BE=(N->CS+N->CI)/2;
}
void CStrivial(nodo *N)
{
    N->CS=N->bact+(NU-((N->nivel)+1))*maxB(); 
}
int maxB()
{
    int i,j,result=0;
    for(i=0;i<NU;i++){
        for(j=0;j<NU;j++){
            if(result<B[i][j])result=B[i][j];
        }
    }
    return result;
}
void CIprecisa(nodo *N)
{
    N->CI=N->bact+AsignacionVoraz(N);
}
int AsignacionVoraz(nodo *N)
{
    int ben_acum=0,i,result=0,j,k,AUX[NU];
    //Guardamos los usados
    for(i=0;i<NU;i++)
    {
        AUX[i]=N->USADAS[i];
    }
    for(i=N->nivel+1;i<NU;i++)
    {
        result=0;
        for(j=0;j<NU;j++){
            if(result<B[i][j] && N->USADAS[j]==0)
            {
                result=B[i][j];
                k=j;
            }
        }
        N->USADAS[k]=1;
        ben_acum += B[i][k];
    }
    //Rescatamos los usados
    for(i=0;i<NU;i++)
    {
        N->USADAS[i]=AUX[i];
    }
    return ben_acum;
}
void BEprecisa(nodo *N)
{
    N->BE=(N->CS+N->CI)/2;
}
void CSprecisa(nodo *N)
{
    N->CS=N->bact+MaximosTareas(N);
}
int MaximosTareas(nodo *N)
{
    int ben_acum=0,i,result=0,j,k;
        for(i=N->nivel+1;i<NU;i++)
        {
            result=0;
            for(j=0;j<NU;j++)
            {
                if(result<B[i][j] && N->USADAS[j]==0)
                {
                    result=B[i][j];
                    k=j;
                }
            }
            ben_acum += B[i][k];
        }
        return ben_acum;
}
void R_P(nodo *S)
{
    int i,j,CONTADOR=0;
    LISTA LNV;
    //C para guardar el max(CI(j) o Valor(s)) o min(CS(j) o Valor(s))
    float C;
    //Inicializacion del algoritmo
    nodo raiz,AuxNodo,AuxNodo2;
    Crear(&LNV);
   
    raiz.bact=0;
    raiz.nivel=-1; //para TRIVIALES,PRECISAS

    //cotas
    CItrivial(&raiz);
    CStrivial(&raiz);
    BEtrivial(&raiz);

 /*     iniS(&raiz);
        iniUSADAS(&raiz);
        CIprecisa(&raiz);
        CSprecisa(&raiz);
        BEprecisa(&raiz);*/
        
    //INSERTAR NODO RAIZ Y ACTUALIZAR C
    InsertarMIN(&LNV,raiz);//InsertarMAX
    C=raiz.CS;
    while(!EsListaVacia(LNV))
    {
     AuxNodo=Comprueba(LNV);
     CONTADOR++;
     Quitar(&LNV);
     if(MINIMIZAR(AuxNodo,C)==0)
     {//MAXIMIZAR
      for(i=0;i<NU;i++)
      {
       AuxNodo2.nivel=AuxNodo.nivel+1;
       for(j=0;j<NU;j++)
       {
        AuxNodo2.s[j]=AuxNodo.s[j];
        AuxNodo2.USADAS[j]=AuxNodo.USADAS[j];
       }
       if(AuxNodo.USADAS[i]==0)
       {
        AuxNodo2.s[AuxNodo2.nivel]=i;
        AuxNodo2.USADAS[i]=1;          
        AuxNodo2.bact=AuxNodo.bact + B[AuxNodo2.nivel][i];                
        CItrivial(&AuxNodo2);
        CStrivial(&AuxNodo2);
        BEtrivial(&AuxNodo2);
        /*   CIprecisa(&AuxNodo2);
             CSprecisa(&AuxNodo2);
             BEprecisa(&AuxNodo2);
        */
                        
        //Comprobaciones por hijo factible
        if(Solucion(AuxNodo2) && (AuxNodo2.bact<S->bact))
        { //AuxNodo2.bact   <   S->bact "ES PARA MINIMIZAR"
          *S=AuxNodo2;
          if(C>AuxNodo2.bact)C=AuxNodo2.bact; // > PARA MINIMIZACION "<" cambiar para MAXIMIZACION
        }else if(!Solucion(AuxNodo2) && !MINIMIZAR(AuxNodo2,C))
              {
               InsertarMIN(&LNV,AuxNodo2);
               if(C>AuxNodo2.CS)C=AuxNodo2.CS; // > PARA MINIMIZACION "<" cambiar para MAXIMIZACION
              }
         }
       }
     }
   }
   printf("\nNodos Generados:  %d\n",CONTADOR);
}
void iniS(nodo *N){
    int i;
    for(i=0;i<NU;i++){
        N->s[i]=-1;
    }
}
void iniUSADAS(nodo *N)
{
    int i;
    for(i=0;i<NU;i++){
        N->USADAS[i]=0;
    }
}
int MAXIMIZAR(nodo N,float C)
{
    if(N.CS<=C){ //SE PODA EL NODO en el peor de los casos el nodo que actualizó C se colocó delante en LNV y si el tiene como cotas numeros igual esta funcion descartará a sus hijos que pueden ser solucion valida
        return 1;
    }else return 0;
}
int MINIMIZAR(nodo N,float C)
{
    if(N.CI>C){ //SE PODA EL NODO en el peor de los casos el nodo que actualizó C se colocó delante en LNV y si el tiene como cotas numeros igual esta funcion descartará a sus hijos que pueden ser solucion valida
        return 1; 
    }else return 0;
}
int Solucion(nodo N)
{
    if(N.nivel==NU-1){ //PARA LA MATRIZ QUE NUNCA VA A SER DEL NU TOTAL
        return 1;
    }else return 0;
}


