#include<stdio.h>
#include<conio.h>

typedef int keytype;
typedef float ortherkey;

typedef struct{
	keytype key;
	ortherkey orther;

}recordtype;
void swap(recordtypte &a, recordtype &b){
	recordtype temp;
	temp=a;
	a=b;
	b=temp;
}
void selectSort(recordtype a[],int n){
	int i,j;
	int index;
	int lowkey;
	for(i=0;i<=n-2;i++){
		index = i;
		lowkey = a[i].key;
		for(j=i+1;j<=n-1;j++){
			if(a[j].key < lowkey) {
				lowkey = a[j].key;
				index =j;
			}
		}
		swap(a[i],a[index]);
	}


}



int main(){
	int n;
	recordtype a[100];
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&n);
	int i;
	for(i=0;i<=n-1;i++){
		fscanf(f,"%d",&a[i]);
	}


	selectSort(a,n);

	printf("Do thi sau khi sap xep\n");
	for(i=0;i<=n-1;i++){
		printf("%d  ",a[i].key );
	}



	return 0;
}