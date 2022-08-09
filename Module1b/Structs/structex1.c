#include<stdio.h>
// Structs are like classes in python

struct student{
	int id;
	int age;
	double creditHours;
};

struct student makeStudent(int id, int age, double creditHours){
	struct student tempStudent;
	tempStudent.id = id;
	tempStudent.age = age;
	tempStudent.creditHours = creditHours;
	return tempStudent;
}

void printStudent(struct student aStudent){
	printf("Student: %d, %d, %f\n", aStudent.id,
					aStudent.age,
					aStudent.creditHours);
}

int main(){
	struct student s1 = makeStudent(1001, 23, 14.5);
	struct student s2 = makeStudent(1002, 24, 15.5);

	printStudent(s1);
	printStudent(s2);

	/*
	struct student s1;
	s1.id = 1001;
	s1.age = 23;
	s1.creditHours = 14.5;

	struct student s2;
	s2.id = 1002;
	s2.age = 24;
	s2.creditHours = 54;

	printf("Student1: %d, %d, %f\n", s1.id, s1.age, s1.creditHours);
	printf("Student2: %d, %d, %f\n", s2.id, s2.age, s2.creditHours);
	*/
	return 0;
}
