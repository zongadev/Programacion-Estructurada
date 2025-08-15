/**
Se tiene un archivo con los datos de los productos (nombre del producto, 
stock, stock minimo y stock maximo).
Se puede tener un maximo de 100 productos. Definir struct para cargar los 
datos en un arreglo estatico, imprimir una tabla, crear con los datos del 
arreglo un nuevo archivo que contenga el stock minimo y maximo
codificados en un solo valor, imprimir nuevamente la tabla con los datos 
de los productos que se deben reponer tomados del nuevo archivo y 
decodificando el stock minimo y maximo y calculando la cantidad a reponer 
sabiendo que si el stock es menor o igual al stock minimo se debera 
reponer hasta alcanzar el stock maximo.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define F 100
#define C 50

struct s_dato{
    char nomprod[C];
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_dato t_dato;

int cargarDatosDeArch(char [],t_dato []);
void imprimirTabla(t_dato []);
int crearNuevoArch(char [],t_dato []);
unsigned int codificar(int,int);
void decodificar(unsigned int,int []);
int listadoProdAReponer(char []);

int main(){
	int res=0;
	// CODIFICAR AQUI
	
    return res;
}

int cargarDatosDeArch(char nom[],t_dato prod[]){
	int res=0;
	// CODIFICAR AQUI
	
    return res;
}

int crearNuevoArch(char nom[],t_dato prod[]){
    int res=0;
	// CODIFICAR AQUI
	
    return res;
}

unsigned int codificar(int smin,int smax){
    unsigned int codigo=0;
	// CODIFICAR AQUI
	
    return codigo;
}

void decodificar(unsigned int cod,int stminmax[]){
	// CODIFICAR AQUI
	
}

void imprimirTabla(t_dato prod[]){
	// CODIFICAR AQUI
	
}

int listadoProdAReponer(char nom[]){
	int res=0;
	// CODIFICAR AQUI
	
    return res;
}

