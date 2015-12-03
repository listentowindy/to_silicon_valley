#ifndef MYLIB_H_
#define MYLIB_H_

#include<stdlib.h>
#include <assert.h>
#include<time.h>

#define LEFT(i)  ((i<<1) + 1) //??Ϊ?????????±???0??ʼ??????????Ϊ2*i+1,?Һ???Ϊ2*i+2 
#define RIGHT(i) ((i<<1) + 2)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//ʹ?ñ?????ǰ?????ȵ??? srand((int)time(0)); ??????????????
//???? [a,b) ֮?????????? 
int random( int a, int b){
     assert( a <= b);
     return ( rand()%(b-a) + a );
}

//???? 
void Shuffle(int *arr, int len){
    int i;
    for(i=0; i<len; i++){
        swap( arr+i, arr+random(i,len) );
    }
}

//???????? 
void insert_sort(int *arr, int length){
	int i=0;
	int j=0;
	int key;

	for(i=1; i<length; i++){
		key = arr[i];
		j = i-1;
		while( j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}


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
	while( k <= end && i < left_n && j < right_n){//Ҫ???? i < left_n && j < right_n
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
//?ϲ????? 
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


/**
*??????iΪ????????????Ϊ??????
**/
void max_heap(int *arr, int len, int i){//
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;
    
    if( left < len && arr[i] < arr[left] ){
        largest = left;    
    }
    if( right < len && arr[largest] < arr[right] ){
        largest = right;
    } 
    if( largest != i){
        swap( &arr[i], &arr[largest]);
        max_heap(arr, len, largest);
    }
}

void build_max_heap(int *arr, int len){
    int heap_size = len;//?Ѵ?С
    int i;
    for(i=heap_size/2; i>=0; i--){
        max_heap(arr, len, i);
    }
} 
//?????? 
void heap_sort(int *arr, int len){
    int heap_size = len;
    int i;
    build_max_heap(arr, heap_size);
    printf("\n%d\n", arr[0]);

    for(i=heap_size-1; i>=1; i--){
        swap(&arr[0], &arr[i]);
        heap_size--;
        max_heap(arr, heap_size, 0);
    }
}

int partion(int *arr, int p, int r){//??һ 
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

int partion_2(int *arr, int p, int r){//???? 
    int x = arr[p];
    int i = p;
    int j = r+1;
    while(1){
        while( arr[++i] < x && i < r);//
        while(arr[--j] > x && j > p);//??Ҫ??  arr[--j] >= x?????еȺţ????????? && j > p?? ?Է?????Խ?? 
        if( i >= j )
            break;
        swap( arr+i, arr+j);    
    }
    arr[p] = arr[j];
    arr[j] = x;
    return j;
}
//???????? 
void QuickSort(int *arr, int p, int r){
    int q;
    if(p < r){
        q = partion(arr, p, r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q+1, r);
    }
}

/* 
int random_partition(int *arr, int p, int r){
    int i = random(p, r+1);
    swap(arr+i, arr+r);
    return partion(arr, p, r);
}

//????ʱ??ѡ?? ??iС ??Ԫ?? 
int random_select(int *arr, int p, int r, int i){
    int q;
    int k;
    if(p==r){
        return p;
    }
    q = random_partition(arr, p,  r);
    k = q-p+1;
    if( i == k){
        return q;
    }else if(i < k){
        return random_select(arr, p, q-1, i);
    }else{
        return random_select(arr, q+1, r, i-k);
    }
}*/

#endif //MYLIB_H_
