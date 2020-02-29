#include <stdio.h>

int soma();

void main(){

	int a, b, resultado;

	scanf("%d", &a);
	scanf("%d", &b);

	resultado = soma(a, b);

	printf("\nA Soma entre %d e %d eh: %d", a, b, resultado);

}

int soma(int a, int b){

	return a + b;
}