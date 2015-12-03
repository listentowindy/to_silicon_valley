#include<stdio.h>
#include<stdlib.h>

void InsertSort(int *arr, int length) {
	int i = 0;
	int j = 0;
	int key;

	for(i = 1; i < length; i++) {
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}


void TestInsertSort() {
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;

	fscanf(fin, "%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	printf("\nbefort insert sort:");
	for(i = 0; i < n; i++) {
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	InsertSort(arr, n);

	printf("\nafter insert sort:");
	for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");	
	return;
}

int main() {
	TestInsertSort();
	return 0;
}
