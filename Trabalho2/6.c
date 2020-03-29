/*

- Lista Duplamente encadeada
- Insere na lista já ordenado

 */

#include <stdio.h>
#include <stdlib.h>

struct lista{

	int conteudo;
	struct lista *anterior;
	struct lista *proximo;
};

typedef struct lista Lista;

Lista* criarLista(){

	Lista *inicio = (Lista*)malloc(sizeof(Lista));

	if (inicio == NULL)
		return NULL;

	inicio->anterior = NULL;
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

	if (inicio->proximo == NULL){ // Se a lista estiver vazia

		novo->proximo = NULL;
		novo->anterior = inicio->proximo;

		inicio->proximo = novo;

		return 1;
	}

	//NULL 3
	//5
	
	Lista *ultimo = inicio->proximo;

	while (ultimo->proximo != NULL)
		ultimo = ultimo->proximo;

	novo->anterior = ultimo;
	novo->proximo = NULL;

	ultimo->proximo = novo;

	return 1;
}

void display(Lista *inicio){

	Lista *atual = inicio->proximo;

	// Imprimindo do Inicio para o Final
	while (atual != NULL){
		printf("-> %d", atual->conteudo);
		atual = atual->proximo;
	}

	printf("\n");

	atual = inicio->proximo;

	// Procuando o Ultimo elemento
	while(atual->proximo != NULL) 
		atual = atual->proximo;

	// Imprindo do Final para o Inicio
	while (atual != NULL ){ 
		printf("-> %d", atual->conteudo);
		atual = atual->anterior;
	}
}

void main(){

	Lista *inicio = criarLista();

	inserirFinal(inicio, 4);
	inserirFinal(inicio, 7);
	inserirFinal(inicio, 9);

	display(inicio);
}