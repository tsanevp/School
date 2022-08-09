/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 */

// Simple header file for an example.

#ifndef EXAMPLE1_H
#define EXAMPLE1_H

// Given an integer, returns the squared value of that number.
int SquareNumber(int num);

// Given two integers, returns an integer representing their sum.
int SumTwoNumbers(int num_one, int num_two);

// Given two integers, returns an int representing their product.
int MultiplyTwoNumbers(int num_one, int num_two);

// STEP 3: Add another simple function here of your choice. 
// I recommend trying something other than an int to see 
// how you may use Assert007 for other types. Up to you!
//
// Given two doubles, returns a double representing their difference.
double SubtractTwoNumbers(double num_one, double num_two);

// Given an array, add an int to array.
int* AddNumToArray(int* array, int value);

int StringStartsWith(const char* prefix, const char* string);

#endif  // EXAMPLE1_H
