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

void chon(recordtype a[],int n){
	keytype lowkey;
	int lowindex;
	int i,j;
	for(i=0;i<n-2;i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j=i+1;j<=n-1;j++){
			if(a[j].key < lowkey){
				lowkey =a[j].key;
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
		while(j>0&&a[j].key < a[j-1].key){
			swap(a[j],a[j-1]);
			j--;
		}
	}
}
void bb(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].key < a[j-1].key){
				swap(a[j],a[j-1]);
			}
		}
	}
}

//quicksort


int FindPivot(recordtype a[],int i,int j){
	int k=i+1;
	keytype fristKey = a[i].key;
	int index;
	while(k<=j&&a[k].key==fristKey) k++;
	if(k>j) return -1;
	else if(a[k].key> fristKey) return k;
	else return i;
}
int PhanHoach(recordtype a[],int i,int j,keytype Pivot){
	int L,R;
	L=i;
	R=j;
	while(L<=R){
		while(a[L].key<Pivot) L++;
		while(a[R].key >= Pivot) R--;
		if(L<R){
			swap(a[L],a[R]);
		}
	}
	return L;
}
void Qiucksort(recordtype a[],int i,int j){
	int index,k;
	keytype fristKey;
	index = FindPivot(a,i,j);
	if(index!=-1){
		fristKey = a[index].key;
		k=PhanHoach(a,i,j,fristKey);
		Qiucksort(a,i,k-1);
		Qiucksort(a,k,j);
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
	//bb(a,n);
	Qiucksort(a,0,n-1);
	printf("sau khi sap xep\n");

	for(i=0;i<=n-1;i++){
		printf("%d   ",a[i].key);
	}

	return 0;
}