#include <stdio.h>

typedef struct num{
    
    int vet[4];
    
}num;

num lerNum();

void main(){
    
    int i;
    
    num v = lerNum();
    
    for (i = 0; i < 4; i++)
        printf("%d", v.vet[i]);
}

num lerNum(){
    
    int i;
    num valor;
    
    for (i = 0; i < 4; i++)
        scanf("%d", &valor.vet[i]);
    
    return valor;
}
