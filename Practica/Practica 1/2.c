#include <stdio.h>
void operar(float a,float b,char signo){
	if(signo == '+'){
		printf(suma(a,b));
	}
	if(signo =='-'){
		printf(resta(a,b));
	}
	if(signo =='*'){
		printf(multiplicacion(a,b));
	}
	if(signo =='/'){
		printf(division(a,b));
	}
}
	
	float suma(float a, float b){
		return a+b;
	}
		
		float resta(float a, float b){
			return a-b;
		}	
			
			float multiplicacion(float a, float b){
				return a*b;
			}
				
				float division(float a, float b){
					return a/b;
				}
					


int main() {
	char signo;
	float a,b;
	
	printf("Ingrese un numero");
	scanf("%f",&a);
	
	getchar();
		
	printf("Ingrese la operacion a realizar");
	scanf("%c",&signo);
	
	printf("Ingrese un numero");
	scanf("%f",&b);
	
	operar(a,b,signo);
	return 0;
}

