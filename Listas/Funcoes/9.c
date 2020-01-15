#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

	char nome[50];
	char sexo;
	char cpf[15];
	Data nascimento;

}Pessoa;

Pessoa cliente;

int cadastrarCliente();
int validaNome(char nome[]);
int validaSexo(char sexo);
int validaCPF(char cpf[]);
int validaNascimento(int nascimento);

void main(){

	int cadastro;

	cadastro = cadastrarCliente();

	printf("\n");

	if (cadastro == SUCESSO_CADASTRO)
		printf("Cadastro Realizado com Sucesso\n");

	else{
		switch(cadastro){

			case ERRO_NOME: printf("Nome Maior que 20 Caracteres\n"); break;

			case ERRO_SEXO: printf("Sexo Invalido\n"); break;

			case ERRO_CPF: printf("CPF Invalido\n"); break;

			case ERRO_NASCIMENTO: printf("Data de Nascimento Invalida\n"); break;
		}
	}

	
}

int cadastrarCliente(){ //PROBLEMAS GRAVES AO VALIDAR FUNCOES
	
	int nome, sexo, cpf, nascimento;

	printf("Digite o seu Nome: ");
	fgets(cliente.nome, 50, stdin);

	nome = validaNome(cliente.nome);

	if (nome == ERRO_NOME)
		return ERRO_NOME;

	printf("Digite o seu Sexo: ");
	scanf("%c", &cliente.sexo);	
	getchar(); // Limpando Buffer do Teclado 

	sexo = validaSexo(cliente.sexo);

	if (sexo == ERRO_SEXO)
		return ERRO_SEXO;

	printf("Digite o seu CPF: ");
	fgets(cliente.cpf, 50, stdin);

	cpf = validaCPF(cliente.cpf);

	if (cpf == ERRO_CPF)
		return ERRO_CPF;

	printf("Digite a sua Data de Nascimento: ");
	scanf("%d", &nascimento);

	nascimento = validaNascimento(nascimento);
	
	if (nascimento == ERRO_NASCIMENTO)
		return ERRO_NASCIMENTO;


	return SUCESSO_CADASTRO;	
}

int validaNome(char nome[]){

	int tam = strlen(nome) - 1;

	if (tam > 0 && tam < 21)
		return SUCESSO_NOME;
	else 
		return ERRO_NOME;

}

int validaSexo(char sexo){

	sexo = toupper(sexo); // Convertendo Letras Minúsculas para Maiúsculas

	if (sexo == 'M' || sexo == 'F' || sexo == 'O')
		return SUCESSO_SEXO;
	else
		return ERRO_SEXO;
	
}

int validaCPF(char cpf[]){

	int tam = strlen(cpf) - 1; // Retirando uma Posicao devido ao '\n'

	if (tam == 11 || tam == 14)
		return SUCESSO_CPF;
	else
		return ERRO_CPF;	
}

int validaNascimento(int nascimento){
	
	int cont = 0;

	cliente.nascimento.dia = nascimento / 1000000;
	cliente.nascimento.mes = nascimento % 1000000 / 10000;
	cliente.nascimento.ano = nascimento % 1000000 % 10000;

	if (cliente.nascimento.dia < 1 || cliente.nascimento.dia > 31)
		cont ++;
	if (cliente.nascimento.mes < 1 || cliente.nascimento.mes > 12)
		cont ++;
	if (cliente.nascimento.ano < 1 || cliente.nascimento.ano > 2019)
		cont ++;

	if (cont == 0)
		return SUCESSO_NASCIMENTO;
	else
		return ERRO_NASCIMENTO;


}

