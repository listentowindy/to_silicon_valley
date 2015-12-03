#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int start, int medium, int end){
	int left_n = medium - start +1;
	int right_n = end - medium;
	int *left_arr = NULL;
	int *right_arr = NULL;
	int i = start;
	int j = medium + 1;
	int k = start;

	left_arr = (int*)malloc(sizeof(int) * left_n);
	right_arr = (int*)malloc(sizeof(int) * right_n);

	
	for( i = 0, j=start; i < left_n; i++, j++){
		left_arr[i] = arr[j];
	}
	for( i = 0, j = medium+1; i < right_n; i++, j++){
		right_arr[i] = arr[j];
	}

	i = 0;
	j = 0;
	k = start;
	while( k <= end && i < left_n && j < right_n){//Ҫ���� i < left_n && j < right_n
		if( left_arr[i] <= right_arr[j] ){
			arr[k++] = left_arr[i++];
		}else{
			arr[k++] = right_arr[j++];
		}
	}	
	if( i < left_n && j >= right_n){
		while( k<=end ){
			arr[k++] = left_arr[i++];
		}
	}else if( i >= left_n  && j < right_n){
		while( k<=end ){
			arr[k++] = right_arr[j++];
		}
	}
}
void merge_sort(int *arr, int start, int end){
	int medium;
	int i=0;
	
	if( start < end ){
		medium = (start + end)/2;
		merge_sort(arr, start, medium);//排序左半段
		merge_sort(arr, medium+1, end);//排序右半段
		merge(arr, start, medium, end);//合并左右
	} 
}

void test_merge_sort(){
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;

	fscanf(fin, "%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("\nbefort merge sort:");
	for(i=0; i<n; i++){
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	merge_sort(arr, 0, n-1);

	printf("\nafter merge sort:");
	for(i=0; i<n; i++){
		printf("%5d", arr[i]);
	}
	printf("\n");	
	return;
}

main(){
	test_merge_sort();
	system("pause");
	exit(0);
}
