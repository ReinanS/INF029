#include <stdio.h> 
#include <stdlib.h>
#include "ReinanSantos-2019116042-T2.h"

void show_log(char *str);

void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeListar();

int main() {

	inicializar();
	testeCriarEstrutura();
	testeInserirComEstrutura();
   	finalizar();

	return 0;
}

int ligado = 1;
void show_log(char *str){
    if (ligado)
        printf("###%s###\n", str);
}

void testeCriarEstrutura(){
    show_log("testeCriarEstrutura()");

    printf("%d\n",criarEstruturaAuxiliar(5, 1) == SUCESSO);
    printf("%d\n",criarEstruturaAuxiliar(3, 2) == SUCESSO);
}

void testeInserirComEstrutura(){
    show_log("testeInserirComEstrutura()");
  
    printf("%d\n",inserirNumeroEmEstrutura(4, 1) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(2, 1) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(4, 1) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(1, 1) == SUCESSO);

    printf("%d\n",inserirNumeroEmEstrutura(8, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(1, 2) == SUCESSO);

} 
