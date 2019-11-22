#include <stdio.h>
#include <conio.h>
//chon

typedef int keytype;
typedef float otherkey;
typedef struct {
	keytype key;
	otherkey keyfield;
} recordtype;

void swap(recordtype &a,recordtype &b){
	recordtype temp;
	temp = a;
	a=b;
	b =temp;
}

void chon(recordtype a[],int n){
	int i,j,index;
	recordtype lowkey;
	for(i=0;i<n-2;i++){
		index=i;
		lowkey = a[i];
		for(j=i+1;j<=n-1;j++){
			if(a[j].key < lowkey.key){
				lowkey = a[j];
				index=j;
			}
		}
		swap(a[index],a[i]);
	}

}

int main(){
	recordtype a[100];
	int n,i;
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	for (int i = 0; i <=n-1; ++i)
	{
		fscanf(f,"%d",&a[i]);
	}

	chon(a,n);

	printf("chuoi sau khi sap xep\n");
	for (int i = 0; i <=n-1; ++i)
	{
		printf("%d ",a[i].key );
	}
	return 0;

}



