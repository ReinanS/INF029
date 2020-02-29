#include <stdio.h>
#include <string.h>

int contarChar(char str[], char letra);

void main(){

	char palavra[50];
	char letra;
	int repete;

	printf("Digite a palavra: ");
	fgets(palavra, 50, stdin);

	printf("Digite a Letra a ser Consultada: ");
	scanf("%c", &letra);

	repete = contarChar(palavra, letra); 

	printf("\nA letra %c aparece %d vezes na Palavra. \n", letra, repete);
}

int contarChar(char str[], char letra){

	int i, tamanho, cont = 0;

	tamanho = strlen(str) - 1;

	for (i = 0; i < tamanho; i++)
		if (str[i] == letra)
			cont ++;

	return cont;
}