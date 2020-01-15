#include <stdio.h>

int inverterNumero(int num);

void main(){
    
    int num = 12345;
    
    int retorno = inverterNumero(num);
    
    printf("\n%d\n", retorno);
}

int inverterNumero(int num){ // 2352
    
    int auxiliar = num % 10;
    num /= 10;
     
    if (num > 0){
        
        do{
           auxiliar *= 10;
           auxiliar += num % 10; 
           num /= 10;
           
        }while(num > 0);
    
        
    }else{
       
    }
    
    return auxiliar;
}


