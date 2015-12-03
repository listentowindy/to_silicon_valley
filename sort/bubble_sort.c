#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
void BubbleSort_1(int *arr, int len){
    int i,j;
    for(i=0; i<len-1; i++){
        for(j=i+1; j<len ;j++){
            if( arr[i] > arr[j] ){
                swap( arr+i, arr+j );
            }
        }
    }
}
*/
void BubbleSort(int *arr, int len) {
    int i,j;
    for(i = 0; i < len; i++ ) {
        for(j = 0; j < len-i-1; j++) {
            if(arr[j] > arr[j+1] ) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}

void TestBubbleSort() {
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;

	fscanf(fin, "%d", &n);
	arr = (int *) malloc(sizeof(int)*n);
	printf("\nbefort bubble sort:");
	for(i = 0; i < n; i++) {
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	BubbleSort(arr, n);

	printf("\nafter bubble sort:");
	for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");
	free(arr);
	return;
}

int main() {
	TestBubbleSort();
	return 0;
}
