#include <stdio.h>

#define n 5

typedef struct g{
    
    int maior;
    int menor;
    
}grandeza;

void lerVetor(int vet[]);
grandeza maiorMenor(int vet[]);
void exibirMaiorMenor(grandeza mm);

void main(){
    
        int vet[n];
        
        grandeza mm; 
        
        lerVetor(vet);
        
        mm = maiorMenor(vet, mm);
        
        exibirMaiorMenor(mm);
}

void lerVetor(int vet[]){
    
    int i;
    
    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);
}

grandeza maiorMenor(int vet[]){
    
    int i;
    int maior = vet[0], menor = vet[0];
    grandeza mm;
    
    for (i = 1; i < n; i++){
        
        if (vet[i] > maior)
            maior = vet[i];
        
        if (vet[i] < menor)
            menor = vet[i];
    }
    
    mm.maior =  maior;
    mm.menor = menor;
    
    return mm;
}

void exibirMaiorMenor(grandeza mm){
    
    printf("\nMaior eh: %d \nMenor eh: %d \n", mm.maior, mm.menor);
}

