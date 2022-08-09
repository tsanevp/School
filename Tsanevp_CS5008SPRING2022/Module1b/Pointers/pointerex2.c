#include<stdio.h>

void update(int* arguement){
        *arguement = 10;
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
        return 0;
}

