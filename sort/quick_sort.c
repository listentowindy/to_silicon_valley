#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int *arr, int p, int r){//法一 
    int x = arr[r];
    int i = p-1;
    int j = p;
    for(j=p; j<=r-1; j++){
        if(arr[j] < x){
            i = i+1;
            swap(arr+i, arr+j);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

int partion_2(int *arr, int p, int r){//法二 
    int x = arr[p];
    int i = p;
    int j = r+1;
    while(1){
        while( arr[++i] < x && i < r);//
        while(arr[--j] > x);// && j > p);//若要用  arr[--j] >= x，即有等号，必须加上 && j > p， 以防数组越界 
        if( i >= j )
            break;
        swap( arr+i, arr+j);    
    }
    arr[p] = arr[j];
    arr[j] = x;
    return j;
}

void quick_sort(int *arr, int p, int r){
    int q;
    if(p < r){
        q = partion_2(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}


void test_insert_sort(){
	FILE * fin = fopen("input3","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;

	fscanf(fin, "%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("\nbefort quick sort:");
	for(i=0; i<n; i++){
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	quick_sort(arr, 0, n-1);

	printf("\nafter quick sort:");
	for(i=0; i<n; i++){
		printf("%5d", arr[i]);
	}
	printf("\n");	
	return;
}

main(){
	test_insert_sort();
	system("pause");
	exit(0);
}
