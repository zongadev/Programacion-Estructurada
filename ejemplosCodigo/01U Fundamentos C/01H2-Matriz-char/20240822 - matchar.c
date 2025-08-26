#include <stdio.h>

#define F 10                      // Tama�o del arreglo
#define C 10                     // Tama�o del arreglo

void cargarMatC(char mat[F][C]){
	int f=0, c=0;		         // inicializar indice f y c en 0
	char aux;
	printf("%s\n","INGRESE TEXTO:\n");
	printf("[%d]: ",f);
	aux=getchar();
	while ( f<F-1 && aux!='\n' ){		
		while(c<C-1&& aux!='\n' ){
			mat[f][c]=aux;
			c++;
			aux=getchar();
		}
		mat[f][c]='\0';
		f++;
		c=0;
				
		if (f<F-1){
			printf("[%d]: ",f);
			aux=getchar();
		}		
	}
	mat[f][0]='\0';
}
void imprimirMatC(char mat[F][C]){
	int f = 0, c = 0;		 // inicializar indice f y c en 0	
	for (f=0; f<F && mat[f][0]!='\0'; f++){		
		printf("%s\n",mat[f]);
	}		
}
int main( ) {
	char matC[F][C]={0};    // definicion de la variable  
	cargarMatC(matC);
	printf("\n");
	imprimirMatC(matC);
	return 0;
}

