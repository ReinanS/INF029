// Serve para gravar dados de forma permanente,
// dependendo apenas da memória disponível pela mídia, 
// e não pela memória RAM.

/*
	Tipos de abertura

	- r: abertura somente para leitura
	- w: abertura para escrita, caso o arquivo não exista, ele o cria, e caso já exista, ele sobreescreve o existente.
	- a: abertura para escrita, acrescenta novos dados no final do arquivo existente, caso o arquivo não exista, ele o cria.
*/

// Leitura de caractere por caractere no arquivo
// getc(ponteiro_do_arquivo); enquanto for diferente de EOF.

#include <stdio.h>

// Exemplo de criação de arquivos
void criacaoDeArquivo() {
	// ponteiro para o arquivo
	FILE *pont_arq;

	// abrindo o arquivo
	pont_arq = fopen("arquivo.txt", "a");

	// fechando arquivo
	fclose(pont_arq);

	printf("O arquivo foi criado com Sucesso!\n");
}

// Exemplo de escrita no arquivo
int escritaArquivo() {
	
	FILE *pont_arq;
	char palavra[20];

	pont_arq = fopen("arquivo.txt", "w");

	if (pont_arq == NULL) {
		printf("Erro de Abertura do arquivo!\n");
		return 1;
	}

	printf("Escreva uma palavra para testar gravacao de arquivo: ");
	scanf("%s", palavra);

	// usando fprintf para armazenar a string no arquivo
	fprintf(pont_arq, "%s", palavra);

	fclose(pont_arq);

	printf("\nDados gravados com Sucesso!\n");
}

int leituraArquivo() {

	FILE *pont_arq;
	char texto_str[20];

	// abrindo o arquivo em modo "somente leitura"
	pont_arq = fopen("arquivo.txt", "r");

	if (pont_arq == NULL) {
		printf("Erro de abertura do Arquivo!");
		return 1;
	}

	// enquanto não for fim de arquivo o looping será executado
	// e será impresso o texto
	while(fgets(texto_str, 20, pont_arq) != NULL) {
		printf("%s", texto_str);
	}

	// fechando o arquivo
	fclose(pont_arq);

	return (0);
}

int main() {

	leituraArquivo();
	
}