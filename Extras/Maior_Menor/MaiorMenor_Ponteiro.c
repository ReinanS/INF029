#include <stdio.h>

#define n 5

void lerVetor(int vet[]);
void maiorMenor(int vet[], int *maior, int  *menor);
void exibirMaiorMenor(int maior, int menor);

void main(){
    
        int vet[n], maior, menor;
        
        lerVetor(vet);
        
        maiorMenor(vet, &maior, &menor);
        
        exibirMaiorMenor(maior, menor);
}

void lerVetor(int vet[]){
    
    int i;
    
    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);
}

void maiorMenor(int vet[], int *maior, int *menor){
    
    int i;
    *maior = vet[0], *menor = vet[0];
    
    for (i = 1; i < n; i++){
        
        if (vet[i] > *maior)
            *maior = vet[i];
        
        if (vet[i] < *menor)
            *menor = vet[i];
    }
    
}

void exibirMaiorMenor(int maior, int menor){
    
    printf("\nMaior eh: %d \nMenor eh: %d \n", maior, menor);
}

