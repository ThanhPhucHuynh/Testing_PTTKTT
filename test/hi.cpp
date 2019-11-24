#include <stdio.h>

/*Khai bao*/
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
} recordtype;

/*Doi cho*/
void Swap(recordtype &x, recordtype &y){
	recordtype temp;
	temp = x;
	x = y;
	y = temp;
}

/*Selection Sort*/

void SelectionSort(recordtype a[], int n){
	int i,j, lowindex;
	keytype lowkey;
	for (i=0; i<=n-2; i++){
		lowkey = a[i].key;
		lowindex = i;
		for (j=i+1; j<=n-1; j++){
			if (a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(a[i],a[lowindex]);
	}
}

main(){
	int n,i;
	recordtype a[100];
	
	FILE* file = fopen("dayso.inp", "r");
	fscanf(file, "%d",&n);
	for (i = 0; i <= n-1; i++) {
		fscanf(file, "%d", &a[i]);
	}
	
	SelectionSort(a,n);
	
	printf("Day sau khi sap xep theo kieu Selection_Sort la:\n\n");
	for(i=0; i<=n-1; i++){
		printf("%d ",a[i]);
	}
}
