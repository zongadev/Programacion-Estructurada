#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// arrCE: arreglo de Char de memoria Estatica
// arrCD: arreglo de Char de memoria Dinamica

char* dimArregloC(int cant){
	return malloc(cant);
}
					//     i7
void dimArregloC2( char** arrCD, int cant){
	*arrCD = malloc(sizeof(char)*cant); //cc 11
  //*(i7) <- cc 11
}

int main() {
	char arrCE[25]={0};
	char* arrCD=NULL; 
	//arrCD = dimArregloC(25);
	dimArregloC2( &arrCD, 25);
	
	strcpy(arrCE,"Hola como va,ESTATICA");	
	printf("En mem <%p> estatica: %s\n",arrCE,arrCE);
	printf("\n");
	strcpy(arrCD,"Hola como va,DINAMICA");	
	printf("En mem <%p> dinamica: %s\n",arrCD,arrCD);
		
	return 0;
}

