#include <stdio.h>

#define n 5

void preenche_vet(int vet[], int tam);
void imprime_vet(int vet[], int tam);
int soma_vet(int vet[], int tam);

int main(){

  int vet[n];

  preenche_vet(vet, n);
  imprime_vet(vet, n);

  int recebe = soma_vet(vet, n );

  printf("\nA soma total: %d \n", recebe);

  return 0;
}

void preenche_vet(int vet[], int tam){

  int i;

  for (i = 0; i < tam; i++){
    printf("Informe o Valor:");
    scanf("%d", &vet[i]);
  }
}

void imprime_vet(int vet[], int tam){

  int i;

  printf("\n");

  for (i = 0; i < tam; i++)
    printf("Valores: %d \n", vet[i]);
}

int soma_vet(int vet[], int tam){

  if (tam == 0)
    return vet[tam];
  else{

    printf("\nvet = %d \n",vet[tam]);

    return vet[tam - 1] + soma_vet(vet, tam - 1);
  }
}

