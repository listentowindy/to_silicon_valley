#include <stdio.h>
#include <stdlib.h>
int number = 0; 
void mergePass(int  *, int  *, int, int);
void merge(int *, int *, int, int, int);
void copy(int  *dest, int  *src, int l, int r)
{
    while(l <= r)
    {
        dest[l] = src[l];
        l++;
    }
}
void mergeSort(int  *a, int size)
{
    int  *b = (int *)malloc(sizeof(int ) * size);
    mergePass(a, b, 0, size - 1);
    free(b);
}


void mergePass(int  *a, int  *b, int l, int r)
{
    int m;
    if(l < r)
    {
        m = (l + r) / 2;
        mergePass(a,b,l,m);
        mergePass(a,b,m+1,r);
        merge(a,b,l,m,r);
        copy(a,b,l,r);

    }
}

void merge(int  *a, int  *b, int l, int m, int r)
{
    int i = l, j = m + 1;
    while( i <= m && j <= r)
    {
        if(a[i] <= a[j])
            b[l++] = a[i++];
        else
        {
            b[l++] = a[j++];
            number += m-i+1;
        }
    }
    while(i <= m)
        b[l++] = a[i++];
    while(j <= r)
        b[l++] = a[j++];
}


int main()
{    
    int n = 5;
    int *arr ; 
    int i;
 
    scanf("%d", &n);
    arr = (int*)malloc( sizeof(int) * n);
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    
    mergeSort(arr, n);
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("%d\n", number);
	printf("%d,---%d\n", sizeof(int), sizeof(int));
	system("pause");
    free(arr);
    return 0;
}
