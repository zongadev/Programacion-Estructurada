#include <stdio.h>
#include <stdlib.h>
#define T 10
/**
Para visualizar archivos Binarios
https://hexed.it/
*/

struct sVenTar{         // 33 byte
    int codVen;         //  4 byte
    char mesVenta[25];  // 25 byte
    int canTar;         //  4 byte
	
};
typedef  struct sVenTar tVenTar;


int escribirArchivo(FILE* fichero);
int leerArchivo(FILE* fichero);

int main(){
  
	FILE* fichero = fopen( "ventasTarjetas.dat","w+b" );

    escribirArchivo(fichero);
    rewind( fichero );
    leerArchivo(fichero);

	
	printf("\n");
	printf("------- %d -------",sizeof(tVenTar));
	
	fclose(fichero);
	
   return 0;
}


int escribirArchivo(FILE* fichero){
    /** cargar el arreglo de tVenTar con datos validos*/
    tVenTar venTar[T]={{ 1, "Enero", 91},
                        { 1, "Febrero", 60},
                        { 1, "Marzo", 60},
                        { 3, "Febrero", 60},
                        { 6, "Marzo", 76},
                        { 1, "Enero", 90},
                        { 7, "Febrero", 60},
                        { 7, "Marzo", 62},
                        { 8, "Febrero", 60},
                        { 8, "Marzo", 96}
                      };

    int i;

    printf( "Escribiendo cantidades:\n\n" );
    for( i=0; i<T; i++ ){
        printf( "%d\t%s\t%d\t\n", venTar[i].codVen,venTar[i].mesVenta,venTar[i].canTar);
		
        fwrite( &venTar[i], sizeof(tVenTar), 1, fichero );
    }	
	//fwrite( venTar, sizeof(tVenTar), T, fichero );
	return 0;
}
	
int leerArchivo(FILE* fichero){
    int  i;
    tVenTar leer[T]={0};
    printf( "\nLeyendo los datos del fichero \n" );
    i=0;
	/**
    fread( &leer[i], sizeof(tVenTar), 1, fichero );
    while(!feof(fichero)) {
        printf("%d\t%s\t%d\t\n", leer[i].codVen,leer[i].mesVenta,leer[i].canTar);
        i++;
		fread( &leer[i], sizeof(tVenTar), 1, fichero );
    }	
	*/
    //sin feof, utilizando el retorno de bytes leidos de fread (el count)
	
    int res=fread( &leer[i], sizeof(tVenTar), 1, fichero );
    while(res!=0 ) {
        printf("%d\t%s\t%d\t\n", leer[i].codVen,leer[i].mesVenta,leer[i].canTar);
        i++;
        res=fread( &leer[i], sizeof(tVenTar), 1, fichero );
    }
    
	return 0;
}

