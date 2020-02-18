#include <stdio.h>
#include <stdlib.h>

typedef struct celula {

	int conteudo;
	struct celula *proximo;

}celula;

void insere_na_lista(int x, celula *p);
void imprime_lista(celula *le);

void main(){

	celula *inicio = NULL; // Inicializando lista vazia
	
	int a = 5;
//	celula *novo = insere(inicio, a);

	insere_na_lista(a, inicio);
	imprime_lista(inicio);
}

void insere_na_lista(int x, celula *p){

	// Supõe-se que p!= NULL;

	celula *novo = (celula*)malloc(sizeof(celula));
	novo ->conteudo = x;
	novo -> proximo = p ->proximo;
	p -> proximo = novo;
}

celula* insere (celula *p, int x){

	celula *novo = (celula*) malloc(sizeof(celula));
	novo -> conteudo = x;
	novo -> proximo = p;

	return novo;
}

void imprime_lista(celula *le){

	if (le != NULL){
		printf("%d \n", le -> conteudo);
		imprime_lista(le -> proximo);
	
	}else
		printf("Fim da Lista \n\n");
}