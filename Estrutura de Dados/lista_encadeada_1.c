#include <stdio.h>
#include <stdlib.h>

//CRIANDO ESTRUTURA
typedef struct reg {
	
	int conteudo;
	struct reg *prox;
	
}celula;

//CRIA IINICIO DA LISTA
celula *inicio = NULL;

void main(){



}

// DEFINE A LISTA COMO VAZIA
void criar_lista(){

	inicio = NULL;
}

/* Funcao que insere um elemento do inicio da lista.
 Retorna:
	0 - se nao ha'  memoria para inserir
	1 - se conseguiu inserir
*/
int insere(int dado){

	celula *p;

	p = (celula *) malloc(sizeof(celula));

	if (p == NULL){

		printf("Erro de Alocacao \n");
		return 0;
	}

	p -> conteudo = dado;
	p -> prox = NULL;

	if (inicio == NULL)
		inicio = p;
	
	else{

		p -> prox = inicio;
		inicio = p;
	}

	return 1;

}

// Esta função recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endereço de uma celula que contém x.
// Se tal celula não existe, devolve NULL.

celula *busca(int x, celula *le){

	celula *p;
	p = le;

	while(p != NULL && p -> conteudo != x)
		p = p -> prox;

	return p; 
}

// Funcao busca usando recursividade

celula *busca_re(int x, celula *le){

	if (le == NULL) return NULL;
	
	if (le -> conteudo == x) return le;

	return busca_re (x,le -> prox);
}

