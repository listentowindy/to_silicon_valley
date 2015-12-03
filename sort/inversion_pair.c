#include<stdio.h>
#include<stdlib.h>

long long reversion_num = 0;

void Merge(int arr[], int temp[], int p, int q, int r) {
    int left = p;
    int right = q+1;
    int k = p;
    while(left <= q && right <= r) {
        if(arr[left] <= arr[right]){
            temp[k++] = arr[left++];
        }else{
            temp[k++] = arr[right++];
            reversion_num = reversion_num + q - left + 1;
        }
    }
    while(left <= q) {
         temp[k++] = arr[left++];
    }
    while(right <= r) {
         temp[k++] = arr[right++];
    }/**/
}

void Copy(int *desc, int *src, int p, int r) {
    int i;
    for(i = p; i <= r; i++) {
        desc[i] = src[i];
    }
}

void MergePass(int arr[], int temp[], int p, int r) {
    int q;
    if( p < r){
        q = (p + r)/2;
        MergePass(arr, temp, p, q);
        MergePass(arr, temp, q+1, r);
        Merge(arr, temp, p, q, r);
        Copy(arr, temp, p, r);
    }
}

void MergeSort(int arr[], int size) {
    int *temp = (int *)malloc(sizeof(int) * size);
    MergePass(arr, temp, 0, size-1);
    free(temp);
}

int main() {
    int n;
    int *arr ;
    int i;
    
	scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    MergeSort(arr, n);
    printf("%lld\n", reversion_num);
    free(arr);
    //printf("%d,%d,%d,%d,%d,%d,%d,%d\n", sizeof(short),sizeof(int),sizeof(long),sizeof(long int),sizeof(long long),sizeof(float),sizeof(double),sizeof(long double));
    return 0;
}

