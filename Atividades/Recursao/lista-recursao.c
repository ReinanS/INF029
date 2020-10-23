#include <stdio.h>
#include "lista-recursao.h"

int fatorial(int n) {
	if(n <= 1){
		return 1;
	}
	return n*fatorial(n-1);
}

int fibonacci(int n) {
	if(n == 1 || n == 2){
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

// TESTES

int ligado = 1;
void show_log(char *str){
    if (ligado){
        printf("###%s###\n", str);
    }
}

void testeFatorial() {
    show_log("testeFatorial()");
    printf("%d\n", fatorial(5) == 120); 
 
}

void testeFibonacci() {
    show_log("testeFibonacci()");
    printf("%d\n", fibonacci(8) == 21);
    printf("%d\n", fibonacci(4) == 3);
}