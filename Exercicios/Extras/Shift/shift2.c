#include <stdio.h>

#define n 5

void shift(int vet[], int escolha);

void main(){
    
    int i;
    
    int vet[n];
    int escolha;

    for (i = 0; i < n; i ++)
        scanf("%d", &vet[i]);
    
    printf("Escolha: ");
    scanf("%d", &escolha);
    
    shift(vet, escolha);
    
    for (i = 0; i < n; i++)
        printf("\n%d \n",vet[i]);
}

void shift(int vet[], int escolha){
    
    int i, j;
    
    for (i = 0; i < n; i++){
     
        if (escolha == vet[i]){
            
            vet[i] = vet[i + 1];
        
            for (j = i + 1; j < n; i++)
        
                vet[j] = vet[j + 1];
        }
        
       n -1; 
    }
    
}
