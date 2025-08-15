#include <stdio.h>

int main() {
	char texto[100];
	char letra;
	int i =0;
	printf("Ingrese una oracion de 100 letras como maximo \n");
	while(i!=100){
		letra= getchar();
		texto[i]=letra;
		i++;
		if(letra == '\n'){
			texto[i]='\0';
			i=100;
		}
	}
	
	/*
	while(i!=100 && (letra=getchar())!= '\n'){
	texto[i]=letra;
	i++;
	}
	texto[i]='\0';
	
	*/
	printf(texto);
	return 0;
}

