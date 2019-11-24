#include <stdio.h>
#include <conio.h>

typedef int keytype;
typedef float ortherkey;

typedef struct
{
	keytype key;
	ortherkey orther;
}recordtype;

void swap(recordtype &a, recordtype &b){
	recordtype temp;
	temp =a;
	a =b;
	b=temp;
}


void BB(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].key<a[j-1].key){
				swap(a[j-1],a[j]);
			}
		}
	}


}

int main(){
	int i,n;

	recordtype a[100];

	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i]);
	}
	BB(a,n);

	printf("sau khgi sap xep\n");
	for(i=0;i<=n;i++){
		printf("%d   ", a[i].key);
	}

	return 0;
}