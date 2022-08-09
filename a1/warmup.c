#include<stdio.h>
/*
 * This program prints the given string a number of times based on the number of iteration given.
 *
 */

void str_to_print(char* str, int num_itt){
	int i;
	
	for(i=0;i<num_itt;i++){
		printf(str);
	}
}

int main(){
	int num_itt;

	num_itt = 3;
	char str[] = "VICTORY!\n";

	str_to_print(str, num_itt);
	return 0;
}

