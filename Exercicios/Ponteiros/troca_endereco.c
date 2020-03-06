#include <stdio.h>
#include <stdlib.h>

void troca(int **n);

void main(){

	int a;
	int *aPtr;

	aPtr = &a;

	printf("ANTES: %p \n", aPtr);
	
	troca(&aPtr); // PEGO O ENDERECO DO PONTEIRO

	printf("DEPOIS: %p\n", aPtr); 

}

// USO DE PONTEIRO PARA PONTEIRO

void troca(int **n){

	int *x = (int*)malloc(sizeof(int));

	*n = x;
}