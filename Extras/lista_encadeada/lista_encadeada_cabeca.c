#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

	int conteudo;
	struct celula *proximo;

}Celula;

int inserir(Celula *le);
int remover(Celula *le);
void buscar(Celula *le);
Celula* buscar_recursivo(Celula *le, int x);
Celula *remover_recursivo(Celula *le, int x);


void listar(Celula *le);

void main(){

	// Declaracao da cabeça
	Celula *inicio = (Celula*)malloc(sizeof(Celula)); 
	inicio->proximo = NULL;

	int i;

	for (i = 0; i < 4; i ++)
		inserir(inicio);

	listar(inicio);
	buscar(inicio);
}
int inserir(Celula *le){

	int x;

	printf("Digite o Valor desejado: ");
	scanf("%d", &x);

	Celula *novo = le-> proximo;

	novo = (Celula*)malloc(sizeof(Celula));

	if (novo == NULL)
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

void buscar(Celula *le){

  int x;
  Celula *busca = le->proximo;

  printf("Digite o valor a ser buscado: ");
  scanf("%d", &x);

  while(busca != NULL){

    if(busca->conteudo == x){
      printf("Achei \n");
      break;
    }

    busca = busca->proximo;
  }
}

Celula* buscar_recursivo(Celula *le, int x){

	Celula *p = le->proximo;

	if (p == NULL) return NULL;
	if (p->conteudo == x){
	 printf("Achei\n");
	 return le;
	}

	return buscar_recursivo(p->proximo, x);
}

/*void remover(){

  int x;

  printf("Digite o o valor a ser removido: ");
  scanf("%d", &x);

  Celula *busca = inicio;
  Celula *anterior = NULL;

  while (busca != NULL){
    if(busca -> conteudo == x){
      if (busca == inicio)
        inicio = busca->proximo;
      else
        anterior->proximo = busca->proximo;
      
      free(busca);
      break;
    }
    anterior = busca;
    busca = busca->proximo;
  }
}
*/
Celula *remover_recursivo(Celula *le, int x){

	Celula *p = le->proximo;
	Celula *lixo = p->proximo;

	if (p == NULL) return NULL;
	
	if (p->conteudo == x){
		p->proximo = lixo->proximo;
		free(lixo);
		return le; 
	}

	return remover_recursivo(p->proximo, x);
}

int remover(Celula *le){

  int x;

  printf("Digite o o valor a ser removido: ");
  scanf("%d", &x);

  Celula *buscar = le->proximo;
  Celula *anterior = NULL;

  while (buscar != NULL){

    if(buscar->conteudo == x){

      if (buscar == le->proximo)
        le->proximo = buscar->proximo;
      else
        anterior->proximo = buscar->proximo;
      
      free(buscar);
    }

    anterior = buscar;
    buscar = buscar->proximo;
  }
}

void listar(Celula *le){

	Celula *p;

	if (p == NULL){
		printf("--- Fim da Lista --- \n\n");
		return ;
	}

	// Caso a lista não esteja vazia
	p = le->proximo;

	while (p != NULL){
		printf(" %d ->", p->conteudo);
		p = p->proximo;
	}

	printf("--- Fim da Lista --- \n\n");
}

int contList(Celula *le){
    
    int cont = 0;

    while(le!=NULL){
        cont++;
        le = le->proximo;
    }
    return cont;
}  
