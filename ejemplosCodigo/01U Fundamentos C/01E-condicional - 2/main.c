/**
01E-condicional - 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio(int inf, int sup);

void caso03();
void caso04();

int main() {
    srand(time(NULL));          /** Seteo de la semilla del generador de valores aleatorios*/
    printf("\nTraduce un numero a letras, mismo \nproblema resuelto de dos formas distintas\n");

    printf("\n------------- ----------------\n");
    caso03();

    printf("\n-------------  ---------------\n");
    caso04();

    printf("\n-------------------------------\n");
    return 0;
}

void caso03(){
    /**Condicional if , else if*/
    int x;
	int a=0, b=13;
    x=aleatorio(a,b);
    printf("CASO03: CON Condicional if , else if \n");
	printf("Traducción de numero a letra\n");

    if (x==0){
        printf("(%d): CERO",x);
    }
    else if (x==1){
        printf("(%d): UNO",x);
    }
    else if (x==2){
        printf("(%d): DOS",x);
    }
    else if (x==3){
        printf("(%d): TRES",x);
    }
    else if (x==4){
        printf("(%d): CUATRO",x);
    }
    else if (x==5){
        printf("(%d): CINCO",x);
    }
    else if (x==6){
        printf("(%d): SEIS",x);
    }
    else if (x==7){
        printf("(%d): SIETE",x);
    }
    else if (x==8){
        printf("(%d): OCHO",x);
    }
    else if (x==9){
        printf("(%d): NUEVE",x);
    }
    else {
        printf("(%d): NO es un numero registrado",x);
    }
}

void caso04(){
    /** switch .. case */
    int x;
    x=aleatorio(0,13);
    printf("CASO04: CON switch ... case\n");

    switch (x){
        case 0:{
            printf("(%d): CERO",x);
            break;
        }
        case 1:{
            printf("(%d): UNO",x);
            break;
        }
        case 2:{
            printf("(%d): DOS",x);
            break;
        }
        case 3:{
            printf("(%d): TRES",x);
            break;
        }
        case 4:{
            printf("(%d): CUATRO",x);
            break;
        }
        case 5:{
            printf("(%d): CINCO",x);
            break;
        }
        case 6:{
            printf("(%d): SEIS",x);
            break;
        }
        case 7:{
            printf("(%d): SIETE",x);
            break;
        }
        case 8:{
            printf("(%d): OCHO",x);
            break;
        }
        case 9:{
            printf("(%d): NUEVE",x);
            break;
        }
        default:{
            printf("(%d): NO es un numero registrado",x);
        }
    }
}

int aleatorio(int inf, int sup){
    /** Genera un numero aleatorio entre inf y sup (ambos extremosincluidos)*/
    return inf + (rand() % (sup-inf+1));
}
