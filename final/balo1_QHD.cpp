#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
	char Ten[25];
	int TL,GT,PA,Sl;
}Dovat;

Dovat * ReadFile(int *w,int *n){
	Dovat *dsdv;
	dsdv= (Dovat*)malloc(sizeof(Dovat));
	int i =0;
	FILE *f=fopen("Balo2_qhd.INP","r");
	fscanf(f,"%d",w);
	while(!feof(f)){
		fscanf(f,"%d%d%d",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].Sl);
		fgets(dsdv[i].Ten,25,f);
		dsdv[i].Ten[strlen(dsdv[i].Ten)-1]='\0';
		i++;
		dsdv = (Dovat *)realloc(dsdv,sizeof(Dovat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}
int min(int a,int b){
	if(a>b) return b;
	else return a;
}

void InDV(Dovat *dsdv,int n,int w){
	int i;
	float TongGiaTri=0,tongtien=0;
	printf("|---|-------------------------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s|\n","STT","Ten hang","TL","GT","PA");
	printf("|---|-------------------------|---------|---------|---------|\n");

	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1 );
		printf("|%-25s",dsdv[i].Ten );
		printf("|%-9d",dsdv[i].TL);
		printf("|%-9d",dsdv[i].GT);
	//	printf("|%-9.2f",dsdv[i].DG);
		printf("|%-9d|\n",dsdv[i].PA);
		tongtien += dsdv[i].PA*dsdv[i].TL;
		TongGiaTri += dsdv[i].PA*dsdv[i].GT;
	}
	printf("Tong TongGiaTri= %.2f ---- Kl = %.2f\n",TongGiaTri,tongtien );
}

typedef int Bang[100][100];

void TaoBang(Dovat *dsdv, int n,int w,Bang F,Bang X){
	int xk,yk,k;
	int Fmax,Xmax,v;
	for(v=0;v<=w;v++){
		//X[0][v]=v/dsdv[0].TL;
		X[0][v]=min(v/dsdv[0].TL,dsdv[0].Sl);
		F[0][v]=X[0][v]*dsdv[0].GT;
	}
	for(k=1;k<n;k++){
		for(v=0;v<=w;v++){
			Fmax= F[k-1][v];
			Xmax =0;
			yk =min(v/dsdv[k].TL,dsdv[k].Sl);
			//yk= v/dsdv[k].TL;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][v-xk*dsdv[k].TL]+xk*dsdv[k].GT>Fmax){
					Fmax=F[k-1][v-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					Xmax = xk;
				}
			}
			F[k][v]=Fmax;
			X[k][v]=Xmax;
		}
	}
}
void trabang(Dovat *dsdv,int w,int n,Bang X){
	int k,v;
	v=w;
	for(k=n-1;k>=0;k--){
		dsdv[k].PA = X[k][v];
		v=v-X[k][v]*dsdv[k].TL;
	}
}
void inbang(int w,int n,Bang F,Bang X){
	int k,v;
	for(k=0;k<n;k++){
		for(v=0;v<=w;v++){
			printf("|%4d %2d ",X[k][v],F[k][v] );

		}
		printf("\n" );
	}
}

int main(){
	Dovat *dsdv;
	int n,w;
	Bang F,X;
	dsdv = ReadFile(&w,&n);
	TaoBang(dsdv,n,w,F,X);
	trabang(dsdv,w,n,X);
	InDV(dsdv,n,w);

	return 0;
}

