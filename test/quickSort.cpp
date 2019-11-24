#include<stdio.h>
#include<conio.h>

typedef int keytype;
typedef float ortherType;

typedef struct 
{
	keytype key;
	ortherType orther;
}recordtype;

void swap(recordtype &a,recordtype &b){
	recordtype temp =a;
	a=b;
	b=temp;
}

int FindChot(recordtype a[],int i,int j){
	keytype firstkey = a[i].key;
	int k = i+1;
	while(k<=j && firstkey==a[k].key) k++;
	if(k>j) return -1;
	else
	if(a[k].key>firstkey) return k;
	else return i;
}
int PhanHoach(recordtype a[],int i,int j,keytype chot){ 
	int L,R;
	L=i;
	R=j;
	while(L<=R){
		while(a[L].key<chot) L++;
		while(a[R].key>=chot) R--;
		if(L<R) swap(a[L],a[R]);
	}
	return L;

}

void Quick(recordtype a[],int i,int j){
	keytype chot;
	int chotindex,t;
	chotindex = FindChot(a,i,j);
	if(chotindex!=-1){
		//PhanHoach(a,i,chot);
		chot=a[chotindex].key;
		t=PhanHoach(a,i,j,chot);
		Quick(a,i,t-1);
		Quick(a,t,j);
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
	// printf("sau khi xap xep");
	// for(i=0;i<=n-1;i++){
	// 	printf("%d  ",a[i].key);
	// }
	 Quick(a,0,n-1);
	printf("sau khi xap xep");
	for(i=0;i<=n-1;i++){
		printf("%d  ",a[i].key);
	}


	return 0;
}