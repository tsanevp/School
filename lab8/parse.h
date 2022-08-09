#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PARSE_H
#define PARSE_H

// Parse: A mini parser that is used to parse commands users enter into a shell
// or as input. It can be thought of as an interactive interpreter of a command
// line that performs the REPL actions.


// METHOD DEFINITIONS

// Method to parse through the given string splitting each token at the given delimeter.
//
// INPUT: A string command the user gives us.
// INPUT: The delimeters to split the string at.
void parse(char* string, char* delimeter);

#endif
