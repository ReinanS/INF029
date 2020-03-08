#include <stdio.h>

#define n 10

void main(){

	int pilha[10];
	int topo = 0;

}

int push(int v){ // INSERE ELEMENTO

	if(topo < n){
		pilha[topo] = v;
		topo ++;
		return 1;
	
	}else{
		printf("Stack Over Flow \n"); // LISTA CHEIA
		return -1;
	}
}

int pop(){ // RETIRA ELEMENTO

	if (topo > 0){
		topo --;
		return pilha[topo];
	
	}else{
		printf("Stack Under Flow \n"); // LISTA VAZIA
		return -1;
	}
}

