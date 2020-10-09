#include <stdio.h>

typedef struct l{
    
    char a, b, c;
}letras;

letras lerLetras();

void main(){
    
    letras let = lerLetras();
    
    printf("\n%c %c %c\n", let.a, let.b, let.c);
    
}

letras lerLetras(){
    
    letras let;
    
    scanf("%c %c %c", &let.a, &let.b, &let.c);
    
    return let;
}
