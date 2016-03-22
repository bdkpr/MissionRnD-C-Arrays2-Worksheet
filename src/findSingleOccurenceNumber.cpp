/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>
int max_in_A(int *, int);

int findSingleOccurenceNumber(int *A, int len) {
	if (A==NULL||len<0)
		return -1;
	int ind,max=max_in_A(A, len);	//max no.in the array
	if (max == -1)
		return -1;
	int *repeat_arr = (int *)malloc(max*sizeof(int));
	for (ind = 0; ind <= max; ind++){
		repeat_arr[ind] = 0;
	}
	for (ind = 0; ind < len; ind++){		//counting the no.of times no. is repeated
		repeat_arr[A[ind]]++;
	}
	for (ind = 0; ind <= max; ind++){
		if (repeat_arr[A[ind]] == 1){
			return A[ind];
		}
	}
	return -1;
}
int max_in_A(int *arr, int len){
	int i, max = arr[0];
	for (i = 1; i < len; i++){
		if (arr[i] >= 0){
			if (max < arr[i]){
				max = arr[i];
			}
		}
		else{
			return -1;
		}
	}
	return max;
}