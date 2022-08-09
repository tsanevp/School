#include<stdio.h>
#include<string.h>

void update(int* arguement){
            *arguement = 10;
}


void printArray(const char **arry){
    int i = 0;
    printf("%s\n", arry[0]);  
    
    while (i < 3) {
        int j = 0;
        printf("The string is: ");
        while (arry[i][j] != '\0') {
            printf("%c", arry[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

}

int main(){
    int value = 5;
    int* p_value = &value; // use * after type assignment to create a pointer

    update(p_value);
    printf("value is: %d\n", value);
    printf("The address of value is: %p\n", p_value); //hexidecimal value to store memory
    printf("The value at p_value is: %d\n", *p_value); //if star comes before pointer, then it is dereferencing

    *p_value = 15; // was 5 before, now is reassigned to 15
    printf("The updated value at p_value is: %d\n", *p_value);
    printf("Value updated is: %d\n", value);
    
    const char *arry[3];
    arry[0] = "hello";
    arry[1] = "wow";
    arry[2] = "peter";
    printArray(arry);

    return 0;
}

