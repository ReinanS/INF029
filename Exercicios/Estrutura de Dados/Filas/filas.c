#include <stdio.h>
#include <stdlib.h>

struct Node {
	int num;
	struct node *proximo;
};
typedef struct Node node;

void main(){

	node *fila = (node*)malloc(sizeof(node));

	int tam;

	if (!fila){
		printf("Sem memoria disponível! \n");
		exit(1);
	
	}else
		inicia(fila, &tam);	
}

void inicia(node *fila, int *tam){

	fila->proximo = NULL;

	*tam = 0;
}

int vazia(node )