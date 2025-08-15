#include <stdio.h>
#define TERM_I 0
#define F 3                      // Tamaño del arreglo
#define C 3                      // Tamaño del arreglo
int ingresarIM(int f, int c){
	int x;
	printf("[%d][%d]: ",f,c);
	scanf("%d", & x); 
	return x;
}	
void cargarMatI(int mat[F][C]){
	int f=0, c=0, aux ;		// inicializar indice f y c en 0
	f=0;
	aux=ingresarIM(f,c);
	while ( f<F-1 && aux!=TERM_I ){
		while(c<C-1 && aux!=TERM_I ){
			mat[f][c]=aux;
			c++;
			if (c<C-1){
				aux=ingresarIM(f,c);
			}
		}
		printf("- - - \n");
		mat[f][c]=TERM_I;
		f++;
		c=0;
		if (f<F-1){
			aux=ingresarIM(f,c);
		}
	}
	mat[f][0]=TERM_I;
}
void imprimirMatI(int mat[F][C]){
	int f = 0, c = 0;		 // inicializar indice f y c en 0
	for (f=0; f<F && mat[f][0]!=TERM_I; f++){
		for(c=0;c<C && mat[f][c]!=TERM_I;c++){
			printf("%4d",mat[f][c]);
		}
		printf("\n");
	}		
}
int main( ) {
	int matI[F][C]={0};    // definicion de la variable  
	cargarMatI(matI);
	printf("\n");
	imprimirMatI(matI);
	return 0;
}

