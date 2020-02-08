#include <stdio.h>
#include <string.h>

/*
    Cadastrar 5 Pessoas
    op1 = 4 vetores
    op2 = 1 vetor de Struct
 */
void apagar_tela();
int ler_idade(int *idade);
void imprimir_idade(int *idade);
int ler_sexo(char *sexo);
void imprimir_sexo(char *sexo);
int ler_salario(float *salario);
void imprimir_salario(float *salario);
int ler_nome(char *nome);
void imprimir_nome(char *nome);


void main(){
    
    int opcao, idade;
    char sexo, nome [50];
    float salario;
    
    int *p_idade;
    char *p_sexo, *p_nome;
    float *p_salario;
    
    p_idade = &idade;
    p_sexo = &sexo;
    p_salario = &salario;
    p_nome = &nome[50];
    
    do {
        
        printf("\n\t\tMenu: \n\n");
        printf("0 - Sair \n");
        printf("1 - Digitar Idade \n");
        printf("2 - Imprimir Idade \n");
        printf("3 - Digitar Sexo \n");
        printf("4 - Imprimir Sexo \n");
        printf("5 - Digitar Salario \n");
        printf("6 - Imprimir Salario \n");
        printf("7 - Digitar Nome \n");
        printf("8 - Imprimir Nome \n\n");
        
        printf("Digite a Opcao: ");
        scanf("%d", &opcao);
        getchar();
        fflush(stdin);
        
        switch(opcao){
            
            case 0:{ 
                printf("\nSaindo\n\n"); break;
            }
            case 1:{
                *p_idade = -1;
                ler_idade(p_idade);
                if (*p_idade == -1)
                    printf("Idade Invalida \n");
                break;
                
            }
            case 2:{
                imprimir_idade(p_idade); break;
            }
            
            case 3:{
               ler_sexo(p_sexo); break;
            }
            
            case 4:{
                imprimir_sexo(p_sexo); break;
            }
            
            case 5:{
               ler_salario(p_salario);break;
            }
            
            case 6:{
                imprimir_salario(p_salario); break;
            }
            
            case 7:{
                ler_nome(p_nome); break;
            }
            
            case 8:{
                imprimir_nome(p_nome); break;
            }
            
        }
        
    }while(opcao != 0);
}

void apagar_tela(){
    printf("\e[H\e[2J");
}

int ler_idade(int *idade){
    
    int id;
    
    printf("Digite a sua Idade: ");
    
    scanf("%d", &id);
    
    if (id < 1)
        return 0;
        
    *idade = id;
    
    return 1;
        
}

void imprimir_idade(int *idade){
    
    printf("\nSua idade e: %d \n", *idade);
}

int ler_sexo(char *sexo){
    
    char sx[2];
    
    printf("Digite o sexo: ");
    scanf("%s", sx);
      
    if (strlen(sx) > 1)
        return 0;
    
    if (sx[0] == 'M' || sx[0] == 'F' || sx[0] == 'm' || sx[0] == 'f')
        *sexo = sx[0];
    
    return 1;
}
void imprimir_sexo(char *sexo){
       
    printf("O sexo digitado e: %c", *sexo);
}

int ler_salario(float *salario){
    
    printf("Digite o Salário: ");
    scanf("%f", salario);
    
    return 1;
}

void imprimir_salario(float *salario){
    
    printf("Salario Digitado e : %.2f", *salario);
}

int ler_nome(char *nome){
    
    printf("Digite o Nome :");
    fgets(nome, 50, stdin);
    
    size_t ln = strlen(nome) - 1; //size_t = unsigned integer type
    if (nome[ln] == '\n')
        nome[ln] = '\0';
    
    imprimir_nome(nome);
    
    return 1;
}

void imprimir_nome(char *nome){
    
    printf("\n%s\n", nome);
}



