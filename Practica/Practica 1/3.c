#include <stdio.h>

void leer(char texto[100]){
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
	
}
void reemplazar(char t[100]){
		char c,n;
		int i=0;
		printf("Ingrese el caracter a reemplazar: ");
		c=getchar();
		printf("\n Ingrese el caracter nuevo: ");
		getchar();
		n=getchar();
		while(t[i]!='\0'){
			if(t[i]==c){
				t[i]=n;
		}
			i++;
		}
		printf("Reemplazado: \n %s",t);
	}

int main() {
	char texto[100];
	leer(texto);
	reemplazar(texto);
	return 0;
}
	/*
	while(i!=100 && (letra=getchar())!= '\n'){
	texto[i]=letra;
	i++;
	}
	texto[i]='\0';
	
	*/
	

