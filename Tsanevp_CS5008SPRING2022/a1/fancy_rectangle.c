#include<stdio.h>
/*
 * This program prints an empty rectangle of the specified width and height if the fill value is 0, and a non-empty rectanngle if the fill value is 1.
 *
 */

void PrintFancyRectangle(int width, int height, char symbol, int fill){
	int i;
	
	for(i=1; i<=height; i++){
		if(((i==1) || (i==height)) || (fill == 1)){
			int j;
			for(j=1;j<=width;j++){
				printf("%c", symbol);
			}
			printf("\n");
		}
		else{
			int x;
			for(x=1;x<=width;x++){
				if((x==1) || (x==width)){
					printf("%c", symbol);
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
	char symbol = '^';
	int fill = 0;
	
	if((fill != 0) && (fill != 1)){
		printf("Invalid fill option\n");
	}
	else{
		PrintFancyRectangle(width, height, symbol, fill);
	}
	return 0;
}
