#include<stdio.h>

/**
 * Swaps the the last int in arr with the middle element in arr.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - swap_mid_back([1, 2, 3], 3) :: [1, 3, 2]
 * - swap_mid_back([-4, 3, 0, 1], 4) :: [-4, 1, 0, 3]
 *
 * @param arr array of integers
 * @param len length of arr
 */

void swap_mid_back(int* arr, int len){
	int middle_index;
	int temp;
	
	if (len % 2 == 0) {
		middle_index = (len / 2) - 1;
	}
	else {
		middle_index = len / 2;
	}
	
	temp = arr[middle_index];
	arr[middle_index] = arr[len - 1];
	arr[len - 1] = temp;

	int i;
	for(i=0;i<len;i++) {
		printf("The order of the new array is: %d\n", arr[i]);
	}
}

int main(){
	int size = 3;
	int arr[] = {1, 2, 3};

	swap_mid_back(arr, size);
	
	return 0;
}
