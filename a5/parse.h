#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PARSE_H
#define PARSE_H

// Parse: A parser that is used within a custom shell to parse commands users
// enter on the shell command line. It stores each parsed token in an arguments
// array that is later used to evaluate which, if valid, command to call.

// METHOD DEFINITIONS

// Method to parse through the given string commad, splitting each token at the
// given delimeter and storing each token in an argv[] array.
//
// INPUT: A string command the user gives us in the shell command line.
// INPUT: The delimeters to split the string at.
// INPUT: Array to store each token in.
int parse(char* string, char* delimeter, char** argv);

#endif
