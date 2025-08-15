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
int main(){
	arrR("holas que talss");
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
