#include<string.h>
#include <math.h>
#include <stdio.h>

double f3(double *p){
	return round(*p);
}
int main(){
	double x=2.56;
	printf("%f",f3(&x));
	return 0;
}
