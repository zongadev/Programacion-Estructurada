#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int b;
	char c;
	printf("Ingrese un char: \n");
	c=getchar();
	unsigned int mask=1<<31;       
	int i;
	for (i=0;i<32;i++)
	{
		printf("%d",(c&(mask>>i))!=0);
	}
	
}
