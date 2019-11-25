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

int FindPivot(recordtype a[],int i,int j){
	int k=i+1;
	keytype firstkey=a[i].key;
	//int index = i;
	while(k<=j&& firstkey == a[k].key) k++;
	if(k>j) return -1;
	else if(firstkey<a[k].key) return k;
	else return i;
}
int PhanHoach(recordtype a[],int i,int j,keytype Pivot){

	int L,R;
	L=i;
	R=j;
	while (L<=R){
		while(a[L].key < Pivot) L++;
		while(a[R].key >= Pivot) R--;
		if(L<R){
			swap(a[L],a[R]);
		}
	}	
	return L;

}
// void quick(recordtype a[],int i,int j){
// 	keytype Pivot;
// 	int index;
// 	int k;
// 	index = FindPivot(a,i,j);
// 	printf("\n%d",a[index].key);
// 	while(index != -1){
// 		Pivot = a[index].key;
// 	//	printf("%d\n", Pivot);
// 		k=PhanHoach(a,i,j,Pivot);
// 		quick(a,i,k-1);
// 		quick(a,k,j);
// 	}
// }
void Quick(recordtype a[],int i,int j){
	keytype chot;
	int chotindex,t;
	chotindex = FindPivot(a,i,j);
	if(chotindex!=-1){
		//PhanHoach(a,i,chot);
		chot=a[chotindex].key;
		t=PhanHoach(a,i,j,chot);
		Quick(a,i,t-1);
		Quick(a,t,j);
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
	//NoiBot(a,n);
	printf("sau khi sap xep\n");




	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key);
	}

	Quick(a,0,n-1);
	printf("\nsau khi sap xep\n");




	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key);
	}

	return 0;
}
