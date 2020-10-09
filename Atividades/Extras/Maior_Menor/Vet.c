#include <stdio.h>

#define n 5

void lerVetor(int vet[]);
void maiorMenor(int vet[], int mm[]);
void exibirMaiorMenor(int mm[]);

void main(){
    
        int vet[n], mm[2];
        
        lerVetor(vet);
        
        maiorMenor(vet, mm);
        
        exibirMaiorMenor(mm);
}

void lerVetor(int vet[]){
    
    int i;
    
    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);
}

void maiorMenor(int vet[], int mm[]){
    
    int i;
    int maior = vet[0], menor = vet[0];
    
    for (i = 1; i < n; i++){
        
        if (vet[i] > maior)
            maior = vet[i];
        
        if (vet[i] < menor)
            menor = vet[i];
    }
    
    mm[0] =  maior;
    mm[1] = menor;
    
}

void exibirMaiorMenor(int mm[]){
    
    printf("\nMaior eh: %d \nMenor eh: %d \n", mm[0], mm[1]);
}

