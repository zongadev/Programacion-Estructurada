/**
01D-funcion-libreria
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>                       /** Libreria matematica del estandar C*/
                                        /** Utilizaremos la función pow  que no dará la potencia de un numero*/


int ingresar(char msj[]);               /** Declaración de la cabecera de la funcion*/
double  promedio(int a ,int b);         /** Declaración de la cabecera de la funcion*/
void imprimir(char msj[],double valor);

int main() {

    int x,y;
    double prom;
    double pot2;

    x=ingresar("Ingrese valor x: ");
    y=ingresar("Ingrese valor y: ");
	
    prom= promedio(x,y);
	
    imprimir("El valor promedio es:",prom);
	
    pot2 = pow(prom,2) ;
    imprimir("El promedio elevado al cuadrado es:",pot2);

    return 0;
}

// char msj[]  -> es una cadena de caracteres ose un string, tambien denominado arreglo de char

int ingresar(char msj[]){               /**Codigo de la funcion*/
    int aux;
    printf("%s",msj);
    scanf("%d",&aux);
    return aux;
}

double promedio(int a, int b){          /**Codigo de la funcion*/
    double res = (a+b)/2;
    return res;
}

void imprimir(char msj[],double valor){ /**Codigo de la funcion*/
    printf("%s %lf\n",msj,valor);
	
}
