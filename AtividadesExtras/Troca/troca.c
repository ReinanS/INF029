#include <stdio.h>

void preencher(int *n1, int *n2); 
void troca(int *n1, int *n2);
void exibir(int *n1, int *n2);

void main(){
    
    int a, b;
    
    preencher(&a, &b);
    
    troca(&a,&b);
    
    exibir(&a, &b);
}

void preencher(int *n1, int *n2){
    
    scanf("%d %d", n1,n2);
    
}

void troca(int *n1, int *n2){
        
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}

void exibir(int *n1, int *n2){
    
    printf("\nA = %d \nB = %d \n", *n1, *n2);
}
