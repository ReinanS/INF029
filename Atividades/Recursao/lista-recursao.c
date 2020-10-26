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

int inverteNum(int n, int total) {
	if(n <= 0){
		return total;
	}
	return inverteNum(n / 10, (total * 10) + n % 10);
}

int somaVet(int vet[], int tam) {
	if(tam <= 0) {
		return 0;
	}
	return vet[tam-1] + somaVet(vet, tam-1);
}

int soma(int n) {
	if(n <= 0) {
		return 0;
	}
	return n + soma(n-1);
}

int potencia(int k, int n) {
	if(n < 1) {
		return 1;
	}
	return k * potencia(k, n-1);
}

// Não está funcionando
void inverter(int vet[], int i) {
	int aux = vet[(TAM-1)-i];
	vet[(TAM-1)-i] = vet[i];
	vet[i] = aux;
	i++;

	if (i < (TAM/2)){
	inverter(vet, i);
	}
}

int mdc(int x, int y) {
	if(y == 0) {
		return x;
	}

	mdc(y, x % y);
}

int contaDigito(int n, int k, int i) {
	if(n % 10 == k) {
		i++;
	}
	if(n % 10 == n) {
		return i;
	}
	contaDigito(n / 10, k, i);
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

void testeInverteNum() {
    show_log("testeinverteNum()");
    printf("%d\n", inverteNum(321,0) == 123);
    printf("%d\n", inverteNum(45 ,0) == 54);
    printf("%d\n", inverteNum(1245 ,0) == 5421);
}

void testeSomaVet() {
    show_log("testeSomaVet()");
    int vet1[] = {1, 2, 3, 4, 5};
    printf("%d\n", somaVet(vet1, 5) == 15);
	int vet2[] = {5,1,2};
	printf("%d\n", somaVet(vet2, 3) == 8); 
}

void testeSoma() {
    show_log("testeSoma()");
    printf("%d\n", soma(5) == 15); 
}

void testePotencia() {
    show_log("testePotencia()");
    printf("%d\n", potencia(2,4) == 16);
    printf("%d\n", potencia(5,3) == 125); 
   	printf("%d\n", potencia(9,1) == 9); 
    printf("%d\n", potencia(4,0) == 1); 
}

void testeInverter() {
    show_log("testeInverter()");
    
    int vet[TAM];
    int i;

    for(i = 0; i < TAM; i++) {
    	vet[i] = i;
    }

    inverter(vet, 0);
    printf("%d\n", vet[0] == 99);
    printf("%d\n", vet[99] == 0);
}

void testeMDC() {
    show_log("testeMDC()");
    printf("%d\n", mdc(2,4) == 2);
    printf("%d\n", mdc(3,9) == 3);  
}

void testeContaDigito() {
    show_log("testeContaDigito()");
    printf("%d\n", contaDigito(762021192, 2, 0) == 3);  
}