#include <stdio.h>
#include <conio.h>
//xen

typedef int keytype;
typedef float ordertype;




typedef struct {
	keytype key;
	ordertype feild;

}recordtype;

void swap(recordtype &a,recordtype &b){
	recordtype temp;
	temp = a;
	a= b;
	b=temp;

}

void xen(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		j=i;
		while((j>0)&&(a[j].key < a[j-1].key)){
			swap(a[j],a[j-1]);
			j--;
		}

	}

}

int main(){
	int n,i;
	recordtype a[100];
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	printf("%d\n",n);
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i]);
	}
		for(i=0; i<=n-1; i++){
		printf("%d ",a[i]);
	}	
		printf("\n ");
	xen(a,n);
	printf("Day sau khi sap xep theo kieu Selection_Sort la:\n\n");
	for(i=0; i<=n-1; i++){
		printf("%d ",a[i]);
	}	



	return 0;
}
