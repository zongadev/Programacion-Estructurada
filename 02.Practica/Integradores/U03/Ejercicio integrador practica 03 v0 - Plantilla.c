/*
Se tiene un archivo con la primera linea de titulos 
(PRODUCTO, STOCK, STOCKMIN, STOCKMAX y PRECIO) y el resto de las lineas con 
los datos de los productos. Definir struct para cargar los titulos y
 los datos en un arreglo dinamico, imprimir una tabla incluyendo titulos y datos. 
Imprimir nuevamente la tabla con los datos de los productos que se deban 
reponer (si el stock es menor o igual al stock minimo se debera reponer 
hasta alcanzar el stock maximo) incluyendo la cantidad a reponer y
el importe a pagar por esa reposicion (incluir titulos: REPONER E IMPORTE) 
y al final del listado lo que se debe pagar por el total de la compra.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 60
struct s_titu
{
    char *prod;
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_titu t_titu;

struct s_dato
{
    char *nomprod;
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_dato t_dato;

struct s_contenido
{
    t_titu titulo;
	// COMPLETAR ESTRUCTURA AQUI ...
	
};
typedef struct s_contenido t_contenido;

int cargarDatosDeArch(char [],t_contenido *);
void imprimirTabla(t_contenido);
int listadoProdAReponer(t_contenido,char *);

int main()
{
    int res=0;
	// CODIFICAR AQUI
	
	
    return res;
}

int cargarDatosDeArch(char *nom,t_contenido *content)
{
    int res=0;
	// CODIFICAR AQUI
	
	
    return res;
}


void imprimirTabla(t_contenido content)
{
	// CODIFICAR AQUI
	
	
	
}

int listadoProdAReponer(t_contenido content,char *nom)
{
    int res=0;
	// CODIFICAR AQUI
	
	
    return res;
}

