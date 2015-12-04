#include<stdio.h>
#include "mylib.h"

int RandomPartition(int *arr, int p, int r){
    int i = random_val(p, r+1);
    swap(arr+i, arr+r);
    return partion(arr, p, r);
}

int RandomSelect(int *arr, int p, int r, int i) {
    int q;
    int k;
    if(p == r) {
        return p;
    }
    q = RandomPartition(arr, p,  r);
    k = q - p + 1;
    if(i == k){
		return q;
    }else if(i < k){
        return RandomSelect(arr, p, q-1, i);
    }else{
        return RandomSelect(arr, q+1, r, i-k);
    }
}

void TestSelectI() {
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;
    int index;

	fscanf(fin, "%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++) {
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

    printf("\narray:");
    Shuffle(arr, n);
    for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	index = RandomSelect(arr, 0, n-1, 3);
    printf("\n3=>位置%d，值：%d\n", index, arr[index]);
    
    printf("\narray:");
    Shuffle(arr, n);
    for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	index = RandomSelect(arr, 0, n-1, 1);
    printf("\n1=>位置%d，值：%d\n", index, arr[index]);
    
    printf("\narray:");
    Shuffle(arr, n);
    for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	index = RandomSelect(arr, 0, n-1, n);
    printf("\n%d=>位置%d，值：%d\n", n, index, arr[index]);

    printf("\narray:");
    Shuffle(arr, n);
    for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	index = RandomSelect(arr, 0, n-1, n-4+1);
    printf("\n第%d大的元素=>位置%d，值：%d\n", 4, index, arr[index]);
    QuickSort(arr, index+1, n-1);
    printf("4个最大的元素为：");
    for(i = index; i < n; i++) {
        printf("%5d", arr[i]);
    }
    
	printf("\n");
    free( arr );	
	return;
}

int main() {
    srand((int)time(0));
	TestSelectI();
	return 0;
}
