/**
Ejercicio integrador practica 02

Se tiene un archivo con la primera linea de titulos (PRODUCTO, STOCK y PRECIO)
 y el resto de las lineas con los datos de los productos. 
Se puede tener un maximo de 100 productos. 
Definir struct para cargar los titulos y los datos en un arreglo estatico, 
imprimir una tabla incluyendo titulos  y datos, ordenar los productos 
alfabeticamente de menor a mayor, imprimir nuevamente la tabla con
los datos de los productos cuyo stock este comprendido dentro 
de un rango determinado.
*/
#include<stdio.h>
#include<string.h>
#define F 100
#define C 50

struct s_titu{
    char prod[C];
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_titu t_titu;

struct s_dato{
    char nomprod[C];
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_dato t_dato;

struct s_contenido{
    t_titu titulo;
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_contenido t_contenido;

int cargarDatosDeArch(char [],t_contenido []);
void imprimirTabla(t_contenido []);
void ordenarPorProd(t_contenido []);
void imprimirTablaConFiltro(t_contenido [],int,int);

int main(){
    int res=0;
	// CODIFICAR AQUI
	
    
    return res;
}

int cargarDatosDeArch(char nom[],t_contenido content[1]){
    int res=0;
	// CODIFICAR AQUI
	
    return res;
}

void imprimirTabla(t_contenido content[1]){
	// CODIFICAR AQUI
	
	
}

void ordenarPorProd(t_contenido content[1]){
	// CODIFICAR AQUI
	
	
}

void imprimirTablaConFiltro(t_contenido content[1],int stinf,int stsup){
	// CODIFICAR AQUI
	
}


