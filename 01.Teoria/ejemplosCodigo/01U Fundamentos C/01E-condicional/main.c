/**
01E-condicional
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int ingresar(char msj[]);
void imprimir(char msj[],double valor);
int aleatorio(int inf, int sup);

int maxi(int a, int b);
int mini(int a, int b);

void caso01();
void caso02();

void evaluar(double num);
void tipo(double num);
void tipoNum(double num);
void evaluarNum(double num);

int main() {
    srand(time(NULL));          /** Seteo de la semilla del generador de valores aleatorios*/

    printf("-------------Condicional Simple----------------\n");
    caso01();                   /**Se generan dos números y se determina el maximo y el mínimo*/

    printf("-------------Condicional Anidada---------------\n");
    caso02();                   /**Se evalua si un numero es Neutro, Positivo , Negativos, Enetero, Natural, Real */

    printf("----------------------------------------------\n");
    return 0;
}

void caso01(){
    /**Condicional simple, se usa en funciones mini y maxi*/
    int x,y;
    x=aleatorio(-200,100);
    y=aleatorio(10,200);

    printf("CASO01: Se generan dos numeros aleatorios  y\n\tse determina el maximo y el minimo\n");

    imprimir("X es: ",x);
    imprimir("Y es: ",y);

    imprimir("El minimo es",mini(x,y));
    imprimir("El maximo es",maxi(x,y));

}

void caso02(){
    /**Condicional anidada, se usa en funciones evaluarNum y tipoNum*/
    int x,y;
    double val;

    printf("CASO02: Se generan dos numeros aleatorios X e Y, \n\tluego se evalua si la division x/y es\n\tNeutro|Negativo|Positivo - \n\tEntero y Natural|Entero|Real\n");
    printf("\tEJ: 0 es Neutro - / -1.3 es Negativo - Real  / ..etc\n");

    x=aleatorio(-40,40);
    y=aleatorio(1,40);
    imprimir("X es: ",x);
    imprimir("Y es: ",y);

    val = x/(double)y;
    imprimir("VAL = x/(double)y es: ",val);
    evaluarNum (val);
}

int mini(int a, int b){
    /**Retorna el valor minimo entre a y b*/
    int res = a;
    if (a>b){
        res = b;
    }
    else{
        res = a;
    }

    return res;
}
int maxi(int a, int b){
    /**Retorna el valor maximo entre a y b*/
    int res;
    if (a < b){
        res = b;
    }
    else{
        res = a;
    }
    return res;
}

int aleatorio(int inf, int sup){
    /** Genera un numero aleatorio entre inf y sup (ambos extremosincluidos)*/
    return inf + (rand() % (sup-inf+1));
}
void imprimir(char msj[],double valor){
    /**Codigo de la funcion*/
    printf("%s %lf\n",msj,valor);
}

void evaluarNum(double num){
/**Determina e imprime si num es Neutro | Negativo | Positivo */
/**Y si es Entero y Natural | Entero | Real  */
    printf("\nVAL = %lf, es: ",num);
    if (num==0){
        printf("Neutro - ");
    }
    else{
        if (num<0){
            printf("Negativo - ");
        }
        else{
            printf("Positivo - ");
        }
        tipoNum(num);
    }
    printf("\n");
}

void tipoNum(double num){
    /**Determina e imprime si num es Entero y Natural | Entero | Real  */
    int ent;
    double dec;
    ent = (int)num;          /** Extrae parte entera de num*/
    dec = num - ent;         /** Extrae parte decimal de num*/

    if (dec == 0){
        if (ent >=0){
            printf("Entero y Natural - ");
        }
        else {
            printf("Entero - ");
        }
    }
    else{
        printf("Real - ");
    }
}

/*
int ingresar(char msj[]){
    int aux;
    printf("%s",msj);
    scanf("%d",&aux);
    return aux;
}
*/


