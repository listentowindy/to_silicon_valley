#include<stdio.h>
#include "mylib.h"

void test_shuffle(){
	FILE * fin = fopen("input","r");
	int n = 0;
	int *arr = NULL;
    int i = 0;

    assert( fin != NULL );
	fscanf(fin, "%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	printf("\nbefort shuffle:");
	for(i=0; i<n; i++){
		fscanf(fin, "%d", arr+i);
		printf("%5d", arr[i]);
	}

	shuffle(arr, n);

	printf("\nafter shuffle:");
	for(i=0; i<n; i++){
		printf("%5d", arr[i]);
	}
	printf("\n");	
	return;
}

main(){
    int i;
    srand((int)time(0));

	test_shuffle();
	system("pause");
	exit(0);
}
