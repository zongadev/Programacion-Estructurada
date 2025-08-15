#include <stdio.h>
#include <stdlib.h>
#define T 10
/**
int fseek(FILE *stream, long int offset, int whence)
      La funcion fseek() cambia la posición de archivo actual que está asociada 
	  con la ruta a una nueva ubicación dentro del archivo.

	stream : es el puntero a un objeto ARCHIVO que identifica el flujo.
	offset : es el numero de bytes para hacer desplazamiento.
	whence : (de donde)posicion desde donde se agrega el desplazamiento. 
			Se especifica whence mediante una de las 
			siguientes constantes:
			SEEK_SET  -> 0 Comienzo del archivo 
			SEEK_CUR  -> 1 Posicion actual del puntero del archivo
			SEEK_END  -> 2 Fin del documento

int ftell(FILE * handle)
	La funcion ftell retorna la posicion de puntero del archivo es decir
	el desplazamiento en byte desde la posicion cero (inicial) del archivo.
*/

struct sPersona{
    unsigned int dni;
    char nom[25];
    char ape[25];
};
typedef struct sPersona tPersona;

int escribirArchivo(FILE* arch){
	int res=0;
	
    tPersona personas[T]={{ 9, "Julian", "Alvarez"}, {10, "Lionel", "Messi"},
                         {23, "Emiliano", "Martinez"}, {25, "Lisandro", "Martinez"},
                         {11, "Angel", "Di Maria"}, {1, "Franco", "Armani"},
                         {7, "Rodrigo", "De Paul"}, {22, "Lautaro", "Martinez"},
                         {13, "Cristian", "Romero"},{19, "Nicolas", "Otamendi"}
                      };

    fwrite( personas, sizeof(tPersona), T, arch );
}

void leerPorPosicion(tPersona* aux,int pos,FILE* arch){
	int offset=(sizeof(tPersona)*pos);
	fseek(arch, offset, SEEK_SET);		
	fread( aux, sizeof(tPersona), 1, arch );
	
}
			
int main () {
	int i=0;
	tPersona aux;
	FILE* arch=NULL;
	/** 
	arch=fopen("datos.dat","wb");
	escribirArchivo(arch);
	
	*/		
	arch=fopen("datos.dat","rb");
	/*
	fseek(arch, 0, SEEK_SET);	//es lo mismo que hacer -> rewind(arch);	
	*/	
	
	printf("Sizeof:%d\n",sizeof(tPersona));
	
	printf("\nImprimir el contenido del archivo posicionando el puntero\n\n");
	for (i=0;!feof(arch);i++){	
		leerPorPosicion(&aux,i,arch);
		printf("%4d:%4d%12s%12s\n",ftell(arch),aux.dni,aux.nom,aux.ape);
	}

	/*
	printf("\n%4d",SEEK_SET);//0
	printf("\n%4d",SEEK_CUR);//1
	printf("\n%4d",SEEK_END);//2
	*/
	printf("\nObtener el tamanio del archivo en bytes\n");
	fseek(arch, 0, SEEK_END);      // posicionar el puntero al final
	printf("El Tamanio del archivo es: %6d",ftell(arch)); //obtener la posicion del puntero
	
	fclose(arch);
	return 0 ;
}
