#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int conteudo;
	struct celula *proximo;

}Celula;

// le = Lista Encadeada

int inserir(Celula *le);
int buscar(Celula *le);
Celula* buscar_recursivo(Celula *le, int x);
int remover(Celula *le);
Celula *remover_recursivo(Celula *le, int x);
void listar(Celula *le);

void main(){

	// Declaracao da cabeça
	Celula *inicio = (Celula*)malloc(sizeof(Celula)); 
	inicio->proximo = NULL;

	int i;
	for (i = 0; i < 4; i ++)
		inserir(inicio);

	remover_recursivo(inicio, 4);
	listar(inicio);
}

int inserir(Celula *le){

	int x;

	printf("Digite o Valor desejado: ");
	scanf("%d", &x);

	Celula *novo = le->proximo; //Por quê o inicio é uma cabeca, senão seria *novo = le->proximo.

	novo = (Celula*)malloc(sizeof(Celula));

	if (novo == NULL) // Se não existir mais memória para ser alocada, ele retorna 0.
		return 0;

	novo->conteudo = x;
	novo->proximo = NULL;
	
	if (le-> proximo == NULL)
		le-> proximo = novo;
	else{
		novo->proximo = le->proximo;
		le->proximo = novo; 
	}

	return 1;

}

int buscar(Celula *le){

  int x;
  Celula *busca;

  printf("Digite o valor a ser buscado: ");
  scanf("%d", &x);

  for (busca = le->proximo; busca != NULL; busca = busca->proximo)
  	if (busca->conteudo == x){
  		printf("Achei \n");
  		return 1;
  	}

  printf("Nao Achei \n");
  return 0;

}

Celula* buscar_recursivo(Celula *le, int x){

	Celula *p = le->proximo;

	if (p == NULL){
		printf("Nao Achei\n");
	 	return NULL;
	}
	
	if (p->conteudo == x){
		printf("Achei\n");
	 	return le;
	}

	return buscar_recursivo(p->proximo, x);
}

int remover(Celula *le){

  int x;

  printf("Digite o o valor a ser removido: ");
  scanf("%d", &x);

  Celula *busca;
  Celula *anterior;

  for (anterior = NULL, busca = le->proximo; busca != NULL; anterior = busca, busca = busca->proximo){
  	if(busca ->conteudo == x){
  		if (busca == le->proximo)
  			le->proximo = busca->proximo;
  		else
  			anterior->proximo = busca->proximo;

  		free(busca);
  		
  		printf("Removido\n");
  		return 1;
  	}

  }

  printf("Nao Removido\n");
  return 0;
  
}

Celula *remover_recursivo(Celula *le, int x){


	Celula *busca = le->proximo;
	Celula *anterior = NULL;
	

	if (busca == NULL){ 
		printf("Nao Achado\n");
		return NULL;
	}
	
	if (busca->conteudo == x){
		if (busca == le->proximo)
			le->proximo = busca->proximo;
		else
			anterior->proximo = busca->proximo;

		free(busca);
		printf("Removido\n");
		return le;
	}

	return remover_recursivo(busca->proximo, x);
}

void listar(Celula *le){

	Celula *p;

	if (p == NULL){
		printf("--- Fim da Lista --- \n\n");
		return ;
	}

	// Caso a lista não esteja vazia

	for (p = le->proximo; p != NULL; p = p->proximo)
		printf(" %d ->", p->conteudo);

	printf("--- Fim da Lista --- \n\n");
}

int contList(Celula *le){
	
	Celula *p;    
    int cont = 0;

   for (p = le; p != NULL; p = p->proximo)
   		cont ++;

    return cont;
}  
