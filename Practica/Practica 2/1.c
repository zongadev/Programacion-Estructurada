#include <stdio.h>
#include<string.h>
#include <math.h>
typedef struct punto{
	float x;
	float y;
} punto;


int main() {
	punto pa,pb;
	printf("Ingrese las coordenadas de un punto \n X:");
	scanf("%f",&pa.x);
	printf("Y:");
	scanf("%f",&pa.y);
	
	printf("Ingrese las coordenadas de otro punto \n X:");
	scanf("%f",&pb.x);
	printf("Y:");
	scanf("%f",&pb.y);
	printf("\n\n");
	if(sqrt(pow(pa.x,2)+pow(pa.y,2))<sqrt(pow(pb.x,2)+pow(pb.y,2))){
		printf("El punto (%.1f,%.1f) esta mas cerca del origen", pa.x,pa.y);
	}else{
		printf("El punto (%.1f,%.1f) esta mas cerca del origen", pb.x,pb.y);
		
	}
	return 0;
}

