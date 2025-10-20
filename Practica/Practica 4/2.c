#include <stdio.h>

int cociente(int a, int b){
	if(a==0) return 0;
	return 1+cociente(a-b,b);
}

int main() {
	printf("%d",cociente(10,2));
	return 0;
}

