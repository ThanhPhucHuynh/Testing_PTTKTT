#include <stdio.h>
#include <conio.h>


typedef int keytype;
typedef float ortherkey;


typedef struct 
{
	keytype key;
	ortherkey orther;

}recordtype;

void swap(recordtype &a,recordtype &b){
	recordtype temp;
	temp =a ;
	a =b;
	b=temp;
}

void chon(recordtype a[],int n){
	int i;
	keytype lowkey;
	int lowindex,j;
	for(i=0;i<=n-2;i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j=i+1;j<=n-1;j++){
			if(a[j].key<lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		swap(a[i],a[lowindex]);
	}


}

void xen(recordtype a[],int n){
	int i,j;

	for(i=0;i<=n-1;i++){
		j=i;
		while(j>0&& a[j].key<a[j-1].key){
			swap(a[j],a[j-1]);
			j--;
		}
	}


}






int main(){

	recordtype a[100];
	int n,i;
	FILE *f;
	f=fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i].key);
	}
	xen(a,n);
	printf("day so sau khi sap xep xen\n");
	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key);
		//fscanf(f,"%f",&a[i].key);
	}
	return 0;
}


