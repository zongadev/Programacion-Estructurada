/**
  Ejercicio 1.14
  Ultima actualización: 10/09/2024
  
  En este código sólo se realizó la lectura del archivo 
  y la carga de la matriz de int.
  Falta realizar el resto que solicita la consigna.

*/
#include <stdio.h>
#define F 20
#define C 40
#define TERM_I -999
void cargarMat(int mat[F][C]){
	FILE* arch=fopen("datos.txt","r");
	int num,x;
	int f=0,c=0;              // iniciliza 
	fscanf(arch,"%d",&num);
	while(!feof(arch) && f<F-1 && c<C-1){		
		mat[f][c]=num;        // almacena el valor en la matriz
		x=fgetc(arch);        // lee ',' o '\n' 
		c++;                  // incrementar columna
		if(x=='\n'){
			mat[f][c]=TERM_I; // terminador (fin de la columa)
			c=0;              // inicilizar columna
			f++;              // incrementar fila
		}
		if(!feof(arch)){
			fscanf(arch,"%d",&num);}
	}
	mat[f][0]=TERM_I;         // terminador (fin de la fila)
	fclose(arch);             // cerrar archivo
}
	
void imprimirMat(int mat[F][C]){
	int f=0,c=0;
	for(f=0;mat[f][0]!=TERM_I && f<F-1;f++){
		for(c=0;mat[f][c]!=TERM_I && c<C-1;c++){
			printf("%3d",mat[f][c]);
		}
		printf("\n");
	}
}
	
int main( ) {
	int mat[F][C];
	cargarMat( mat );
	imprimirMat( mat );
	// Escribir el resto del código  para la solución
	
	return 0;
}

