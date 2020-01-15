#include <stdio.h>
#include <string.h>

int contarPalavra(char texto[], char busca[], int posicoes[]);

void main(){
    
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    
    for (i = 0; i<30; i++)
        posicoes[i] = -1;
    
    
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    
    int retorno = contarPalavra(strTexto, strBusca, posicoes);
    
    printf("%d\n", retorno);
}

int contarPalavra(char texto[], char busca[], int posicoes[]){
    
    int i, j;
    
    int qtdOcorrencias = -1;
    
    for (i = 0, j = 0; i < strlen(busca); i++)
        
        while(texto[i] == busca[j]){
            j++;
            i++;

        
        if (busca[j] == '\0')
            
        }

    return qtdOcorrencias;
}
