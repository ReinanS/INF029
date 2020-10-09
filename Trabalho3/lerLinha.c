// Copia o que tem em tmp.txt para tmpCopy.txt 
// Copiando Linha a linha.

#include <stdio.h>

#define MAX 80

int main() {

	int qtdLinhas = 0;
	char linha[MAX];
	FILE *input, *output;

	input = fopen("tmp.txt", "r");

	if(input) {
		output = fopen("tmpCopy.txt", "w");
		fgets(linha, MAX, input);

		while(!feof(input)) {	
			fputs(linha, output);
			fgets(linha, MAX, input);
			qtdLinhas++;
		}

		fclose(output);
		fclose(input);
		
		printf("%d \n", qtdLinhas);

	} else {
		printf("Não\n");
	}

}