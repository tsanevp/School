#include<stdio.h>
/*
 * This program prints an empty rectangle of the specified width and height.
 *
 */

void PrintRectangle(int width, int height){
	char dash = '-';
	int i;
	
	for(i=1; i<=height; i++){
		if((i==1) || (i==height)){
			int j;
			for(j=1;j<=width;j++){
				printf("%c", dash);
			}
			printf("\n");
		}
		else{
			int x;
			for(x=1;x<=width;x++){
				if((x==1) || (x==width)){
					printf("%c", dash);
				}
				else{
					printf(" ");
				}
			}	
		printf("\n");
		}
	}
}

int main(){
	int width = 5;
	int height = 4;

	PrintRectangle(width, height);
	return 0;
}
