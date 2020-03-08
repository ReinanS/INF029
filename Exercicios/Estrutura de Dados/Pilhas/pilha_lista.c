#include <stdio.h>
#include <stdlib.h>

struct posicao{

	int valor;
	struct posicao *prox;
}

typedef struct posicao Posicao;

Posicao *topo = NULL;

void main(){

}

int push (int v){

	Posicao *novo;
	novo = (Posicao*)malloc(sizeof(Posicao));

	if (novo != NULL){
		novo -> valor = v;
		novo -> prox = topo;
		topo = novo;

		return 1;

	}else
		return 0;
}

int pop (){

	int v;

	if (topo != NULL){
		v -> topo = valor;
		Posicao *t1 = topo;
		topo = topo->prox;
		free(t1);
		return v;

	}else
		return -1;
}

