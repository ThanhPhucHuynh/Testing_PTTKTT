#include <stdio.h>
#include <conio.h>



typedef int keytype;
typedef float keyorther;

typedef struct{
	keytype key;
	keyorther orther;
}recordtype;


void swap(recordtype &a, recordtype &b){
	recordtype temp;
	temp = a;
	a=b;
	b=temp;
}

void xen(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		j=i;
		while(j>0&& a[j].key<a[j-1].key){
			//if(a[j].key a[j-1].key){
				swap (a[j],a[j-1]);
				j--;
			//}
		}
	}
}
void NoiBot(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].key<a[j-1].key){
				swap(a[j],a[j-1]);
			}
		}
	}



}

int main(){
	recordtype a[100];
	int i,n;
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i].key);
	}
	//xen(a,n);
	NoiBot(a,n);
	printf("sau khi sap xep\n");

	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key);
	}

	return 0;
}