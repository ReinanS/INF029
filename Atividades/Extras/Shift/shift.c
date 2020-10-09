#include <stdio.h>
#include <stdlib.h>

#define n 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//SHIFT

int main(int argc, char *argv[]) {
	
	int vetor[n], remover, indice;
	int tamocupado = n;
	int i, j;
	
	for(i = 0; i < n; i++)
		scanf("%d",&vetor[i]);
	
    printf("Remover: ");
	scanf("%d", &remover);
	
	for(i = 0; i < tamocupado; i++)
	
        if (vetor[i] == remover)
        
            for(j = i; j < tamocupado; j++)
                vetor[j] = vetor [j+1];
            
	tamocupado -=1;
	
	for(i=0; i<tamocupado; i++)
		printf("%d\n",vetor[i]);
	
	return 0;
}
