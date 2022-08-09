# Assignment A2 Objectives
* Start working with `structs` and header files.
* Doing more advanced things with `strings`.
* Work with functions and function prototypes.

## Summary/Overview
In this assignment, we started playing around with `structs`, `strings`, and header files. We were given the following files: a2.h, a2.c, a2_test.c, and Makefile. The purpose and definition of each is:
* a2.h - A header file that defines the struct Name, and its functions. Name is a struct that take a persons first, middle, and last name as an input.
* a2.c - A c file that implements Name and defines the object functions. The purpose of a2.c is to format the Name object to some desired format. 
* a2_test.c - A test file that defines multiple Name objects, and then calls them in main.
* Makefile - A make file that builds `a2.c a2.h a2_test.c` and runs `gcc a2.c a2_test.c -g -o a2`. After running, it also runs `rm a2`, which removes a2 from the directory.

The assignment also had us get more familar with pointers. To do so, we created a pointers.c file to experiment with various pointer methods. That file is `pointer.c` and includes a main function to test and code with the c file.
### About struct Name
The struct Name takes first name, middle name, and last name as parameters. These are the functions found within a2.c:
* stringLength, formatCase, Big, Last, Reg, Mid, Small, FormatName, FillName.
Each function definition is below along with an example.
* stringLength - Given a string input, returns the length of that string as an interger.
* formatCase - Given a string, returns a newly formatted string so that all letter but the first are lowercase.
* Big - Prints the name <first> <middle> <last>. e.g. if first = "Ben", middle = "Ivan", and last = "Bitdiddle, then print: "Ben Ivan Bitdiddle". If the middle name is `NULL`, only prints "Ben Bitdiddle".
* Last - Prints the string <last>, <first>. e.g. if first = "Ben:, middle = "Ivan", and last = "Bitdiddle", then print "Bitdiddle, Ben".
* Reg - Print the string <first> <last>. e.g. if first = "Ben:, middle = "Ivan", and last = "Bitdiddle", then print "Ben Bitdiddle".
* Mid - Print the string <first> <middle-initial>. <last>. e.g. if first = "Ben:, middle = "Ivan", and last = "Bitdiddle", then print "Ben I. Bitdiddle". If the middle name is `NULL`, then only prints "Ben Bitdiddle".
* Small - Print the first name only. e.g. if first = "Ben:, middle = "Ivan", and last = "Bitdiddle", then print "Ben".
* Formatname - Lets the user decide which formatting option to apply on a given name and prints result. e.g. given some name, if a user input they wish to use format option 'b', Big(Name) would get applied.
* FillName - The same as FormatName, except instead of printing the new name, stores it in an array name Dest.

### About pointer.c
This is just a c file where we messed around with pointers to gain some confidence in using them.

### About The Code
The code does not reley on any external libraries except <stdio.h>, <stdlib.h>, and <time.h>. All three libraries were already imported for us.

## Running and testing a2.c
To test the functionality of a2.c, you first need to open a2_test.c and define Name objects to be ran within mainand call a2.c. Once the desiered objects that will sufficiently test a2.c have been defined, you are ready to build and run a2.c. To do so, run `make -f Makefile` in your command line. This will run the Makefile, which builds `a2.c a2.h a2_test.c` and runs `gcc a2.c a2_test.c -g -o a2`. After running, it also runs `rm a2`, which removes a2 from the directory.

## Assumptions Made:
- Since a magic number is used to define the size of Dest, we can assign the same size to Dest when defining snprintf in a2.c FillName.

## Time Spent On Assignment:
I spent a little more time that I originally would have thought on this assignment. In total, I spent around 15 hours on it. I completed each function in about 4ish hours, but after that, I worked on trying to define helper functions to simplfy the orignal functions. I ran into troubles when it came to defining an array of strings and then returning it, and also finding the true size of dest.
