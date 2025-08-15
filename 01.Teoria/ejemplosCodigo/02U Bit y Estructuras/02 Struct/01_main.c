#include <stdio.h>
//#pragma pack(1) //https://www.javatpoint.com/structure-padding-in-c
struct s_fecha{
	int dd,mm,aa;  //12
};
typedef struct s_fecha t_fecha;

struct s_punto{
	int x,y,z;     // 12
	char nom[26];  // 28
	t_fecha fecha; // 12
	
	// 52
};
typedef struct s_punto t_punto; //t_punto

int main() {
	printf("\n\n");
	printf("%d\n",sizeof(t_punto));
	printf("\n\n");
	return 0;
}

