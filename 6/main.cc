/*************************************************************************
 * File Name:    main.cc
 * Author:       aeolus
 * Mail:         hongchunxiao@gmail.com
 * Created  Time: 2015/12/01 22:16:07 (Tuesday December)
 * Modified Time: 2015/12/01 22:16:07 (Tuesday December)
 * 
 * Description:
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int MaxIndexDistance(int arr [], int n)
{
	if (arr == NULL || n < 2) return 0;

	bool *in_desc_seq = new bool[n];
	int min = arr[0];
	in_desc_seq[0] = true;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			in_desc_seq[i] = true;
		}
	}
	
	int max_index_distance = 0;
	int i = n-1, j = n-1;
	while (i >= 0) {
		while (in_desc_seq[i] == false) { //in_desc_seq[0] = true, so it don't need to check i >= 0
			i--;
		}

		while (arr[j] <= arr[i] && j > i) {
			j--;
		}

		max_index_distance = max(j-i, max_index_distance);
		i--;
	}

	delete [] in_desc_seq;
	return max_index_distance;
}

void test(int arr[], int n, int exp)
{
	cout << "max_index_distance of {";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "} = " << MaxIndexDistance(arr, n) << endl;
	assert(MaxIndexDistance(arr, n) == exp);
}

int main()
{
	int arr1[6] = {5, 3, 4, 0, 1, 4};
	test(arr1, 6, 4);
	
	int arr2[6] = {5, 3, 4, 3, 3, 3};
	test(arr2, 6, 1);

	int arr3[6] = {5, 3, 4, 1, 3, 7};
	test(arr3, 6, 5);
	return 0;
}
