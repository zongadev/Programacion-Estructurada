#include <stdio.h>

int TAM=100;
int TERM_I=0;

void cargarArrPNR(int arr[TAM]);
int estaEnArr(int n, int arr[TAM], int tamano);
int esPos(int n);

int esPos(int n){
	int res=0;
	if(n>0){
		res=1;
	}
	return res;
}
	
int estaEnArr(int n, int arr[TAM], int tamano){
	int cont=0;
	int res=0;
	for(int i =0;i<tamano-1;i++){
		if(arr[i]==n){
			cont++;
		}
	}
	if (cont==1){
		res=1;
	}
	return res;
}

void imprimirArr(int arr[TAM]){
		for(int i =0; i<TAM && arr[i]!=TERM_I;i++){
			printf("[%d]: %d \n",i,arr[i]);
		}
}
	
void cargarArrPNR(int arr[TAM]){
	int i=0;
	int num;
	printf("Ingrese numeros positivos: \n");
	printf("[%d]:",i);
	scanf("%d",&num);
	while (num!=TERM_I && i<TAM){
		if(esPos(num)==1 && estaEnArr(num,arr,i)==0){
			arr[i]=num;
			i++;
		}
		printf("[%d]:",i);
		scanf("%d",&num);
	}
	arr[i++]=0;
}	
int main(){
	int arrI[TAM];
	cargarArrPNR(arrI);
	imprimirArr(arrI);
}
