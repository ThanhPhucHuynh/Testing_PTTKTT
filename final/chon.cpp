#include <stdio.h>
#include <conio.h>




typedef int keytype;
typedef float ortherKey;


typedef struct 
{
	keytype key;
	ortherKey orther;

}recordtype;

void swap(recordtype &a, recordtype &b){
	recordtype temp =a;
	a=b;
	b=temp;
}

void chon(recordtype a[],int n){
	int i,j;
	keytype fristkey;
	int index;
	for(i=0;i<=n-2;i++){
		fristkey = a[i].key;
		index = i;
		for(j=i+1;j<=n-1;j++){
			if(a[j].key < fristkey){
				fristkey = a[j].key;
				index = j;
			}
		}
		
		swap(a[i],a[index]);
	}
}




int main(){
	recordtype a[100];
	int n,i;
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	printf("%d\n",n );
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i].key);
	}
	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key );
	}
	chon(a,n);

	printf("\nday so sau khi sap xep\n");
	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key );
	}

	return 0;
}
