#include <stdio.h>

#define ERRO 0

int fatorial();

void main(){
	int n, fat;

	scanf("%d", &n);

	fat = fatorial(n);

	if (fat != ERRO)
		printf("\nFatorial de %d eh: %d\n", n, fat);
	else
		printf("\nNao eh Possivel Calcular o Fatorial de %d \n", n);


}

int fatorial(int n){
	
	int i;
    
    int fat = 1;
    
	if (n > 1){
		for (i = n; i > 0; i--)
			fat *= i;

		return fat;
	}
	else
		return ERRO;


	

}
