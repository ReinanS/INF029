#include <stdio.h>

typedef struct p {
    
    char palavra[3][50];
}p;

p lerPalavras();

void main(){
    
    int i;
    
    p str = lerPalavras();
    
    for (i = 0; i < 3; i++)
        printf("%d° palavra:  %s\n", i + 1, str.palavra[i]);
}

p lerPalavras(){
    
    int i;
    
    p str;
    
    for (i = 0; i < 3; i++)
        fgets(str.palavra[i], 50, stdin);
    
    return str;
}
