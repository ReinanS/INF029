#include <stdio.h>


void main(){

	// Declarando Variáveis
	int a;
	float b;
	double d;
	char c, str[10];
	

	// Lendo
	scanf("%d", &a);
	scanf("%f", &b);
	scanf("%lf", &d);
	scanf(" %c", &c); // Acrescentei um espcaço antes
	getchar(); // Para ser possível ler a string
	fgets( str, 10, stdin);

	// Imprimindo
	printf("\nInteiro: %d \n", a);
	printf("Float: %f \n", b);
	printf("Double: %f \n", d);
	printf("Char: %c \n", c);
	printf("Strintg: %s \n", str);

	// Declarando Ponteiros e atribuindo endereços
	int *pA = &a;
	float *pB = &b;
	double *pD = &d;
	char *pC = &c;
	char *pStr = str; // O vetor é um ponteiro

	scanf("%d", pA);
	scanf("%f", pB);
	scanf("%lf", pD);
	scanf(" %c", pC);
	getchar();
	fgets(pStr, 10, stdin);

	printf("\nInteiro: %d \n", *pA);
	printf("Float: %f \n", *pB);
	printf("Double: %f \n", *pD);
	printf("Char: %c \n", *pC);
	printf("Strintg: %s \n", pStr);
}