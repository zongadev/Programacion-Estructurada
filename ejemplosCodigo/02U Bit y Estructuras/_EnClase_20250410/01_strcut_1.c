#include <stdio.h>
#include <string.h>
#define T 20
#define TER -999
struct s_fecha{
	int dd,mm,aa;	
};
typedef struct s_fecha t_fecha;
struct s_punto{
	int x,y,z;
	char nom[T];
	t_fecha fecha;
};
typedef  struct s_punto t_punto;


void imprimir(t_punto p[5]){
	int i;
	for(i=0;i<5 && p[i].x!=TER;i++){
		printf("pa (%d,%d,%d,%s,%c,%d/%d/%d)\n",p[i].x,p[i].y,p[i].z,p[i].nom,p[i].nom[0],p[i].fecha.aa,p[i].fecha.mm,p[i].fecha.dd);
	}	
}

int main(){
	
	printf("\nESTRUCTURAS\n");
	t_punto p[5]= {{1,2,3,"B.Aires",{31,12,2024}},
						{10,20,31,"Lujan",{10,4,2025}},
						{TER,0,0,"",{0,0,0}},
						{0},
						{0} 
						};
	
	p[0].fecha.dd=24;
	imprimir(p);

		
	
	//t_punto pa;
	//t_punto pb={1,2,3,"B.Aires",{31,12,2024}};
	
	
	//pa.x=10;
	//pa.y=20;
	//pa.z=31;
	//strcpy(pa.nom,"Lujan");
	//pa.fecha.aa=2025;
	//pa.fecha.mm=4;
	//pa.fecha.dd=10;
	
	
	
	
	
	//pb=pa;	
	//pb.x=71;
	//pb.y=66;
	//pb.z=99;
	
	//printf("pa (%d,%d,%d,%s,%c,%d/%d/%d)\n",pa.x,pa.y,pa.z,pa.nom,pa.nom[0],pa.fecha.aa,pa.fecha.mm,pa.fecha.dd);
	//printf("pb (%d,%d,%d,%s)\n",pb.x,pb.y,pb.z,pb.nom);
	//printf("pb (%d,%d,%d,%s,%c,%d/%d/%d)\n",pb.x,pb.y,pb.z,pb.nom,pb.nom[0],pb.fecha.aa,pb.fecha.mm,pb.fecha.dd);

    printf("\n");
	return 0;
}
