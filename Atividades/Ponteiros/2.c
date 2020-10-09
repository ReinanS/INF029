#include <stdio.h>

void troca(int *a, int *b);

void main(){

	int n1, n2;

	scanf("%d", &n1);
	scanf("%d", &n2);

	int *pN1 = &n1;
	int *pN2 = &n2;

	troca(pN1, pN2);

	printf("\nValor de N1 = %d \nValor de N2 = %d \n\n", *pN1, *pN2);
}

void troca(int *a, int *b){

	int c;

	c = *a;
	*a = *b;
	*b = c;
}