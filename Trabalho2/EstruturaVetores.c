#include <stdio.h>
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

Principal vetorPrincipal[TAM];

void dobrar(int *x){

    *x = *x * 2;


}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar(){

  int i;

  for (i = 0; i < TAM; i++){
    vetorPrincipal[i].auxiliar = NULL;
    vetorPrincipal[i].contador = 0;
    vetorPrincipal[i].tamanho = 0;
  }
    
}


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

RertoPrincipal (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1

*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
  
  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao-1].auxiliar != NULL)
    return JA_TEM_ESTRUTURA_AUXILIAR;
  
  if (tamanho < 1)
    return TAMANHO_INVALIDO;
  
  vetorPrincipal[posicao-1].auxiliar = (int*)malloc(tamanho*sizeof(int)); // AUXILIAR É UM PONTEIRO DO TIPO INTEIRO

  if (vetorPrincipal[posicao-1].auxiliar == NULL)
      return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao-1].tamanho = tamanho;
  
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
RertoPrincipal (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    // 12445
CONSTANTES
    JÁ TEM 
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao-1].auxiliar == NULL )
        return SEM_ESTRUTURA_AUXILIAR;
    
    int contador = vetorPrincipal[posicao-1].contador;

    if (contador >= vetorPrincipal[posicao-1].tamanho)
      return SEM_ESPACO;

    vetorPrincipal[posicao-1].auxiliar[contador] = valor;
    vetorPrincipal[posicao-1].contador ++; // ELE CONSEGUIU COLOCAR O VALOR NA ESTRUTURA

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar Principal final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

RertoPrincipal (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao-1].auxiliar == NULL)
      return SEM_ESTRUTURA_AUXILIAR;
  
    if (vetorPrincipal[posicao-1].contador == 0) // DEPOIS VERIFICAR SE EXISTE OUTRA FORMA
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao-1].contador --; // EXCLUSÃO LÓGICA
  
  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
RertoPrincipal (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

    int i, j;
    int existe = 0;
    int aux;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao-1].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao-1].contador == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int contador = vetorPrincipal[posicao-1].contador;

    if (contador == 1 && vetorPrincipal[posicao-1].auxiliar[0] == valor){
      existe = 1;
    
    }
    else
      for (i = 0; i < contador-1; i++)
        
        if (vetorPrincipal[posicao-1].auxiliar[i] == valor){
          aux = vetorPrincipal[posicao-1].auxiliar[i];
          vetorPrincipal[posicao-1].auxiliar[i] = vetorPrincipal[posicao-1].auxiliar[i+1];
          vetorPrincipal[posicao-1].auxiliar[i+1] = aux;

          existe = 1;
        }
    
    if (existe == 0)
        return NUMERO_INEXISTENTE;
    else
      vetorPrincipal[posicao-1].contador --;
    
    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorPrincipal = 0;
    if (posicao < 1 || posicao > 10){
        retorPrincipal = POSICAO_INVALIDA;
    }else retorPrincipal = SUCESSO;

    return retorPrincipal;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

RetorPrincipal (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void getDadosAux(int posicao, int vetorAux[], int n){

    int i;

    for (i = 0; i < n; i++)
        vetorAux[i] = vetorPrincipal[posicao-1].auxiliar[i];
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao-1].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int contador = vetorPrincipal[posicao-1].contador;

    getDadosAux(posicao,vetorAux, contador);

    return SUCESSO;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

RertoPrincipal (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void bubble(int vet[], int n){

    int i, j, aux;

    for (i = n -1; i > 0; i--)
        for (j = 0; j < i; j++)
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao-1].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int contador = vetorPrincipal[posicao-1].contador;

    getDadosAux(posicao,vetorAux,contador);

    bubble(vetorAux, contador);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

RertoPrincipal (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorPrincipal = 0;
    return retorPrincipal;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

RertoPrincipal (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorPrincipal = 0;
    return retorPrincipal;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o Principalvo tamanho 'PrincipalvoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e Principalvo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

RertoPrincipal (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    PrincipalVO_TAMANHO_INVALIDO - Principalvo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do Principalvo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int PrincipalvoTamanho){

    int retorPrincipal = 0;
    return retorPrincipal;

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

RetorPrincipal (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorPrincipal = 0;


    return retorPrincipal;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

RetorPrincipal (Principal*)
    NULL, caso não tenha nenhum número nas listas
    Principal*, ponteiro para o início da lista com cabeçote
*/
Principal* montarListaEncadeadaComCabecote(){

    return NULL;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
RetorPrincipal void
*/
void getDadosListaEncadeadaComCabecote(Principal* inicio, int vetorAux[]){


}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.

RetorPrincipal 
    void.
*/
void destruirListaEncadeadaComCabecote(Principal* inicio){
   

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    
    
}

