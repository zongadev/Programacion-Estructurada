#include <stdio.h>
#include <string.h>
#define T 100

void cargarText(char arrC[]){
	strcpy(arrC,"    hola  como va,    hoy es    lunes mmmm.  ");
}
void imprimirText(char arrC[]){
	printf("%s\n",arrC);
	
}
void normalizar(char txt[]){
	int i,j,k;
	j=0;
	i=0;	
	while(txt[i]!='\0'){
		while(txt[i]!='\0' && txt[i]==' ' ){ // busca la proxima letra
			i++;
		}
		while(txt[i]!='\0' && txt[i]!=' ' ){ // alamcena las letras
			txt[j]= txt[i];
			j++;
			i++;
		}
		txt[j]=txt[i];                       //almacena un espacio o  el '\0'
		j++;
	}
	// Mayuscula la primer letra
	if(txt[0]>='a'&&txt[0]<='z'){
		txt[0]=txt[0]-32;
	}
}
	
/**
void normalizar(char arrC[]){
	int i,j,k;
	i=0;
	// elimina espacios de adelante
	for(k=0;arrC[k]!='\0' && arrC[k]==' ' ;k++);	
	for(j=0;arrC[k]!='\0';j++,k++){
		arrC[j]=arrC[k];		
	}
	arrC[j]=arrC[k]; //para asignar el '\0'
	
	// elimina los espacios intermedios y del final
	for (i=0;arrC[i]!='\0';i++){
		if (arrC[i]==' '&&arrC[i+1]==' '){
			for (j=i+1;arrC[j]!='\0';j++){
				arrC[j]=arrC[j+1];
			}
			i--;
		}
	}
	// colocar el punto al final
	i--;
	if(i<T-1){
		arrC[i]='.';
		arrC[i+1]='\0';
	}
	// Mayuscula la primer letra
	if(arrC[0]>='a'&&arrC[0]<='z'){
		arrC[0]=arrC[0]-32;
	}
}
	*/
int main() {
	char arrC[T];
	cargarText(arrC);
	normalizar(arrC);
	imprimirText(arrC);
	return 0;
}

