#include <stdio.h>

int contarNum(int num, int busca);

void main(){
    
    int numero = 01234220;
    int busca = 0;
    
    int retorno = contarNum(numero, busca);

    printf("\n%d\n", retorno);
}

int contarNum(int numerobase, int numerobusca){
    
    int qtdOcorrencias=0, contA=0, contB=0;
    char strBase[9999];
    char strBusca[9999];

   sprintf(strBase,"%d",numerobase);
   sprintf(strBusca,"%d",numerobusca);

   for(contA=0, contB=0;contA<strlen(strBase);contA++){
      while(strBase[contA]==strBusca[contB]&&contA<strlen(strBase)){
         contA++;
         contB++;
      }
      if(contB==strlen(strBusca)){
         qtdOcorrencias++;
      }
      contB=0;            
   }
  
    return qtdOcorrencias;
}
