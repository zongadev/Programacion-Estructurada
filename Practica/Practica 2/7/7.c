#include <stdio.h>
#include <string.h>
#define NA 10
#define NM 20

typedef struct alumno{
	char nombre[100];
	int legajo, materias[30];
}
t_alumno;
typedef struct materia{
	char nombre[100];
	int codigo;
}t_materia;
typedef struct nota{
	int legajo_alumno;
	int cod_materia,nota;
}t_nota;


void cargaAlumnos(char arcAlu[]){
	int i=0,legajo,materias[30],j=0;
	char nombre[100];
	char c;
	FILE* arch=fopen(arcAlu,"w");
	printf("Ingrese un alumno");
	while(i<NA &&legajo !=0){
		
		printf("\n\tIngrese el legajo del alumno: \t");
		scanf("%d",&legajo);
		getchar();
		if(legajo !=0){
			printf("\n\tIngrese el nombre: \t");
			while((c=getchar()) != '\n' && j<100-1){
				nombre[j]=c;
				j++;
			}
			c=' ';
			nombre[j]='\0';
			j=0;
			
			
			
			printf("\n\t A continuacion ingrese, separado por enters, los codigos de las materias cursadas: \n");
			scanf("%d",&materias[j]);
			while(j<30 && materias[j]!=0){
				j++;
				scanf("%d",&materias[j]);
				getchar();
			}
			j=0;
			
			fprintf(arch,"%s,%d",nombre,legajo);
			while(materias[j]!=0){
				fprintf(arch,",%d",materias[j]);
				j++;
			}
			j=0;
			fprintf(arch,"\n");
			printf("===================");
		}
	}
	fclose(arch);
}

void cargarMaterias(char archivo[]){
	int i=0,cod,j=0;
	char nombre[100];
	char c;
	FILE* arch=fopen(archivo,"w");
	printf("Ingrese las materias: ");
	while(i<NA &&cod !=0){
		
		printf("\n\tIngrese el codigo de la materia: \t");
		scanf("%d",&cod);
		if(cod !=0){
			printf("\n\tIngrese el nombre de la materia: \t");
			while((c=getchar()) != '\n' && j<100-1){
				nombre[j]=c;
				j++;
			}
			c=' ';
			nombre[j]='\0';
			j=0;
	
			
			fprintf(arch,"%s,%d\n",nombre,cod);
			printf("===================");
		}
	}
	fclose(arch);
	
}
void cargaAlumnosMat(t_alumno mat[NA], char archivo[]){
	FILE* arch= fopen(archivo,"r");
	t_alumno aux;
	char c;
	int i=0,j=0,r;
	r=fscanf(arch,"%100[^,],%d",aux.nombre,&aux.legajo);
	c=fgetc(arch);
	while(r!=EOF && c!='\n' && i<NA){
		while(j<30&& c!='\n'){
			r=fscanf(arch,"%d",&aux.materias[j]);
			c=fgetc(arch);
			if(c!='\n'){
				printf("%d",aux.materias[j]);
				j++;
			}
		}
		mat[i]=aux;
		printf("%s,%d \n",aux.nombre,aux.legajo);
		i++;
		r=fscanf(arch,"%100[^,],%d",aux.nombre,&aux.legajo);
		c=fgetc(arch);
	}
	
}

	int main(){
	char archAlu[]="alumnos.txt", archMat[]="materias.txt";
	
	t_alumno alumnosArr[NA];
	cargaAlumnos(archAlu);
	cargarMaterias(archMat);
	cargaAlumnosMat(alumnosArr,archAlu);
	return 0;
}
