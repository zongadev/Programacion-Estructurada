#include <string.h>
#include <stdio.h>

void f1(int* p1, int* p2){
	int aux;
	aux= *p2;
	*p2= *p1;
	*p1= aux;
}

int main(){
	int x=12,y=3;
	printf("X: %d Y: %d\n",x,y);
	f1(&x,&y);
	printf("X: %d Y: %d\n",x,y);
	return 0;
}
