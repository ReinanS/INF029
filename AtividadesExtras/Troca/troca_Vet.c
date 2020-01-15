#include <stdio.h>

void trocaVet(int vet[]);

void main(){
    
    int vet[2];
    int i;
    
    for (i = 0; i < 2; i++){
        printf("Digite o %d Valor: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("\n");
    
    trocaVet(vet);
    
    for (i = 0; i < 2; i++)
        printf("Valor do Vetor %d eh: %d",i + 1, vet[i]);
    
    printf("\n");
}

void trocaVet(int vet[]){
    
    int aux;
    
    aux = vet[0];
    vet[0] = vet[1];
    vet[1] = aux;
    
}

