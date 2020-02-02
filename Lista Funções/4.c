#include <stdio.h>

void lerNumero(int vet[]);

void main(){
    
    int vet[3];
    int i;
    
    lerNumero(vet);
    
    for (i = 0;i < 3; i++)
        printf("%d ", vet[i]);
}

void lerNumero(int vet[]){
    
    int i;

    for (i = 0; i < 3; i++)
        scanf("%d", &vet[i]);
}
