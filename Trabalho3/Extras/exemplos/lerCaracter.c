// Copia o que tem em tmp.txt para tmpCopy.txt 
// Copiando caracter a caracter.
#include <stdio.h>

#define MAX 80

int main() {

	int qtdLinhas = 0;
	char ch;
	FILE *input, *output;

	input = fopen("tmp.txt", "r");

	if(input) {
		// Se output nao existir, ele vai criar um novo arquivo
		output = fopen("tmpCopy.txt", "w");
		ch = fgetc(input);

		while(ch != EOF) {
			fputc(ch, output);
			ch = fgetc(input);
		}

		fclose(output);
		fclose(input);
	
	} else {
		printf("Não Abriu Input\n");
	}
}