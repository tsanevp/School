#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int array[3] = {1, 2, 3};
	double array2[3] = {1.2, 2.2, 4.56};
	char array3[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char array4[] = "Hello world!";
	printf("%s\n", array4);
	printf("%s\n", array3);

	/*array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	*/

	for ( int i = 0; i < 3; i++ ){
		printf("%d\n", array[i]);	
	}
	return 0;
}
