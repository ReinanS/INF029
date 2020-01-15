#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarLetra(char str[], char letra, int caseSensitive);

void main(){
    
    char palavra[250];
    char letra;
    int caseSensitive;
    
    strcpy(palavra, "Renato Lima Novais");
    letra = 'L';
    caseSensitive = 0;
    
    int retorno = contarLetra(palavra, letra, caseSensitive);
    
    printf("\n%d\n", retorno);
    
}

int contarLetra(char str[], char letra, int caseSensitive){
    
    int cont = 0;
    int i;
    
    if (caseSensitive == 1){
        for (i = 0; i < strlen(str); i++)
            if (letra == str[i])
                cont ++;
    }else 
        for (i = 0; i < strlen(str); i++)
            if (letra == str[i] || tolower(letra) == str[i] || toupper(letra) == str[i]) 
                cont ++;
    
    return cont;
}


