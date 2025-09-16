#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int signed a=-4192;
	int unsigned mask = 1<<31;
	for(int i=0;i<32;i++){
		printf("%d",(a&(mask>>i))!=0);
		if (i%4==3) putchar(' ');
	}
	printf("\n\n\n");
	unsigned b=(unsigned) a>>10; /*Forzas el shifteo a un unsigned que es siempre logico y no aritmetico*/
	for(int j =0;j<32;j++){
		printf("%d",( b&(mask>>j))!=0);
		if (j%4==3) putchar(' ');
	}
}
	
