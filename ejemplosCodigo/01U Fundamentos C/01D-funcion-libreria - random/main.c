/**
01D-funcion-libreria - random
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>                       /** Libreria matematica del estandar C*/
										/** Utilizaremos la función pow  que no dará la potencia de un numero*/
#include <time.h>                       /** para utilizar función time*/
#define INF 10
#define SUP 20

//int ingresar(char msj[]);              /** Declaración de la cabecera de la funcion*/
double  promedio(int a ,int b);          /** Declaración de la cabecera de la funcion*/
void imprimir(char msj[],double valor);
int aleatorio(int inf, int sup);
int esM2YM3oM4(int num);

void caso01();
void caso02();

int main() {
    srand(time(NULL));                  /** Seteo de la semilla del generador de valores aleatorios*/

	printf("\n\n");
	
    printf("%d\n",INF + (rand() % (SUP-INF+1)));

    printf("-------------  ----------------\n");
    caso01();

    printf("-------------  ----------------\n");
    caso02();
    printf("\n-------------  ----------------\n");
    return 0;
}

void caso01(){
    printf("CASO01: Se genera dos numeros aleatorios, se obtiene \n\tel promedio y el cuadrado del promedio\n");
    int x,y;
    double prom;
    double pot2;

    x=aleatorio(INF,SUP);
    y=aleatorio(INF,SUP);

    imprimir("X es: ",x);
    imprimir("Y es: ",y);

    prom= promedio(x,y);
    imprimir("El valor promedio es:",prom);

    pot2=pow(prom,2) ;
    imprimir("El promedio elevado al cuadrado es:",pot2);
}
void caso02(){
    printf("CASO02: Funciones Boolenas. Retornan 1 si cumplen la condicion 0 caso contrario\n");
    int x;
    x=aleatorio(INF,SUP);

    printf("%d (es Mutiplo de 2 y multiplo de 3) o bien (es multiplo de 4)\n",x);
    printf("(1):Verdadero, (0)Falso:\n");
    printf(" Resultado -> %d\n",esM2YM3oM4(x));
}
int esM2YM3oM4(int num){
    return ((num%2==0) && (num%3==0)) || (num%4==0);
}

int aleatorio(int inf, int sup){
    return inf + (rand() % (sup-inf+1));
}

/*
int ingresar(char msj[]){
    int aux;
    printf("%s",msj);
    scanf("%d",&aux);
    return aux;
}
*/
double promedio(int a, int b){          /**Codigo de la funcion*/
    double res = (a+b)/2.0;
    return res;
}

void imprimir(char msj[20],double valor){ /**Codigo de la funcion*/
    printf("%s %lf\n",msj,valor);
}

