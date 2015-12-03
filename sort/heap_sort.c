#include<stdio.h>
#include<stdlib.h>

#define LEFT(i)  ((i<<1) + 1) //因为根结点的下标从0开始，故左孩子为2*i+1,右孩子为2*i+2 
#define RIGHT(i) ((i<<1) + 2)

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
*调整以i为根结点的子树为最大堆
**/
void MaxHeap(int *arr, int len, int i) {//
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    
    if(left < len && arr[i] < arr[left]) {
        largest = left;    
    }
    if(right < len && arr[largest] < arr[right]) {
        largest = right;
    } 
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        MaxHeap(arr, len, largest);
    }
}

void BuildMaxHeap(int *arr, int len) {
    int heap_size = len;//堆大小
    int i;
    for(i = heap_size/2; i >= 0; i--){
        MaxHeap(arr, len, i);
    }
} 

void HeapSort(int *arr, int len) {
    int heap_size = len;
    int i;
    BuildMaxHeap(arr, heap_size);
    printf("\n%d\n", arr[0]);

    for(i = heap_size-1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heap_size--;
        MaxHeap(arr, heap_size, 0);
    }
}

void TestHeapSort() {
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

	HeapSort(arr, n);

	printf("\nafter insert sort:");
	for(i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");	
	return;
}

int main()
{
    int a = 10, b = 20;
	TestHeapSort();
	return 0;
}
