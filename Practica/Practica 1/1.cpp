#include <stdio.h>
#include <math.h> 

int main(){
	float num;
	printf("Ingrese un numero real: ");
	scanf("%f",&num);
	printf("Numero redondo: %.0f \n Piso: %.0f  \n Cielo: %.0f",num,floor(num),ceil(num));
}
