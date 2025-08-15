/**
04 (hibrido) fgetc y fscanf leer archivo csv con formatos variados
*/

#include <stdio.h>
#include <stdlib.h>
/**
  \brief Lectura de un archivo csv que con scanf y con expresiones regulares
		IMPORTANTE:
				AUN SE ENCUENTRA EN EVALUACIÓN
				AUN NO ESTÁ AUTORIZADO EL USO EN LA MATERIA.

        Pruebas realizadas:
			windows 10 -> ok
			ubuntu 	version ?? en replit -> ok
            Mac OS 	version ??           -> ok

		Faltan probar
			otras distribuciones linux
			distintas vesiones de mac
        
marianotrigila@gmail.com
*/

int main(){
	int res=0;
    int r;                              /** en r guardo lo que retorna fscanf*/

    int cod;                            /** variable entera que representa el primer elemento del archivo  */
    char nom[30];                       /** variable arreglo que representa el segundo elemento del archivo   */
    int obj;                            /** variable entera que representa el tercer elemento del archivo   */
    double sAnu;                        /** variable double que representa el cuarto elemento del archivo   */

    FILE* arch;                         
    arch=fopen("arch3.txt","r");        

    if(arch!=NULL){		
		r=fscanf(arch,"%d,%[^,],%d,%lf\n",&cod,nom,&obj,&sAnu); 
		//r=fscanf(arch,"%d,%[a-zA-Z0-9 ],%d,%lf\n",&cod,nom,&obj,&sAnu); 		
		while(r!=EOF){
			printf("%4d%12s%6d%10.2lf\n",cod,nom,obj,sAnu);   
			
			r=fscanf(arch,"%d,%[^,],%d,%lf\n",&cod,nom,&obj,&sAnu); 	
			//r=fscanf(arch,"%d,%[a-zA-Z0-9 ],%d,%lf\n",&cod,nom,&obj,&sAnu); 
		}		
		fclose(arch);                   
	}else{
		res=-1;
	}
    return res;
}
