#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


typedef struct {

	char ten[25];
	float GT,TL,DG;
	int PA,SL;
}DoVat;


void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp = *a;
	*a = *b;
	*b= temp;
}
void BB(DoVat *dsdv,int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(dsdv[j].DG>dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

DoVat * DocFile(float *W,int *n){
	DoVat *dsdv;
	int i=0;
	FILE *f = fopen("CaiBalo2.inp","r");
	fscanf(f,"%f",W);
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%f%f%d",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL);
		dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
		fgets(dsdv[i].ten,25,f);
		dsdv[i].ten[strlen(dsdv[i].ten)-1]='\0';
		dsdv[i].PA=0;
		i++;
		dsdv = (DoVat *)realloc(dsdv,sizeof(DoVat)*(i+1));

	}
	*n=i;
	fclose(f);
	return dsdv;
}


void InDV(DoVat *dsdv,float W, int n){
	float tonggiatri=0;
	int i;
	float ww=0;

	printf("|---|-------------------------|---------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s|%-9s|%-9s|\n","STT","TEN","TL","GT","DG","SL","PA");
	printf("|---|-------------------------|---------|---------|---------|---------|---------|\n");
	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1);
		printf("|%-25s", dsdv[i].ten);
		printf("|%-9.2f", dsdv[i].TL);
		printf("|%-9.2f", dsdv[i].GT);
		printf("|%-9.2f", dsdv[i].DG);
		printf("|%-9d",dsdv[i].SL );
		printf("|%-9d|\n", dsdv[i].PA);

		tonggiatri = tonggiatri + dsdv[i].PA*dsdv[i].GT;
		ww = ww + dsdv[i].PA *dsdv[i].TL;


	}

	printf("tonf gia tri : %f---%f\n",tonggiatri,ww);



}

void Gree(DoVat *dsdv,float W,int n){

	int i;
	for(i=0;i<=n-1;i++){

		if((W/dsdv[i].TL)>dsdv[i].SL) dsdv[i].PA=dsdv[i].SL;
		else dsdv[i].PA= W / dsdv[i].TL;; 
		W=W - dsdv[i].PA*dsdv[i].TL;

	}
}


int main(){
	int n;
	float W;
	DoVat *dsdv;
	dsdv = DocFile(&W,&n);
	BB(dsdv,n);
	Gree(dsdv,W,n);
	InDV(dsdv,W,n);

	return 0;
}
