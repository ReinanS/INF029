// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Reinan de Souza Santos
//  email: reinandesouza01@gmail.com
//  Matrícula: 2019116042
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */

int valida_data_numeros(int dia, int mes, int ano);
int procura_char(char c);

int q1(char *data){
   
    int iDia;
    int iMes;
    int iAno;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
   
    // DIA 
    int i;
    
    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];
        
        if (i > 1) return 0; //NO MAXIMO 2 NUMEROS ANTES DE '/'
        
        if (procura_char(sDia[i]) == 1) return 0; // 
        
    }
    
    sDia[i] = '\0';
    i++;
    
    if (strlen(sDia) == 0) return 0; // VERIFICA SE É IGUAL A 0
    
    iDia = atoi(sDia); //CONVERTE STRING EM INTEIRO
    
    
    //MES 
    
    int j;
    int cont_Mes = 0;
    
    for (j = i; data[j] != '/'; j++, cont_Mes++){
        
        sMes[cont_Mes] = data[j];
        
        if (cont_Mes > 1) return 0; 
        
        if (procura_char(sMes[cont_Mes]) == 1) return 0;
        
    }

    
    sMes[j] = '\0';
    j++;
    
    
    if (strlen(sMes) == 0) return 0;
    
    iMes = atoi(sMes);
    
    // ANO
   int cont_Ano = 0;
   
   for (i = j; i < strlen(data); i++, cont_Ano++){
       
       sAno[cont_Ano] = data[i];
       
       if (procura_char(data[i]) == 1) return 0;
   }
   
    if (cont_Ano != 2 && cont_Ano != 4) return 0; //SÓ ACEITA SE O ANO SE TIVER 2 OU 4 DIGITOS
    
    sAno[cont_Ano] = '\0';
    
    iAno = atoi(sAno);
   
        
    //validar
    int retorno = valida_data_numeros(iDia, iMes, iAno);
    
    return retorno;

}
int valida_data_numeros(int dia, int mes, int ano){
    
		 
    if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (ano < 1 || ano > 2020))
        return 0;
    
    if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11) )
        return 0;
    
    //FEVEREIRO
    if (dia > 29 && (mes == 2 && ano % 4 == 0 || ano % 400 == 0 && ano % 100 != 0) ) // ANO BISSEXTO
        return 0;
    if (dia > 28 && (mes == 2 && ano % 4 != 0 || ano % 400 != 0 && ano % 100 == 0) )
        return 0;
        
    	
    return 1;
   
}

int procura_char(char c){
    if (c < 48 || c > 57)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    char sDia[3], sMes[3], sAno[5];

    int iDiaInicial, iMesInicial, iAnoInicial;
    int iDiaFinal, iMesFinal, iAnoFinal;
    
    int i, j, cont_Mes = 0, cont_Ano = 0;

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;


    // Validando Datas
    if (q1(datainicial) == 0)
        return 2;
    if (q1(datafinal) == 0)
        return 3;
    
    // Capturando Valores da Data Inicial
    
    for (i = 0; datainicial[i] != '/'; i++) // Dia
        sDia[i] = datainicial[i];
    
    sDia[i] = '\0';
    i++;
    
    for (j = i, cont_Mes = 0; datainicial[j] != '/'; j++, cont_Mes++) // Mês
        sMes[cont_Mes] = datainicial[j];
    
    sMes[j] = '\0';
    j++;
   
    for (i = j, cont_Ano = 0; i < strlen(datainicial); i++, cont_Ano++) // Ano
       sAno[cont_Ano] = datainicial[i];
    
    sAno[cont_Ano] = '\0';
   
   // Convertendo String em Inteiro
    iDiaInicial = atoi(sDia); 
    iMesInicial = atoi(sMes);
    iAnoInicial = atoi(sAno);
    
    // Capturando Valores da Data Final
    
   for (i = 0; datafinal[i] != '/'; i++) // Dia
        sDia[i] = datafinal[i];
    
    sDia[i] = '\0';
    i++;
    
    for (j = i, cont_Mes = 0; datafinal[j] != '/'; j++, cont_Mes++) // Mês
        sMes[cont_Mes] = datafinal[j];
    
    sMes[j] = '\0';
    j++;
   
    for (i = j, cont_Ano = 0; i < strlen(datafinal); i++, cont_Ano++) // Ano
       sAno[cont_Ano] = datafinal[i];
    
    sAno[cont_Ano] = '\0';
   
    // Convertendo String em Inteiro
    iDiaFinal = atoi(sDia); 
    iMesFinal = atoi(sMes);
    iAnoFinal = atoi(sAno);
    
    // Se Data Inicial for Maior que a Data Final
    if (iAnoFinal < iAnoInicial || (iAnoFinal == iAnoInicial && iMesFinal < iMesInicial) || (iAnoFinal == iAnoInicial && iMesFinal == iMesInicial && iDiaFinal < iDiaInicial))
        return 4;
    
    int mesFinalAnterior = iMesFinal - 1; // Se o dia Final for menor que o dia Inicial ele vai pegar emprestado todos os dias do mês Final
    
    if (iDiaFinal < iDiaInicial){
        
        if (mesFinalAnterior == 2){ // Fevereiro
            
            if (mesFinalAnterior % 4 == 0 || mesFinalAnterior % 400 == 0 && (mesFinalAnterior % 100 != 0) ) // Ano Bissexto
                iDiaFinal += 29;
            else
                iDiaFinal += 28;
        }
        
        if (mesFinalAnterior == 4 || mesFinalAnterior == 6 || mesFinalAnterior == 9 || mesFinalAnterior == 11)
            iDiaFinal += 30;
        else
            iDiaFinal += 31;
        
        iMesFinal --;
    }
    
    if (iMesFinal < iMesInicial){
        
        iMesFinal += 12;
        iAnoFinal --;
    }
    
    nDias = iDiaFinal - iDiaInicial;
    nMeses = iMesFinal - iMesInicial;
    nAnos = iAnoFinal - iAnoInicial;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    
    int qtdOcorrencias = 0;
    int i;
    
    if (isCaseSensitive == 1)
        for (i = 0; i < strlen(texto); i++)
            if (texto[i] == c)
                qtdOcorrencias ++;
    
    if (isCaseSensitive != 1)
        for(i = 0; i < strlen(texto); i++)
            if (texto[i] == c || texto[i] == toupper(c) || texto[i] == tolower(c)) // Toupper = Caractere em Maiúsculo; Tolower = Caractere em Minúsculo.
                qtdOcorrencias++;
    

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. 
    
    Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser Ado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){


    int A, B,C, acentos;
    int qtdOcorrencias; 
    
    A = B = C = acentos = qtdOcorrencias = 0; // Atribuindo 0 em todas as variáveis

    for(A = 0; A <strlen(strTexto); A ++){

       if(strBusca[0] == strTexto[A]){ // Comparando posicao Inicial
           
           while(strBusca[B] == strTexto[A]){
             A ++;
             B ++;             
          }
        
          if(B == strlen(strBusca)){             
           
            posicoes[C] = A - (strlen(strBusca) - 1) - acentos; // Posicao Inicial
            C ++;
           
            posicoes[C] = A - acentos; // Posicao Final
            C ++;            
          }
          
          B = 0; // Necessário para  as novas palavras iguais
       }
       
       if(strTexto[A] < 0 && strTexto[A + 1] < 0) // Contando Acentos que estão na posicao A do texto e também na seguinte
           acentos ++; 
    }
   

    qtdOcorrencias = C/2;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
    
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
 */

int q5(int num){
    
   int inverso = 0; // Inicializa com 0 para a primeira interação
   int aux;
        
   while (num > 0){

        aux = num % 10;
        inverso = inverso * 10 + aux; // Modo Incorreto = inverso *= 10 + aux;
        num /= 10;
   }

   return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
   
   int aux, qtdOcorrencias = 0;

   int tamanho = 1;

   aux = numerobusca;

   while (aux != 0){ // Enquanto numero de busca for diferente de zero, ele vai continuar dividindo e armazendo o tamanho do numero
    tamanho = tamanho * 10;
    aux /= 10;
   }

   aux = numerobase;

   while (aux != 0){ // Enquanto numero base for diferente de zero, ele vai continuar a busca

    if (aux % tamanho == numerobusca){ // Separando o numero de acordo com o seu tamanho e o comparando
        qtdOcorrencias ++;
        aux = aux / tamanho;
   
   }else
        aux /= 10; // Separando o numero com uma posição
 }
   return qtdOcorrencias;
    
}
