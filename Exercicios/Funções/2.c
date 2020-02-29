#include <stdio.h>

int subtrai();

void main(){
	int a, b, c, resultado;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	resultado = subtrai(a, b, c);

	printf("\n%d\n\n", resultado);
}

int subtrai(int a, int b, int c){
	return a - b - c;
}