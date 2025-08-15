#include <stdio.h>
#include<string.h>
//#pragma pack(1) //https://www.javatpoint.com/structure-padding-in-c
//
struct s_fecha{
	int dd,mm,aa;  //12
};
typedef struct s_fecha t_fecha;

struct s_punto{
	int x,y,z;     // 12
	char nom[28];  // 28
	t_fecha fecha; // 12
	
				   // 52
};
typedef struct s_punto t_punto; //t_punto

/*typedef struct s_punto{*/
/*	double x,y,z;*/
/*}t_punto;*/

void imprimePunto(t_punto p);
int main() {
	//struct s_p3d p;
	t_punto arrP[10],auxP;
	t_fecha auxF;
	printf("\n\n");
	printf("t_fecha: %d\n",sizeof(t_fecha));
	printf("t_punto: %d\n",sizeof(t_punto));
	
    arrP[0].x=10;
	arrP[0].y=20;
	arrP[0].z=12;
	strcpy(arrP[0].nom,"Rosario");	
	arrP[0].fecha.dd = 18;
	arrP[0].fecha.mm = 03;
	arrP[0].fecha.aa = 19;	
	
	arrP[1].x=101;
	arrP[1].y=201;
	arrP[1].z=121;
	strcpy(arrP[1].nom,"Cordoba");	
	auxF.dd=25;
	auxF.mm=12;
	auxF.aa=20;
	arrP[1].fecha=auxF;
	
	auxP = arrP[1];
	
	imprimePunto(arrP[0]);
	imprimePunto(arrP[1]);
	imprimePunto(auxP);	
	
	printf("\n%d",sizeof(double));
	printf("\n\n");
	return 0;
}

void imprimePunto(t_punto p){
	printf("\nx: %4d, y:%4d, z:%4d\n",p.x,p.y,p.z);
	printf("\t nom: %s\n",p.nom);
	printf("\t Fecha: %2d/%2d/%2d\n",p.fecha.dd,p.fecha.mm,p.fecha.aa);
	
}

	
	
	
	
	
/*	struct s_punto{*/
/*		double x,y,z;*/
/*	};*/
/*	typedef struct s_punto t_punto; //t_punto*/
	
	/*typedef struct s_punto{*/
	/*	double x,y,z;*/
	/*}t_punto;*/
	
/*	void imprimePunto(t_punto p);*/
/*	int main() {*/
		//struct s_p3d p;
		
/*		t_punto p1,p2;	*/
		
		
		
/*		p1.x=1; p1.y=12; p1.z=10;*/
/*		p2.x=122; p2.y=112; p2.z=101;*/
		
/*		imprimePunto(p1);*/
/*		imprimePunto(p2);*/
/*		printf("\n%d",sizeof(double));*/
		
/*		return 0;*/
/*	}*/
	
/*	void imprimePunto(t_punto p){*/
/*		printf("\nx: %.2lf, y:%.2lf, z:%.2lf\n",p.x,p.y,p.z);*/
/*	}*/
		
		
