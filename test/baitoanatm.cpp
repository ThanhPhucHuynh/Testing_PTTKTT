#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>


typedef struct 
{
	char Ten[25];
	int MG, PA;
}Tien;


void swap(Tien *a,Tien *b){
	Tien temp = *a;
	*a =*b;
	*b = temp;
}
void BB(Tien *dslt,int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(dslt[j].MG >dslt[j-1].MG){
				swap(&dslt[j],&dslt[j-1]);
			}
		}
	}
}


Tien *docfile(int *n){
	Tien *dslt;
	int i=0;
	dslt = (Tien *)malloc(sizeof(Tien));
	FILE *f=fopen("ATM.inp","r");
	while(!feof(f)){
		fscanf(f,"%d",&dslt[i].MG);
		dslt[i].PA=0;
		fgets(dslt[i].Ten,25,f);
		dslt[i].Ten[strlen(dslt[i].Ten)-1]='\0';
		i++;
		dslt = (Tien*) realloc(dslt,sizeof(Tien)*(i+1));
	}
	*n = i;
	fclose(f);
	return dslt;
}
void InTien(Tien *dslt,int n, int TienCanRut){
	int i;
	int tongrut=0;

	printf("|---|-------------------------|---------|---------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|\n","STT","MenhGia","PA","TT");
	//printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", "     Loai tien   ","Menh Gia", "So to","Thanh tien");
	printf("|---|-------------------------|---------|---------|\n");
	for(i=0;i<=n-1;i++){
		printf("|%-3d",i+1);
		printf("|%-25s",dslt[i].Ten);
		printf("|%-9d",dslt[i].PA );
		printf("|%-9d|\n",dslt[i].MG*dslt[i].PA );
		tongrut = tongrut + dslt[i].MG*dslt[i].PA;
	}
	printf("tong rut la : %d\n",tongrut );
}


void gree(Tien *dslt,int n,int tong){
	int i=0;

	while(i<n&&tong>0){
		dslt[i].PA = tong/dslt[i].MG;
		printf("%d\n",dslt[i].MG );
		tong =tong - dslt[i].MG*dslt[i].PA;
		i++;
	}

}


int main(){


	int n;
	Tien *dslt;
	dslt = docfile(&n);
	printf("so n: %d \n",n );
	printf("Nhap sp tien muon rut:\n");
	int Tienmuonrut;
	scanf("%d", &Tienmuonrut);
	BB(dslt,n);
	gree(dslt,n,Tienmuonrut);
	InTien(dslt,n,Tienmuonrut);



	return 0;
}
