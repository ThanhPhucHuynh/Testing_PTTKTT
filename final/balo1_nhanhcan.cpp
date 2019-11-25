#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
	char Ten[25];
	float TL,GT,DG;
	int PA ,SL;

}DoVat;


DoVat *dsdv;
int n;
int x[100];
float CT;
float w;
float GTLNTT;//gia tri lon nhat tam thoi
float TGT;
float TLConLai;
void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sapxep(DoVat dsdv[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(dsdv[j].DG >dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

DoVat * ReadFile(float *w,int *n){
	int i=0;
	DoVat *dsdv;
	dsdv = (DoVat *)malloc(sizeof(DoVat));
	FILE *f=fopen("CaiBalo1.inp","r");
	fscanf(f,"%f",w);

	while(!feof(f)){
		fscanf(f,"%f%f",&dsdv[i].TL,&dsdv[i].GT);
		dsdv[i].DG= dsdv[i].GT/dsdv[i].TL;
		fgets(dsdv[i].Ten,25,f);
		dsdv[i].Ten[strlen(dsdv[i].Ten)-1]='\0';
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*) realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n =i;
	fclose(f);
	return dsdv;
}

void InDV(DoVat *dsdv,int n,int w){
	int i;
	float TongGiaTri=0,tongtien=0;
	printf("|---|-------------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s|%-9s|\n","STT","Ten hang","TL","GT","DG","PA");
	printf("|---|-------------------------|---------|---------|---------|---------|\n");

	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1 );
		printf("|%-25s",dsdv[i].Ten );
		printf("|%-9.2f",dsdv[i].TL);
		printf("|%-9.2f",dsdv[i].GT);
		printf("|%-9.2f",dsdv[i].DG);
		printf("|%-9d|\n",dsdv[i].PA);
		tongtien += dsdv[i].PA*dsdv[i].TL;
		TongGiaTri += dsdv[i].PA*dsdv[i].GT;
	}
	printf("Tong TongGiaTri= %.2f ---- Kl = %.2f\n",TongGiaTri,tongtien );
}

int min(int a,int b){
	if(a>b) return b;
	else return a;
}
void init(){//khoi tao
	TGT = 0;
	TLConLai = w;
	CT = TLConLai*dsdv[0].DG;
	GTLNTT = 0;
}
void GhiNhanKyLuc(){
	int i;
	if(GTLNTT<TGT){
		GTLNTT=TGT;
		for(i=0;i<=n-1;i++){
			dsdv[i].PA = x[i];
		}
	}
}
void Try(int i){
	int j;

	for(j=TLConLai/dsdv[i].TL;j>=0;j--){
		TGT = TGT + j*dsdv[i].GT;
		TLConLai = TLConLai - j*dsdv[i].TL;
		CT= TGT + dsdv[i].DG*TLConLai;
		if(CT>GTLNTT){
			x[i]=j;
			if(i==n-1||TLConLai ==0 ){
				GhiNhanKyLuc();
			}else{
				Try(i+1);
			}
		}
		x[i]=0;
		TGT = TGT - j*dsdv[i].GT;
		TLConLai = TLConLai + j*dsdv[i].TL;

	}
}



int main(){
	dsdv =ReadFile(&w,&n);
	sapxep(dsdv,n);
	init();
	Try(0);
	InDV(dsdv,n,w);
	return 0;
}
