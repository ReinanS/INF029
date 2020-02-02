#include <stdio.h>

int q5(int num);

void main(){
    
    int num = 123450;
    
    int retorno = q5(num);
    
    printf("\n%d\n", retorno);
}

int q5(int num){
    
    int inverso = 0, guard;

    while(num > 0) { //enquanto for maior que 0, o número sera dividido e seu resto sera jogado numa variável que multiplicara seu valor por 10 a cada loop 
        guard = num % 10;
        inverso *=  (10 + guard); 
        num /= 10;
    }
    return inverso; //retorna o numero invertido
}