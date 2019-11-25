#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct 
{
	char ten[25];
	int SL,TL,PA,GT;
}DoVat;
typedef int Bang[100][100];




DoVat * DocFile(int *W,int *n){
	DoVat *dsdv;
	FILE *f ;
	f= fopen("balo1-quyhoachcdong.inp","r");
	int i=0;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
//	fscanf(f,"%d",W);
	fscanf(f, "%d",W); 
	//printf("%d\n",W );
	while(!feof(f)){
		fscanf(f,"%d%d",&dsdv[i].TL,&dsdv[i].GT);
		fgets(dsdv[i].ten,25,f);
		dsdv[i].ten[strlen(dsdv[i].ten)-1]='\0';
		dsdv[i].PA=0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}
DoVat * ReadFromFile(int *W, int *n){
	 FILE *f;
	 f = fopen("balo1-quyhoachcdong.inp", "r");
	 fscanf(f, "%d",W); 
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;
	while (!feof(f)){
		 fscanf(f, "%d%d",&dsdv[i].TL,&dsdv[i].GT);
		 fgets(dsdv[i].ten,20,f);
		 dsdv[i].ten[strlen(dsdv[i].ten)-1]='\0';
		 dsdv[i].PA=0;
		 i++;
		 dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	} *n=i;
	 fclose(f);
	 return dsdv;
}

void INDV(DoVat *dsdv,int n,int w){
	int KLThuc;
	int TongGTri;

	printf("|---|-------------------------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s\n","STT","TEN","TL","GT","PA");
	printf("|---|-------------------------|---------|---------|---------|\n");
	int i;
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-25s", dsdv[i].ten);
		printf("|%-9d", dsdv[i].TL);
		printf("|%-9d", dsdv[i].GT);
		printf("|%-9d\n", dsdv[i].PA);
		KLThuc = KLThuc + dsdv[i].PA*dsdv[i].TL;
		TongGTri =TongGTri + dsdv[i].PA*dsdv[i].GT;

	}
	printf("tonf gia tri : %d---%d\n",TongGTri,KLThuc);
}

void TaoBang(DoVat *dsdv, int n, int W, Bang F,Bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;
	for(V=0;V<=W;V++){
		X[0][V]=V/dsdv[0].TL;
		F[0][V]=X[0][V]*dsdv[0].GT;
	}
	for(k=1;k<n;k++){
		for(V=0;V<=W;V++){
			Fmax = F[k-1][V];
			Xmax=0;
			yk=V/dsdv[k].TL;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>Fmax){
					Fmax = F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					Xmax = xk;
				}
			}
			F[k][V]=Fmax;
			X[k][V]=Xmax;
		}
	}

}

void trabang(DoVat *dsdv, int n,int W,Bang X){
	int k,v;
	v=W;
	for(k=n-1;k>=0;k--){
		dsdv[k].PA=X[k][v];
		v=v-X[k][v]*dsdv[k].TL;
	}
}
void inbang(int n,int w,Bang F,Bang X){
	int k,v;
	for(k=0;k<n;k++){
		for(v=0;v<=w;v++){
			printf("%4d%2d",X[k][v],F[k][v]);
		}
		printf("\n");
	}
}





int main(){
	DoVat *dsdv;
	Bang F,X;

	int n;
	int W;
	dsdv = DocFile(&W,&n);
	printf("%d\n",n );
	TaoBang(dsdv,n,W,F,X);
	trabang(dsdv,n,W,X);
	inbang( n, W, F, X);
	INDV(dsdv,n,W);
	return 0;
}
