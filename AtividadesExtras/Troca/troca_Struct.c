#include <stdio.h>

typedef struct t{
    int a, b;
    
}troca;

troca trocaStruct (troca num);

void main(){
        
    troca num; //Crio Variável do Tipo Troca
    
    num.a = 4;
    num.b = 8;
    
   troca retorno =  trocaStruct(num); //Variável do Tipo Troca Recebe a Funcao
    
    printf("%d \n%d \n", retorno.a, retorno.b);
}

troca trocaStruct(troca num){
    
    int aux;
    
    aux = num.a;
    num.a = num.b;
    num.b = aux;
    
    return num; 
}

