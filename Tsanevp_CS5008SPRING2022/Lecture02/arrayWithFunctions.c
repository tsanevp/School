#include<stdio.h>

void populate(int arr[], int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = i;
	}
	// return arr;
}

void printValues(int arr[]){

}
int main(){
	int size = 10;
	int arr[size];

	populate(arr, size)
	return 0;
}
