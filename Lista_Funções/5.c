#include <stdio.h>

typedef struct num{
    
    int a, b, c, d;
}num;

num lerNum();

void main(){
    
    int i;
    
    num valor = lerNum();
    
    printf("\n%d %d %d %d\n", valor.a, valor.b, valor.c, valor.d);
}

num lerNum(){
    
   num v;
   
   //scanf("%d, %d, %d, %d", &v.a, &v.b, &v.c, &v.d);
   
   scanf("%d", &v.a);
   scanf("%d", &v.b);
   scanf("%d", &v.c);
   scanf("%d", &v.d);
   
   return v;
}
