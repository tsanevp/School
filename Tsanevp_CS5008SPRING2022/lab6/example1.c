/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 */

#include <stdio.h>

#include "example1.h"
#include "Assert007.h"

// Given a non-zero integer, returns the squared value of that numbers.:
int SquareNumber(int num) {
    Assert007(num != 0);
    return (num * num);
}

// Given two non-zero integers, returns an int representing their sum.
int SumTwoNumbers(int first, int second) {
    Assert007(first != 0);
    Assert007(second != 0);
    return (first + second);
}

// Given two non-zero integers, returns an int representing their product.
int MultiplyTwoNumbers(int first, int second) {
    Assert007(first != 0);
    Assert007(second != 0);
    return (first * second);
}

// STEP 4: Implement your additional function here. 
// Add a helpful Assert007 call that would set a breakpoint 
// in your code (e.g. if your function takes a char* type, 
// then check that this is not NULL)
//
// Given two non-zero doubles, returns a double representing their difference.
double SubtractTwoNumbers(double num_one, double num_two) {
    Assert007(num_one != 0.0);
    Assert007(num_two != 0.0);
    return (num_one - num_two);

}

// Given an array, add an int to array.
int* AddNumToArray(int* array, int value) {
    Assert007(array != NULL);
    int newArray[sizeof(array)];
    int i = 0;
    for (i; i < sizeof(array); i++) {
        newArray[i] = array[i];
    }
    newArray[sizeof(array)] = value;
    return newArray;
}

int StringStartsWith(const char* prefix, const char* string) {
  Assert007(prefix != NULL);
  Assert007(string != NULL);

  int i = 0;
  
  while (prefix[i] != '\0') {
    // Make sure the string is longer than the prefix
    Assert007(string[i] != '\0');
    if (prefix[i] != string[i]) {
      return 0; // FALSE 
    }

    i++; 
  }

  return 1; 
  
}

