/**
 * Ejercicio 02.07
 * Se realizo un programa que lee de un archivo de texto los datos de alumnos y materias,
 * y son almacendado en un arreglos de estrcuturas.
 * Para el caso de archivo alumnos.txt los registros son de tamanio variable, por tanto se 
 * realiza un agoritmo espcifico para leer el archivo.
 */


#include <stdio.h>
#include <string.h>

#define NA 20    // Numero de alumnos
#define NM 30    // Numero de materias
#define T 100    // Tamanio para el arreglo nombre
  
#define TERM_I -999 

struct alumno {
	char nombre[T];
	int legajo, materias[NM];
}; 
struct materia{
	char nombre[NM];
	int codigo;
}; 
struct nota {
	int legajo_alumno;
	int cod_materia,nota;
}; 


void cargarAlumnos(struct alumno alumnos[]){
	int retorno; 
	int i,j,fin; 	
	FILE* arch; 
	arch = fopen("alumnos.txt","r"); 	
	if (arch!=NULL){
		i=0;
		fscanf(arch,"%[^,],%d,",alumnos[i].nombre,&(alumnos[i].legajo)); 			
		while (!feof(arch) && i<NA-1){	
			j=0;
			fin=0;
			while (!feof(arch) &&  j<NM-1 && fin==0){
				fscanf(arch,"%d",&(alumnos[i].materias[j])); 
				j++;
				retorno=fgetc(arch);
				if (retorno==EOF || retorno == '\n'){
					fin=1;
				}				
			}
			alumnos[i].materias[j] = TERM_I; 			
			i++; 
			if (!feof(arch)){				
				fscanf(arch,"%[^,],%d,",alumnos[i].nombre,&alumnos[i].legajo);  					
			}
		} 
		alumnos[i].legajo = TERM_I;	
		fclose(arch);	
	}	
}
	
void cargarMaterias(struct materia materias[]){
	int i,j,fin; 	
	FILE* arch; 
	arch = fopen("materias.txt","r"); 	
	if (arch!=NULL){	
		i=0;
		fscanf(arch,"%[^,],%d\n",materias[i].nombre,&(materias[i].codigo)); 			
		while (!feof(arch) && i<NM-1){	
			i++;
			fscanf(arch,"%[^,],%d\n",materias[i].nombre,&(materias[i].codigo)); 			
		}	
		materias[i+1].codigo = TERM_I;	
	}	
}
	
void imprimirAlumnos(struct alumno alumnos[]){
	int i=0,j; 
	printf("%20s%14s%30s\n","ALUMNOS","LEGAJO","... CODIGOS DE MATERIAS ....");
	for (i=0; i<NA && alumnos[i].legajo != TERM_I; i++){
		printf("%20s%14d",alumnos[i].nombre,alumnos[i].legajo); 
		
		for (j=0; j<NM && alumnos[i].materias[j]!=TERM_I;j++){
			printf("%8d",alumnos[i].materias[j]);
		}		
		printf("\n");
	}
}

void imprimirMaterias(struct materia materias[]){
	int i=0,j; 
	printf("%20s%8s\n","MATERIA","CODIGO");
	for (i=0; i<NM && materias[i].codigo != TERM_I; i++){
		printf("%20s%8d",materias[i].nombre,materias[i].codigo); 
		printf("\n");
	}
}
	
int main() {

	struct alumno alumnos[NA]; 
	struct materia materias[NM];
	cargarAlumnos(alumnos); 
	imprimirAlumnos(alumnos);
	printf("\n");
	cargarMaterias(materias);
	imprimirMaterias(materias);
	
	return 0;
}

