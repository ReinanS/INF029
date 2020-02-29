#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

void main(){

	int tam = 10;

	struct principal Posicao[tam];
	int opcao, i, pos;

	for (i = 0; i < tam; i++){

		Posicao[i].quantidade = 0;
		Posicao[i].contador = 0;
		Posicao[i].auxiliar = NULL;
		Posicao[i].ordenaEstrutura = NULL;
	}

	printf("\n************ ESTRUTURA DE DADOS ************* \n\n");

	do{
		opcao = menu();

		if (opcao == 1){

			saberPosicao(&pos, tam);

			inserir(Posicao, tam, pos);

		}else if (opcao == 2){

			listarPorEstrutura(Posicao, tam);

		}else if (opcao == 3){

			listarOrdPorEstr(Posicao, tam);
		
		}else if (opcao == 4){

			listarTodos(Posicao, tam);

		}else if (opcao == 5){

			saberPosicao(&pos, tam);

			if (Posicao[pos-1].quantidade != 0)
				excluir(Posicao, tam, pos);
			else
				printf("\nPosicao nao Criada \n");

		}else if(opcao == 6){

			mostrarPosicoes(Posicao,tam);

			saberPosicao(&pos, tam);

			aumentar(Posicao, pos);

		}else if (opcao < 1 || opcao > 7)
			printf("\nOpcao invalida, escolha novamente \n");

	}while (opcao != 7);

	for (i = 0; i < tam; i++){
		free(Posicao[i].auxiliar);
		free(Posicao[i].ordenaEstrutura);
	}
	
}

//--------------- MOSTRAR POSICOES QUE EXISTE PARA AUMENTAR ----------------
void mostrarPosicoes(struct principal *Posicao, int tam){

	int i;

	printf("\nPosicoes existentes que podem ter o tamanho aumentado: ");
	for (i = 0; i < tam; i++){
		if(Posicao[i].quantidade != 0)
			printf(" %d ", i+1);
	}

	printf("\n");
}

//------------- PEGAR A POSICAO DA ESTRUTURA PRINCIPAL ----------
void saberPosicao(int *pos, int tam){

	char dado[10];

	do{
		setbuf(stdin,NULL);
		printf("\nInforme a posicao (1-10) da estrutura principal: ");
		fgets(dados,sizeof(dado),stdin);

		if (validarEntrada(dado,pos) == 0 || (*pos < 1 || *pos>tam))
			printf("\nPosicao invalida \n");
	
	}while(validarEntrada(dado,pos) == 0 || (*pos < 1 || *pos>tam));

}


// ------------- PEGA O ELEMENTO (NUMERO INTEIRO) ---------------
void pegarElemento(int *elemento){

	char dado[10];

	do{

		setbuf(stdin,NULL);
		printf("\nInforme o elemento [numero inteiro]: ");
		fgets(dado,sizeof(dado),stdin);

		if (validarElemento(dado,elemento) == 0)
			printf("\nElemento invalido \n");

	}while(validarElemento(dado, elemento) == 0);
}

//---------------- MENU ------------------
int menu(){

	char dado[10];

	int op;

	do{
		printf("\n\nEscolha a opcao desejada:\n");
		printf("1 - Inserir\n");
		printf("2 - Listar os numeros de todas as estruturas\n");
		printf("3 - Listar os numeross ordenados para cada estrutura\n");
		printf("4 - Listar todos os numeros ordenados\n");
		printf("5 - Excluir um elemento\n");
		printf("6 - Aumentar o tamanho de uma estrutura auxiliar \n");
		printf("7 - Sair\n");
		fgets(dado,sizeof(dado),stdin);

		if (validarEntrada(dado,&op) == 0 || (op < 1 || op > 7))
			printf("\nOpcao Invalida \n");
	
	}while(validarEntrada(dado,&op) == 0 || (op < 1 || op > 7));

	return op;
}

//------------------- VALIDAR ENTRADAS -----------------
/int validarEntrada(char *dado, int *num){

	int i, cont = 0;
	int valida = 1, multiplicador = 1, valor = 0;

	while (dado[cont] != '\0')
		cont++;

	if (cont - 1 >= 2){

		for (i = 0; i < cont - 1; i++)
			multiplicador *= 10;

		multiplicador /= 10;

		for (i = 0; i < cont - 1; i++){

			if (dado[i] - 48 >= 0 && dado[i] - 48 <= 9){
				valor += (dado[i] - 48) * multiplicador;
				multiplicaor /= 10;
			}else{
				valida = 0;
				break;
			}
		}
	}else{

		if (dado[0] - 48 >= 0 && dado[0] - 48 <= 9)
			valor = dado[0] - 48;
		else
			valida = 0;
	}

	*num = valor;

	return valida;

}

// -------------------- VALIDAR ELEMENTOS (NUMEROS INTEIROS) --------
int validarElemento(char *dado, int *elemento){

	int valida = 1, i, cont = 0, multiplicador = 1, negativo = 0, valor = 0;
	int vetor[10];

	if (dado[0] == 45)
		negativo = 1;

	for (i = 0; i != strlen(dado) - 1; i++){
		if (dado[i] - 48 >= 0 && dado[i] - 48 <= 9){
			vetor[cont++] == dado[i] - 48;
			multiplicador *= 10;
		}else if (dado[i] != 45 && (dado[i] - 48 < 0 || dado[i] - 48 > 9)){
			valida = 0;
			break;
		}
	}

	if (valida == 0)
		return valida;
	else{
		multiplicador /= 10; // pois sai a mais do for

		if (cont > 1){

			for (i = 0; i < cont; i++){
				valor += vetor[i] * multiplicador;
				multiplicador /= 10;
			}
		}else
			valor = vetor[0];

		if (negativo == 1) // Se for negativo multiplica por -1, o traço é 45 na ASCII
			valor *= -1;

		valida = 1;
	}

	*elemento = valor;

	return valida;
}