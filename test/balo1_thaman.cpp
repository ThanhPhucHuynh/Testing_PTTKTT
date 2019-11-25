#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>


typedef struct {
	char Ten[25];
	float DG,GT,TL;
	int PA;
}DoVat;


void swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp =*a;
	*a = *b;
	*b = temp;
}

void BB(DoVat *dsdv,int n,float W){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>= i+1;j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}


}


DoVat *docfile(float *W,int *n){
	DoVat *dsdv;
	int i=0;
	
	FILE *f;
	f=fopen("CaiBalo1.inp","r");
	//f=fopen("CaiBalo1.inp","r");
	fscanf(f,"%f",W);
	printf("%f\n",*W);
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%f%f",&dsdv[i].TL,&dsdv[i].GT);
		
		dsdv[i].DG = dsdv[i].GT/(float)dsdv[i].TL;
		printf("%f --- %f \n",dsdv[i].TL,dsdv[i].GT);
		fgets(dsdv[i].Ten,25,f);
		dsdv[i].Ten[strlen(dsdv[i].Ten)-1]='\0';
		dsdv[i].PA=0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
		//i++;
	}
	*n = i;
	fclose(f);
	return dsdv;
	
}
DoVat * ReadFromFile(float *W, int *n){
     FILE *f;
     f=fopen("CaiBalo1.INP", "r");
     fscanf(f, "%f",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f,"%f%f",&dsdv[i].TL,&dsdv[i].GT);
	printf("%f --- %f \n",dsdv[i].TL,dsdv[i].GT);
	   fgets(dsdv[i].Ten,20,f);
	   dsdv[i].Ten[strlen(dsdv[i].Ten)-1]= '\0';
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat *)realloc(dsdv, sizeof(DoVat)*(i+1));  
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}




void INDV(DoVat *dsdv,int n,int W){
	int i=0;
	printf("|---|-------------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-9s|%-9s\n","STT","Ten","TL","GT","DG","PA" );
	printf("|---|-------------------------|---------|---------|---------|---------|\n");
	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1);
		printf("|%-25s",dsdv[i].Ten);
		printf("|%-9f", dsdv[i].TL);
		printf("|%-9f", dsdv[i].GT);
		printf("|%-9f", dsdv[i].DG);
		printf("|%-9d|\n",dsdv[i].PA );
	}
	printf("|---|-------------------------|---------|---------|---------|---------|\n");

	printf("\n X( ");
	for(i=0;i<=n-1;i++){
		printf("%d \n",dsdv[i].PA);
	}
	printf(")");
}

void Gree(DoVat *dsdv,int n,int W){
	int i;
	for(i=0;i<=n-1;i++){
		dsdv[i].PA = W/dsdv[i].TL;
		W= W-dsdv[i].PA*dsdv[i].TL;
	}
}

int main(){
	int n;
	float W;
	DoVat *dsdv;
	dsdv = docfile(&W,&n);
	BB(dsdv,n,W);
	Gree(dsdv,n,W);
	INDV(dsdv,n,W);

	return 0;
}









