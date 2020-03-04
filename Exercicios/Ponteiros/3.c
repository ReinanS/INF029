#include <stdio.h>

#define n 5

void ler_vetor(int *vet);
void ordenar(int *vet);
void imprimir_vetor(int *vet);

void main(){

	int vet[n];

	ler_vetor(vet);
	imprimir_vetor(vet);
	ordenar(vet);
	imprimir_vetor(vet);
}

void ler_vetor(int *vet){

	int i;

	for (i = 0; i < n; i++){
		printf("Digite o %d valor: ", i+1);
		scanf("%d", &vet[i]);
	}
}

void ordenar(int *vet){

	int i, j;
	int maior, menor;

	for (i = 0; i < n; i++)
		if (vet[i + 1] < vet[i])
			vet[i] = vet[i + 1];
}

void imprimir_vetor(int *vet){

	int i;

	for (i = 0; i < n; i++)
		printf("\nValor da %d posicao e: %d", i+1, vet[i]);

	printf("\n");
}