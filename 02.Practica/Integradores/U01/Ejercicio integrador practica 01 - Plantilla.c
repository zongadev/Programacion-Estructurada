/**
Ejercicio integrador practica 01

Se tiene un archivo de titulos (PRODUCTO, STOCK y PRECIO) 
y un archivo con los datos de los productos. 
Se puede tener un maximo de 100 productos. 
Cargar los titulos y los datos en arreglos estaticos, 
imprimir una tabla incluyendo titulos y datos, 
ordenar los productos por stock de mayor a menor, 
imprimir nuevamente la tabla con los datos ordenados.
*/
#include<stdio.h>
#include<string.h>
#define F 100
#define C 50
int cargarDatosDeArch(char [],char [F][C],int [],float []);
int cargarTitulosDeArch(char [],char[F][C]);
void ordenarPorStock(char [F][C],int[],float[]);
void imprimirTabla(char[F][C],char[F][C],int[],float[]);
int main(){
	int retorno=0;
    // CODIFICAR AQUI
	
	return retorno;
}


int cargarDatosDeArch(char nom[],char prod[F][C],int st[],float p[]){
    int res=0;
	// CODIFICAR AQUI
	
    return res;
}

int cargarTitulosDeArch(char nom[],char tit[F][C]){
    int res=0;
	// CODIFICAR AQUI
	
    return res;
}
void ordenarPorStock(char prod[F][C],int st[],float p[]){
	// CODIFICAR AQUI
	
}
void imprimirTabla(char tit[F][C],char prod[F][C],int st[],float p[]){
	// CODIFICAR AQUI
	
}
