#include<stdio.h>

/**
 * Write a function that replaces all numbers greater
 * than ceiling in arr with ceiling.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - crop_hi([1, 2, 3, 4], 4, 2) :: [1, 2, 2, 2]
 * - crop_hi([-3, 17,  7, -12, 10], 5, 8) :: [-3, 8, 7, -12, 8]
 *
 * @param arr     array of integers
 * @param len     length of arr
 * @param ceiling upper limit for ints in array
 */
void crop_hi(int* arr, int len, int ceiling){
	int i;
	
	for(i=0; i<len; i++) {
		if (arr[i] > ceiling) {
			arr[i] = ceiling;
		}
	}

	int j;

	for(j=0; j<len; j++) {
		printf("the array value is %d\n", arr[j]);
	}
}


int main(){
        int size = 4;
	int arr[] = {1, 2, 3, 4};
	int ceiling = 2;
	
	crop_hi(arr, size, ceiling);

        return 0;
}

