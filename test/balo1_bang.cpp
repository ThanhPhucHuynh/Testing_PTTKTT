#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 100
typedef struct {	
	char TenDV[20];
	int TL, GT;
	int PA;
}DoVat;


DoVat *dsdv;
int n;
//int x[MAX];
//float W,CT,TGT,GiaLNTT,TLConLai;

typedef int bang[50][100];


DoVat * ReadFromFile(int *W, int *n){
	 FILE *f;
	 f = fopen("balo1-quyhoachcdong.inp", "r");
	 fscanf(f, "%d",W); 
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;
	while (!feof(f)){
		 fscanf(f, "%d%d",&dsdv[i].TL,&dsdv[i].GT);
		 fgets(dsdv[i].TenDV,20,f);
		 dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1]='\0';
		 dsdv[i].PA=0;
		 i++;
		 dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	} *n=i;
	 fclose(f);
	 return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
		 for (j=n-1; j>=i+1; j--){
			 float DGJ = dsdv[j].GT/dsdv[j].TL;
			 float DGJ_1 = dsdv[j-1].GT/dsdv[j-1].TL;
			 if (DGJ>DGJ_1) 
			swap(&dsdv[j],&dsdv[j-1]);
		}
}

void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("|STT|     Ten Do Vat     | T. Luong| Gia Tri | Don Gia |  P. An  | \n");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-20s",dsdv[i].TenDV);
		printf("|%-9.1d",dsdv[i].TL);
		printf("|%-9.1d",dsdv[i].GT);
		printf("|%-9.1d",dsdv[i].GT/dsdv[i].TL);
		printf("|%-9d|\n",dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("Trong luong cua ba lo= %9.1f\n",W);
	printf("Tong trong luong= %9.1f",TongTL);
	printf("Tong gia tri= %9.1f\n\n",TongGT);
	printf("X(");
	for(i=0;i<n;i++){
 	 printf("%d ", dsdv[i].PA);
		}
	printf(")");
}


void tao_bang(DoVat *dsdv,int n,int W,bang F,bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;
	
	for(V=0;V<=W;V++){
		X[0][V]=V/dsdv[0].TL;
		F[0][V]=X[0][V]*dsdv[0].GT;
	}
	for(k=1;k<n;k++){
		for(V=0;V<=W;V++){
			Fmax=F[k-1][V];
			Xmax =0 ;
			yk = V/dsdv[k].TL;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>Fmax){
					Fmax = F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					Xmax=xk;
				}		
			}
			F[k][V]=Fmax;
			X[k][V]=Xmax;
		}	
	}
	//return X;
}
void tra_bang(DoVat *dsdv,int n,int W,bang X){
	int k,V;
	V=W;
	for(k=n-1;k>=0;k--){
		dsdv[k].PA = X[k][V];
		V=V-X[k][V]*dsdv[k].TL;
	}
}
void inbang(int n,int W,bang F,bang X){
	int V,k;
	for(k=0;k<n;k++){
		for(V=0;V<=W;V++){
			printf("|%4d%2d",F[k][V],X[k][V]);
			
		}
		printf("\n");
	}
}

int main(){
	
	int W;
	bang F,X;
	dsdv=ReadFromFile(&W, &n);
//	BubbleSort(dsdv,n);
	tao_bang(dsdv,n,W,F,X);
	tra_bang(dsdv,n,W,X);
	//Greedy(dsdv,n,W);
	inbang(n,W,F,X);
	InDSDV(dsdv,n,W);
	free(dsdv);
	return 0;
}
