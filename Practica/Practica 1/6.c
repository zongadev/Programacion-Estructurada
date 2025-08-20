#include <stdio.h>
int T=100;

int cargarText(char text[T]);
void imprimirText(char text[T]);
void normalizar(char text[T],int len);

int cargarText(char text[T]){
	printf("Ingrece un texto: ");
	char c;
	int i=0;
	while(i<T && ((c=getchar())!='\n')){
		text[i]=c;
		i++;
	}
	text[i]='\0';
	return i;
}

void imprimirText(char text[T]){
	printf("\n Texto: \t %s",text);
}
	
void normalizar(char text[T], int len){
	char temp;
	if(text[0]>=97 || text[0]<=122){
		text[0]=text[0]-32;
	}
	for(int i=0; text[i]!= '\0';i++){ //el ciclo I es el que recorre la palabra
		printf("i:[%c]",text[i]);
		for(int j = i; text[j]==' '; j++){ //el ciclo J es el que itera dentro de los espacios
			printf("j:[%c]",text[j]);
			if(j>0){
				
				for(int k =i+1; text[i]!='\0';k++){//el ciclo K es para desplazar
					printf("k:[%c]",text[k]);
					text[k]= text[k+1];
					k++;
				}
				
		}
	}
}
}
int main(){
	char text[T];
	int l;
	l=cargarText(text);
	imprimirText(text);
	normalizar(text,l);
	imprimirText(text);
}
