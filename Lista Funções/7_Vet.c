#include <stdio.h>


void lerPalavras(char str[3][50]);

void main(){
    
    int i;
    
    char palavra[3][50];
    
    lerPalavras(palavra);
    
    for (i = 0; i < 3; i++)
        printf("%d° palavra:  %s\n", i + 1, palavra[i]);
}

void lerPalavras(char str[3][50]){
    
    int i;
    
    for (i = 0; i < 3; i++)
        fgets(str[i], 50, stdin);

}
