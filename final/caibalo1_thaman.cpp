#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
	char Ten[25];
	float TL,GT,DG;
	int PA,SL;//Phuong An
}DoVat;
void swap(DoVat *a, DoVat *b){
	DoVat temp = *a;
	*a=*b;
	*b = temp;
}
void XapXep(DoVat dsdv[],int n){
	int i,j;
	for(i=0;i<n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}
DoVat * ReadFile(float *w,int *n){
	int i=0;
	DoVat *dsdv;
	dsdv = (DoVat *)malloc(sizeof(DoVat));
	FILE *f=fopen("CaiBalo3.inp","r");
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

void gree(DoVat *dsdv,int n,int w){
	int i;
	printf("%f\n",w);
	for(i=0;i<n;i++){
		dsdv[i].PA= min(w/dsdv[i].TL,1);
		//dsdv[i].PA = w/dsdv[i].TL;

		w =w - dsdv[i].PA*dsdv[i].TL;
		printf("%d\n",dsdv[i].PA );
	}
}

int main(){
	int n;
	float w;
	DoVat *dsdv;
	dsdv= ReadFile(&w,&n);
	XapXep(dsdv,n);
	gree(dsdv,n,w);
	InDV(dsdv,n,w);
	return 0;
}
