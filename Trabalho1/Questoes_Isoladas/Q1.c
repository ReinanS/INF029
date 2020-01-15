#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valida_data(char data[]);
int valida_data_numeros(int dia, int mes, int ano);
int procura_char(char c);

void main(){
    
    char data[15], aniversario[15];
    
    strcpy(data, "30/04/2001");
    
    strcpy(aniversario, "01/06/2015");
    
    int retorno = valida_data(data);
    
    if (retorno == 0)
        printf("Invalido\n");
    else
        printf("Valido\n");
    
}


int valida_data(char data[]){
    
    
    int iDia;
    int iMes;
    int iAno;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
   
    // DIA 
    int i;
    
    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];
        
        if (i > 1) return 0; //NO MAXIMO 2 NUMEROS ANTES DE '/'
        
        if (procura_char(sDia[i]) == 0) return 0; // 
        
    }
    
    sDia[i] = '\0';
    i++;
    
    if (strlen(sDia) == 0) return 0; // VERIFICA SE É IGUAL A 0
    
    iDia = atoi(sDia); //CONVERTE STRING EM INTEIRO
    
    
    //MES 
    
    int j;
    int cont_Mes = 0;
    
    for (j = i; data[j] != '/'; j++, cont_Mes++){
        
        sMes[cont_Mes] = data[j];
        
        if (cont_Mes > 1) return 0; 
        
        if (procura_char(sMes[cont_Mes]) == 0) return 0; // 
        
    }
    
    sMes[j] = '\0';
    j++;
    
    
    if (strlen(sMes) == 0) return 0;
    
    iMes = atoi(sMes);
    
    // ANO
   int cont_Ano = 0;
   
   for (i = j; i < strlen(data); i++, cont_Ano++){
       
       sAno[cont_Ano] = data[i];
       
       if (procura_char(data[i]) == 0) return 0;
   }
   
    if (cont_Ano != 2 && cont_Ano != 4) return 0; //SÓ ACEITA SE O ANO SE TIVER 2 OU 4 DIGITOS
    
    sAno[cont_Ano] = '\0';
    
    iAno = atoi(sAno);
   
        
    //validar
    int retorno = valida_data_numeros(iDia, iMes, iAno);
    
    return retorno;
    
    
    
}

int valida_data_numeros(int dia, int mes, int ano){
    
		 
    if (dia < 1 || dia > 31 && mes < 1 || mes > 12 && ano < 1900 || ano > 2019)
        return 0;
    
    if ((dia > 30) && mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 0;
    
    //FEVEREIRO
    if ((dia > 29) && mes == 2 && ano % 4 == 0) // ANO BISSEXTO
        return 0;
    if ((dia > 28) && mes == 2 && ano % 4 != 0)
        return 0;
        
    	
    return 1;
   
}

int procura_char(char c){
    if (c < 48 || c > 57)
        return 0;
    else
        return 1;
}
