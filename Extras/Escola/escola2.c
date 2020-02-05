#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tamanho_P 3 // TAMANHO DO VETOR PESSOA
#define tamanho_D 2 //TAMANHO DO VETOR DISCIPLINA

#define SUCESSO_CADASTRO 5
#define SUCESSO_NOME 1
#define ERRO_NOME -1
#define SUCESSO_SEXO 2
#define ERRO_SEXO -2
#define SUCESSO_CPF 3
#define ERRO_CPF -3
#define SUCESSO_NASCIMENTO 4	
#define ERRO_NASCIMENTO -4

typedef struct dma{
	int dia, mes, ano;
}Data;

typedef struct pessoa{
	int matricula, ativo;
	char nome[50], cpf[15];
	char sexo;
	Data nascimento;
	int nas;
}Pessoa;

typedef struct dis{

	char nome[50], professor[50], semestre[20];
	int cod; 

}Disciplina;

Pessoa lista_Professor[tamanho_P];
Pessoa lista_Aluno[tamanho_P];
Disciplina lista_Disciplina[tamanho_D];

int auxiliar(); //AUXILIA O MAIN
int menu_Principal();
int menu_Pessoa();
int menu_Disciplina();
int inserir_Pessoa();
int valida_Nome(char nome[]);
int valida_Sexo(char sexo);
int valida_CPF(char cpf[]);
int valida_Nascimento(Pessoa lista[], int qtd, int idade);

void main(){

	auxiliar();
}

int auxiliar(){

	int opcao_Principal, opcao_Aluno;
	int qtd_Aluno;
	int voltar_Aluno;

	while(opcao_Principal != 4){

		opcao_Principal = menu_Principal();

		switch(opcao_Principal){

			case 1:{
				voltar_Aluno = 0;

				while(voltar_Aluno != 5){
					printf("\n### Menu Aluno ###\n\n");
					opcao_Aluno = menu_Pessoa();

					switch(opcao_Aluno){

						case 1: inserir_Pessoa(lista_Aluno, qtd_Aluno);
					}
				}
			}
		}
	}
}

int menu_Principal(){
	int op;

	printf("#### Menu Principal ### \n\n");
	printf("1 - Aluno\t");
	printf("2 - Professor\t");
	printf("3 - Disciplina\t");
	printf("4 - Sair\n");
	printf("\nDigite a sua Opcao: ");
	scanf("%d", &op);

	return op;
}

int menu_Pessoa(){
	int opcao;

	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Consultar\n");
	printf("4 - Apagar\n");
	printf("5 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao);

	return opcao;

}

int menu_Disciplina(){

	int opcao_Disciplina;

	printf("\n### Menu Disciplina ### \n\n");
	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Consultar\n");
	printf("4 - Apagar\n");
	printf("5 - Voltar\n\n");

	printf("Digite a sua opcao\n");
	scanf("%d",&opcao_Disciplina);

	return opcao_Disciplina;
}

int inserir_Pessoa(Pessoa lista[], int qtd){
	int nome, sexo, idade, cpf;

	printf("Digite Numero de Matricula: ");
	scanf("%d", &lista[qtd].matricula);
	getchar();

	printf("Digite Nome: ");
	fgets(lista[qtd].nome, 50, stdin);

	nome = valida_Nome(lista[qtd].nome);
	printf("\nNome %d", nome);

	printf("Digite o Sexo: ");
	scanf("%c", &lista[qtd].sexo);
	getchar();

	printf("Digite Data de Nascimento: ");
	scanf("%d", &idade);

	printf("Digite o CPF: ");
	fgets(lista[qtd].cpf, 15, stdin);
}

int valida_Nome(char nome[]){

	int tam = strlen(nome) - 1;

	if (tam > 0 && tam < 21)
		return SUCESSO_NOME;
	else 
		return ERRO_NOME;

}

int valida_Sexo(char sexo){

	sexo = toupper(sexo); // Convertendo Letras Minúsculas para Maiúsculas

	if (sexo == 'M' || sexo == 'F' || sexo == 'O')
		return SUCESSO_SEXO;
	else
		return ERRO_SEXO;
	
}

int valida_CPF(char cpf[]){

	int tam = strlen(cpf) - 1; // Retirando uma Posicao devido ao '\n'

	if (tam == 11 || tam == 14)
		return SUCESSO_CPF;
	else
		return ERRO_CPF;	
}

int valida_Nascimento(Pessoa lista[], int qtd, int idade){

	lista[qtd].nascimento.dia = idade / 1000000;
	lista[qtd].nascimento.mes = idade % 1000000 / 10000;
	lista[qtd].nascimento.ano = idade % 1000000 % 10000;
}






