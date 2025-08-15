/**
01F-ciclos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT 10
#define INF 0
#define SUP 99
#define INF2 1000
#define SUP2 100000
#define CERO 0
#define DOSCINCOCINCO 255
int esPrimo(int num);
int aleatorio(int inf, int sup);

void caso01w();
void caso01f();
void caso02w();
void caso02f();
void caso03w();
void caso04w();
void caso05w();

int main() {
    srand(time(NULL));          /** Seteo de la semilla del generador de valores aleatorios*/
    printf("\nCICLOS\n");

    printf("\n------------- ----------------\n");
    caso01w();

    printf("\n-------------  ---------------\n");
    caso01f();

    printf("\n------------- ----------------\n");
    caso02w();

    printf("\n------------- ----------------\n");
    caso02f();


    printf("\n------------- ----------------\n");
    caso03w();

    printf("\n------------- ----------------\n");
    caso04w();

    printf("\n------------- ----------------\n");
    caso05w();

    printf("\n-------------------------------\n");
    return 0;
}

void caso01w(){
    printf("CASO01W: Con while, se genera cant 'cantidades' de numeros aleatorios\n");

    int x, i , cant=CANT ;

    i=0;                            /** inicilizar la variable de control del ciclo*/
    while(i<cant){                  /** Guarda: mientras i sea menor que cant */
        x=aleatorio(INF,SUP);       /** generar aleatorio */
        printf("%d - ",x);          /** imprimir el numero generado */
        i++;                        /** incrementar la variable de control del ciclo*/
    }
    printf("\n");                   /** se agrega un \\n para que quede prolija la salida.*/
}

void caso01f(){
    printf("CASO01f: Con for, se genera cant 'cantidades' de numeros aleatorios\n");

    int x, i , cant=CANT ;

    for( i=0 ; i<cant ; i++){            /** inicializa;  controla;  incrementa*/
        x=aleatorio(INF,SUP);       /** generar aleatorio */
        printf("%d - ",x);          /** imprimir el numero generado */
    }

    printf("\n");                   /** se agrega un \\n para que quede prolija la salida.*/
}

void caso02w(){

    printf("CASO02W: Con while, se genera cant 'cantidades' \n\tde numeros PARES aleatorios ");
    printf("y los imprime. \n\tY ademas imprime la cantidad de fallidos,\n\tes decir los generados que no fueron pares \n");

    int x, pares , cant=CANT ;
    int fallidos=0;

    pares=0;                        /** inicilizar la variable de control del ciclo*/
    while(pares<cant){              /** Guarda: mientras pares sea menor que cant */
        x=aleatorio(INF,SUP);       /** generar aleatorio */
        if (x%2==0){
            printf("%d - ",x);      /** imprimir el numero generado */
            pares++;                /** incrementar la variable de control del ciclo*/
        }
        else{
            fallidos++;             /** cuento la cantidad de fallidos, es decir los generados que no fueron pares*/
        }
    }
    printf("\nCantidad de fallidos: %d",fallidos);

    printf("\n");                   /** se agrega un \\n para que quede prolija la salida.*/
}

void caso02f(){

    printf("CASO02f: Con for, se genera cant 'cantidades' \n\tde numeros PARES aleatorios ");
    printf("y los imprime. \n\tY ademas imprime la cantidad de fallidos,\n\tes decir los generados que no fueron pares \n");

    int x, pares , cant=CANT ;
    int fallidos=0;


    for(pares=0; pares<cant; ){      /** inicializa;  controla;  <no usado>*/
        x=aleatorio(INF,SUP);       /** generar aleatorio */
        if (x%2==0){
            printf("%d - ",x);      /** imprimir el numero generado */
            pares++;                /** incrementar la variable de control del ciclo*/
        }
        else{
            fallidos++;             /** cuento la cantidad de fallidos, es decir los generados que no fueron pares*/
        }
    }
    printf("\nCantidad de fallidos: %d",fallidos);

    printf("\n");                   /** se agrega un \\n para que quede prolija la salida.*/
}


void caso03w(){

    printf("CASO03W: Con while, se imprimen numeros pertenecientes a un rango.");
    printf("\n\tSolo se imprimen aquellos que cumplan una condicion \n\t para el caso la condicion sera si el numero es primo\n");

    int num , cant=CANT ;
    int fallidos=0;
    printf("Entre %d y %d, los numeros primos son:\n",INF,SUP);
    num = INF;                      /** inicilizar num con el primer numero del rango*/
    while(num <= SUP){              /** Guarda: mientras num sea menor al mayor numero del rango */
        if (esPrimo(num)){          /** si es primo ...*/
            printf("%d - ",num);    /** imprimir el numero generado */
        }
        num++;                      /** incrementar la variable de control del ciclo*/
    }
    printf("\n");                   /** se agrega un \\n para que quede prolija la salida.*/
}

int esPrimo(int num){
    /**funcion booleana retorna 1 si num es primo o 0 si num no lo es */
    /**recurso: https://es.wikipedia.org/wiki/N%C3%BAmero_primo*/
    int es_primo = 1;
    int x = 2;
    while((x < num) && es_primo){
         if (num % x == 0){
            es_primo = 0;
         }
         x++;
    }
    return ((num >1) && es_primo);
}

void caso04w(){

    printf("CASO04w: Con while, Descomposicion de un numero entero en sus digitos\n ");
    printf("\tluego se cuentan sus digitos pares e impares\n ");

    int num=aleatorio(INF2,SUP2);       /** generar aleatorio */
    int digi=0, contpar=0,contimpar=0;
    printf("El numero %d , tiene: \n",num);

    while(num>0){
        digi=num%10;
        //printf("%d - ",digi);
        if (digi %2 ==0){
            contpar++;
        }
        else{
            contimpar++;
        }
        num = num/10;
    }
    printf("%d digitos pares, y %d digitos impares\n",contpar,contimpar);
}

void caso05w(){

    printf("CASO05w: Con while, Convertir un numero entero en binario \n ");
    printf("\ty alamacenar el binario en una variable entera\n ");

    int num = aleatorio(CERO,DOSCINCOCINCO);       /** generar aleatorio */

    int resto=0,aux=0,i=1,bin=0;
    aux=num;
        while(aux>0){
            resto=aux%2;            /** obtener el resto */
            aux=aux/2;              /** obtener cociente */
            bin=bin+(resto*i);      /** sumo el resto del anterior con el del actual, cada uno en su posicion */
            i=i*10;                 /** incremento para obtener proxima posicion */
        }
    printf("(Base 10) %d < - - >(Base 2) %d \n",num,bin);
}

int aleatorio(int inf, int sup){
    /** Genera un numero aleatorio entre inf y sup (ambos extremos incluidos)*/
    return inf + (rand() % (sup-inf+1));
}
