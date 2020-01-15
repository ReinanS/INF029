#include <stdio.h>

typedef struct dma{

	int dia, mes, ano;

}Data;

typedef struct pessoa{

	char nome[50], cpf[15];
	Data data_nascimento;
	char sexo;

}Pessoa;

Pessoa cliente;
int data;
int i;

Pessoa cadastrar_cliente();

void main(){
	cadastrar_cliente();

	printf("\n%s", cliente.nome);
	printf("%d/%d/%d\n", cliente.data_nascimento.dia, cliente.data_nascimento.mes, cliente.data_nascimento.ano);
	printf("%s \n", cliente.cpf);
	printf("%c \n", cliente.sexo);

}

Pessoa cadastrar_cliente(){

	printf("Nome: ");
	fgets(cliente.nome, 50, stdin);
		
	printf("Data de Nascimento: ");
	scanf("%d", &data);
	getchar();

	cliente.data_nascimento.dia = data / 1000000;
	cliente.data_nascimento.mes = data % 1000000 / 10000;
	cliente.data_nascimento.ano = data % 1000000 % 10000;

	printf("Digite CPF no formato: xxx.xxx.xxx-xxx \n");
	fgets(cliente.cpf, 15, stdin);
	getchar();
	
	printf("Sexo:");
	scanf("%c", &cliente.sexo);

	return cliente;
}
