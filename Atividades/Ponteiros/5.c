#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

	int conteudo;
	struct lista *proximo;

}Lista;

Lista* criarLista();
int inserirFinal(Lista *inicio, int valor);
int inserirOrdenado(Lista *inicio, int valor);
void exibirLista(Lista *inicio);

void main(){

	Lista *inicio = criarLista();
	
	inserirFinal(inicio, 10);
	inserirOrdenado(inicio, 1);
	inserirOrdenado(inicio, 4);
	inserirOrdenado(inicio, 6);
	inserirOrdenado(inicio, 8);
	inserirOrdenado(inicio, 11);

	exibirLista(inicio);
}

Lista* criarLista(){

	Lista *inicio = (Lista*)malloc(sizeof(Lista));

	if (inicio == NULL) 
		return NULL;

	inicio->proximo = NULL;

	return inicio;
}

int inserirFinal(Lista *inicio, int valor){

	if (inicio == NULL)
		return 0;

	Lista *novo = (Lista*)malloc(sizeof(Lista));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;
	novo->proximo = NULL;

	if (inicio->proximo == NULL){
		inicio->proximo = novo;
		return 1;
	}

	Lista *ultimo = inicio->proximo;

	while (ultimo->proximo != NULL)
		ultimo = ultimo->proximo;

	ultimo->proximo = novo;

	return 1;
}

int inserirOrdenado(Lista *inicio, int valor){

	if (inicio == NULL) // Se o espaco nao foi alocado saia da funcao
		return 0;

	Lista *novo = (Lista*)malloc(sizeof(Lista));

	if (novo == NULL) // Se o espaco nao foi alocado saia
		return 0;

	novo->conteudo = valor; // Atribuindo o valor ao novo elemento

	if (inicio->proximo == NULL){  // Se lista estiver vazia, insira no inicio
		novo->proximo = NULL;
		inicio->proximo = novo;

		return 1;
	}
 	
 	Lista *atual = inicio->proximo; // atual passa a ser o primeiro elemento da lista

 	if (atual->conteudo > valor){
 		novo->proximo = atual;
 		inicio->proximo = novo;

 		return 1;
 	}

 	Lista *anterior = atual; // anterior vai servir para armazenar sempre o antigo atual, já que nao existe um ponteiro chamado anterior;

 	while (atual != NULL && atual->conteudo < valor){
 		anterior = atual;
 		atual = atual->proximo;
 	}

 	if (atual != NULL){ // Se atual parou antes de chegar ao final, é por que achou algum valor maior que o que está sendo comparado
 		novo->proximo = atual;
 		anterior->proximo = novo;

 		return 1;
 	}

 	if (atual == NULL){ // Se não existir um valor maior que o atual, coloca ele na última posicao.
 		novo->proximo = NULL;
 		anterior->proximo = novo;

 		return 1;
 	} 
} 

void exibirLista(Lista *inicio){

	if (inicio == NULL)
		return;

	Lista *atual = inicio->proximo;

	while (atual != NULL){
		printf("-> %d", atual->conteudo);
		atual = atual->proximo;
	}
}