#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	unsigned int d;
	printf("Ingrese un int mayor que 0: \n");
	scanf("%u",&d);
	unsigned int mask=1<<31;       
	int i,j=0;
	for(i=0;i<32;i++){
		printf("%d",(d&mask>>i)!=0);
		if (i%4==3) putchar(' ');
		if((d&mask>>i)!=0){
			j++;
		}
	}
	printf("\n Tiene: %d",j);
}
	
