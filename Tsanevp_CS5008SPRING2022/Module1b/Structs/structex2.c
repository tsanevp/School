#include<stdio.h>

typedef struct student{
	int id;
	int age;
}student_t;

void printStudent(student_t* aStudent){
	printf("Student ID: %d, Age: %d\n", aStudent->id, (*aStudent).age); //can use an arrow instead of * and .
}

void updateStudent(student_t* aStudent, int age, int id){
	(*aStudent).age = age;
	(*aStudent).id = id;
}

int main(){
	student_t s1;
	student_t s2;

	// Lets assign some values to s1 and s2;
	updateStudent(&s1, 23, 1001);
	updateStudent(&s2, 24, 1002);

	printStudent(&s1);
	printStudent(&s2);

	updateStudent(&s2, s2.age, 1004);
	printStudent(&s2);

	return 0;
}
