#include <stdio.h>
// |--|--|--|--|--|--|
// 0  1  2  3  4  5
// sumatR(4) -> 10 (retorna)

// productoR(3,4) -> 2 (no puedo usar *)



/*
// _h_  _o_  _l_
//  0    1    2
void arrR(char* arr){
	if((*arr)!='\0'){
		printf("%c",*(arr));
		arrR(arr+1);
	}

}
*/

int sumatoria(int n){
	if(n==0){
		return 0;
	}
	return n+sumatoria(n-1);
}
	
/*int divR(int n, int j){*/
/*	if(n<j){*/
/*		return n;*/
/*	}*/
/*	return divR(n-j,j);*/
/*}*/
	
	int divR(int n, int j){
		if(n>=j){
			return divR(n-j,j);
		}
		return n;
	}
	
int div(int n, int j){
	if(n>=j){
		return 1+div(n-j,j);
	}else{
		return 0;
	}
}
int main(){
	printf("%d",sumatoria(5));
	printf("\n %d",divR(16,5));
	printf("\n %d",div(15,5));
	return 0;
}

/*
void funR(int lim){ //imprimir una cantidad 'lim' de veces 
	if(lim!=0){
		printf("[%d]IDA (entrada) Recursiva\n",lim);
		funR(lim-1);
		printf("[%d]VUELTA (salida) Recursiva\n",lim);
	}else{
		printf("[%d]FIN Recursiva\n",lim);
	}
	
	
}

int main(int argc, char *argv[]) {
	funR(3);
	return 0;
}
*/
