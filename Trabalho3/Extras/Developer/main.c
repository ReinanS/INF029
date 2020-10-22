
int converteLinha(char linha[]);
int encontraValor(char str[], char linha[], int posicao);
int converteValorAux(char linha[], int aux[], int posicao, int qtdElementos);

int lerArquivo() {
    FILE *input = fopen("estrutura.txt", "r");
    char linha[TAM_LINHA];
    int retorno = SUCESSO;

    if(input == NULL){
        return ERRO_ABRIR_ARQUIVO;
    }

    fgets(linha, TAM_LINHA, input);
    while(!feof(input)) {    
        // converto as informações
        retorno = converteLinha(linha);
        // pego a linha
        fgets(linha, TAM_LINHA, input);
    }

    fclose(input);
    return retorno;
}

int converteLinha(char linha[]){
    int i;
    int j = 0;

    char indice[TAM_LINHA];
    char tamanho[TAM_LINHA];
    char qtd[TAM_LINHA];
    char elementosAux[TAM_LINHA];
    
    int elementosAuxNum[TAM_LINHA];

    // Encontra o indice
    j = encontraValor(indice, linha, j);
    // Encontra o tamanho
    j = encontraValor(tamanho, linha, j);
    //  Encontra o qtd
    j = encontraValor(qtd, linha, j);
    
    // Conversão de string para inteiro
    int indiceNum = atoi(indice);
    int tamanhoNum = atoi(tamanho);
    int qtdNum = atoi(qtd);

    int aux[tamanhoNum];

    // // Encontra os elementos da Estrutura Auxiliar
    if(tamanhoNum > 0){
        converteValorAux(linha, aux, j, qtdNum);
    } else {
        return ESTRUTURA_VAZIA;
    }
    
    

    // Impressoes
    printf("\nIndice = %d \n", indiceNum);
    printf("Tamanho = %d \n", tamanhoNum);
    printf("Qtd = %d \n", qtdNum);

    // Impressão dos elementos na estrutura
    printf("Elementos Estrutura: \n");
    for(i = 0; i < qtdNum; i++) {
        printf("%d->",aux[i]);
    }
    printf("\n");

    // Chamo as funcoes para Inserir na Lista
    criarEstruturaAuxiliar(tamanhoNum, indiceNum);

    for(i = 0; i < qtdNum; i++) {
        inserirNumeroEmEstrutura(aux[i], indiceNum);
    }


    return SUCESSO;
}


int encontraValor(char str[], char linha[], int posicao) {
  int i;

    for(i = 0; linha[posicao] != ';' && linha[posicao] != '\n'; i++, posicao++) { 
        str[i] = linha[posicao];
    }

    str[i++] = '\0';
    posicao++;

    return posicao;
}


int converteValorAux(char linha[], int aux[], int posicao, int qtdElementos){
 
    char str[TAM_LINHA];
    int cont=0;
    while(cont<qtdElementos){
        posicao = encontraValor(str, linha,posicao);
        aux[cont]=atoi(str);
        cont++;
    }
    return posicao;
}
