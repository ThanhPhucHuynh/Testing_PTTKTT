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
int findchot(recordtype a[],int i,int j){
	keytype keyfrist;
	int k;
	k=i+1;
	keyfrist = a[i].key;
	while(k<=j&&(a[k].key == keyfrist)) k++;
	if(k>j) return -1;
	if(a[k].key < keyfrist) return k;
	return i;
}
int phanhoach(recordtype a[],int i,int j,keytype pivot){
	int R,L;
	L=i;
	R=j;
	while(L<=R){
		while(a[L].key<=pivot) L++;
		while(a[R].key > pivot) R--;
		if(L<R) swap(a[L],a[R]);
	}
	return L;
}


void quicksort(recordtype a[],int i,int j){
	keytype pivot;
	int index,k;
	index=findchot(a,i,j);
	if(index != -1){
		pivot=a[index].key;
		k=phanhoach(a,i,j,pivot);
		quicksort(a,i,k-1);
		quicksort(a,k,j);
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
	quicksort(a,0,n-1);


	printf("sau khi sap xep\n");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i].key);
	}
	return 0;
}