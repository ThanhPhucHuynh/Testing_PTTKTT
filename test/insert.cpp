#include<stdio.h>
#include<conio.h>


typedef int keytype;
typedef float ortherKey;

typedef struct 
{
	keytype key;
	ortherKey orther;
}recordtype;

void swap(recordtype &a, recordtype &b){
	recordtype temp;
	temp = a;
	a=b;
	b=temp;
}


void Insert(recordtype a[],int n){
	int i,j;

	for(i=0;i<=n-1;i++){
		j=i;
		while(j>0 && a[j].key < a[j-1].key){
			swap(a[j],a[j-1]);
			j--;
		}

	}


}
int main(){

	int n;
	int i;
	recordtype a[100];
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	printf("%d",n);
	for(i=0;i<=n-1;i++){
	
		fscanf(f,"%d",&a[i]);
	}
	// for ( i = 0; i <= n-1; i++)
	// {
	// 	printf("%d ",a[i].key);
	// }
	Insert(a,n);

	printf("do thi sau khi sap xep \n");
	for ( i = 0; i <= n-1; i++)
	{
		printf("%d ",a[i].key);
	}
	

	return 0;
}