#include <stdio.h>

int resto(int a, int b){
	if(a<b){
		return a;
	}
	return resto(a-b,b);
}

int main(int argc, char *argv[]) {
	printf("%d", resto(12,5));
	return 0;
}

