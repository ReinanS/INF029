#include <stdio.h>

#define n 5

void ler_vetor(int *vet);
void ordenar(int *vet);
void imprimir_vetor(int *vet);

void main(){

	int vet[n];

	ler_vetor(vet);
	ordenar(vet);
	imprimir_vetor(vet);
}

void ler_vetor(int vet[]){

	int i;

	for (i = 0; i < n; i++){
		printf("Digite o %d valor: ", i+1);
		scanf("%d", &vet[i]);
	}
}

void ordenar(int vet[]){ // USO DO BUBBLE SORT

	int i, j, aux;

	for (i = n -1; i > 0; i--)
		for (j = 0; j < i; j++)
			if(vet[j] > vet[j + 1]){
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
}

void imprimir_vetor(int vet[]){

	int i;

	for (i = 0; i < n; i++)
		printf("\nValor da %d posicao e: %d", i+1, vet[i]);

	printf("\n");
}