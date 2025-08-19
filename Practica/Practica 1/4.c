#include <stdio.h>
int TAM =100;
int TERM_I=0;


int cargarArr(int arr[TAM]);
void imprimirArr(int arr[TAM]);
void invertirArr(int arr[TAM], int n);

int cargarArr(int arr[TAM]){
	int n;
	int i =0;
	
	printf("Ingrese un numero entero: \n");
	printf("\t[%d]: ",i);
	scanf("%d", &n);
	while (n!=TERM_I && i!=TAM-1){
		arr[i]=n;
		i++;
		printf("\t[%d]: ",i);
		scanf("%d", &n);
	}
	arr[i++]=TERM_I;
	return i-1;
}

void imprimirArr(int arr[TAM]){
	for(int i =0; i<TAM && arr[i]!=TERM_I;i++){
		printf("[%d]: %d \n",i,arr[i]);
	}
}
	
void invertirArr(int arr[TAM],int n){
	int i = 0;
	int j = n-1;
	int temp;
	while (j>i){
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	};
}
int main() {

	int arr[TAM];
	int l =cargarArr(arr);
	imprimirArr(arr);
	invertirArr(arr, l);
	imprimirArr(arr);
	return 0;
}

