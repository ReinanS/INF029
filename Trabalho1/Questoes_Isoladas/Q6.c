#include <stdio.h>

int contarNum(int num, int busca);

void main(){
    
    int numero = 123422;
    int busca = 3;
    
    int retorno = contarNum(numero, busca);

    printf("\n%d\n", retorno);
}

int contarNum(int num, int busca){
    
    int count = 0;
    int aux;
    
    do{
       
        aux = num % 10;
        
        if (aux == busca)
            count ++;
        
        num /= 10;
        
    }while(num > 0);
    
    return count;
}
