#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
* 计数排序 
* n:数组长度
* k:数组的元素的范围为[0,k) 
**/
int* CountSort(int *arr, int n, int k) {
    int *count = (int *) malloc(sizeof(int) * k);
    int *b = (int *) malloc(sizeof(int) * n);
    int i;
    
    memset(count, 0, sizeof(int) * k);
    for(i = 0; i < n; i++) {
        count[arr[i]]++; 
    } 
    
    for(i = 1; i < k; i++) {
        count[i] += count[i-1];
    }
    
    for(i = 0; i < n; i++) {
        b[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    free(count);
    return b;
}

void TestCountSort() {
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
	int *sort_arr;
    int i = 0;

	fscanf(fin, "%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("\nbefort count sort:");
	for(i=0; i<n; i++){
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	sort_arr = CountSort(arr, n, 100);
	printf("\nafter count sort:");
	for(i = 0; i < n; i++) {
		printf("%5d", sort_arr[i]);
	}
	printf("\n");
    free(arr);
    free(sort_arr);	
	return;
}

int main()
{
	TestCountSort();
	return 0;
}
