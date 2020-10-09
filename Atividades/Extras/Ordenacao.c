// Dificuldade 2, o retorno deve ser a quantidade de trocas.
// Dificuldade 3, o vetor preenchido deve ser de um arquivo
// 17 de Fevereiro entrega do Trabalho

#include <stdio.h>

#define n 5

void imprimir_vetor (int vet[]);
void preencher_vetor (int vet[]);
int bubble (int vet[]);
int selection (int vet[]);
int insert (int vet[]);

void main(){
    
    int vet[n];

    preencher_vetor(vet);

    int recebe_bubble = bubble(vet);

    printf("\n%d \n", recebe_bubble);
 }

 void preencher_vetor (int vet[]){

 	int i;

 	for (i = 0; i < n; i++)
 		scanf("%d", &vet[i]);
 }

void imprimir_vetor (int vet[]){

	int i;

	printf ("\n");
	for (i = 0; i < n; i++)
		printf("%d \n", vet[i]);
}
 int bubble (int vet[]){

 	int i, j;
 	int aux, cont = 0;

 	for (i = 0; i < n -1; i++)
 		for (j = 0; j < n - 1; j++)
 			if (vet[j] > vet[j + 1]){
 				aux = vet[j];
 				vet[j] = vet[j + 1];
 				vet[j + 1] = aux;

 				cont ++;
 			}
 	imprimir_vetor(vet);

 	return cont;

 }

 int selection(int vet[]){

 }

 int insert(int vet[]){

 }