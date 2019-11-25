#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
	char ten[25];
	float TL,GT,DG;
	int PA;
}DoVat;


DoVat *dsdv;
int x[100];
int n;
float W;
float CT;
float GTLNTT;
float TLConLai;
float TGT;

DoVat * DocFile(float *W, int *n){
	int i=0;
	DoVat *dsdv;
	dsdv = (DoVat *)malloc(sizeof(DoVat));
	FILE *f;
    f=fopen("CaiBalo1.INP", "r");
	fscanf(f,"%f",W);
	while(!feof(f)){
		fscanf(f,"%f%f",&dsdv[i].TL,&dsdv[i].GT);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
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

void swap(DoVat *a,DoVat *b){
	DoVat temp;
	temp= *a;
	*a=*b;
	*b = temp;
}
void BB(DoVat *dsdv,int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=n-1;j>=i+1;j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}
void InDV(DoVat *dsdv,float W, int n){
	float tonggiatri=0;
	int i;
	float ww=0;

	printf("|---|-------------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s|%-9s|\n","STT","TEN","TL","GT","DG","PA");
	printf("|---|-------------------------|---------|---------|---------|---------|\n");
	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1);
		printf("|%-25s", dsdv[i].ten);
		printf("|%-9.2f", dsdv[i].TL);
		printf("|%-9.2f", dsdv[i].GT);
		printf("|%-9.2f", dsdv[i].DG);
		
		printf("|%-9d|\n", dsdv[i].PA);

		tonggiatri = tonggiatri + dsdv[i].PA*dsdv[i].GT;
		ww = ww + dsdv[i].PA *dsdv[i].TL;


	}

	printf("tonf gia tri : %f---%f\n",tonggiatri,ww);



}

//klhoi tao
void init(){
	TLConLai = W;
	CT = TLConLai*dsdv[0].DG;
	GTLNTT = 0;
	TGT=0;
}
void GhiKyLuc(){
	int i;
	if(GTLNTT<TGT){
		GTLNTT = TGT;
		for(i=0;i<=n-1;i++){
			dsdv[i].PA=x[i];
		}
	}
}

void Try(int i){
	int j;//so vat duoc chon
	for(j=TLConLai/dsdv[i].TL;j>=0;j--){
		TGT = TGT + j*dsdv[i].GT;
		TLConLai = TLConLai - j*dsdv[i].TL;
		CT = TGT + TLConLai*dsdv[i].DG;
		if(CT > GTLNTT){
			x[i]=j;
			if(i==n-1 || TLConLai ==0 ){
				GhiKyLuc();
			}
			else 
				Try(i+1);
		}
		x[i]=0;
		TGT = TGT - j*dsdv[i].GT;
		TLConLai = TLConLai + j*dsdv[i].TL;
	}
}






int main(){

	dsdv = DocFile(&W,&n);
	BB(dsdv,n);
	init();
	Try(0);
	InDV(dsdv,W,n);

	return 0;
}
