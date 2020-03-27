#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

	int conteudo;
	struct lista *proximo;

}Lista;

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

void main(){

	Lista *inicio = criarLista();

	inserirFinal(inicio, 2);
	
	exibirLista(inicio);
}