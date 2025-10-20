#include <stdio.h>


int producto(int a, int b){
	if(b<1){
		return 0;
	}
	return a+producto(a,b-1);
}
int main() {
	printf("%d",producto(5,2));
	return 0;
}

