#include<stdio.h>
#include<conio.h>
//quick sort

typedef int keytype;
typedef float orthertype;

typedef struct {
	keytype key;
	orthertype keyfield;
}recordtype;


void swap(recordtype &a, recordtype &b){
	recordtype temp;
	temp =a;
	a=b;
	b=temp;
}
void quicksort(recordtype a[],int n){
	int i,j;

	for(i=0;i<=n-2;i++){
		for(j=i+1;j<=n-1;j++){
			if(a[j].key > a[j-1].key){
				swap(a[j],a[j-1]);
			}
		}
	}
}


int main(){
	int n,i;
	recordtype a[100];
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i]);
	}
	quicksort(a,n);


	printf("sau khi sap xep\n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i].key);
	}
	return 0;
}