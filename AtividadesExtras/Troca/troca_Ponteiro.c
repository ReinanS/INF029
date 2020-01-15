#include <stdio.h>

void trocaPonteiro(int *n1, int *n2);

void main(){
    
    int a, b;
    
    a = 9;
    b = 7;
    
    trocaPonteiro(&a, &b);
    
    printf("%d\n%d\n", a, b);
    
}

void trocaPonteiro(int *n1, int *n2){
    
    int *aux = *n1;
    *n1 = *n2;
    *n2 = *aux;
}
