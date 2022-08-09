#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"

// Given a string, returns the length of the
// string as an int value.
// e.g. if string = "Hello", returns 5.
//
// string: a pointer to a string.
int stringLength(char* string) {
    int i = 0;
    int len = 1;
    
    while(string[i] != '\0') {
        len++;
        i++;
    }
    return len;
}

// Given a name, format the name so that all
// characters are lowercase, except the first.
//  e.g. if first = "PeTER", return "Peter".
//
// name: a pointer to a passed name 
char* formatCase(char* name) {
    int i;
    char ch;
    int lenName = stringLength(name);

    char* a = (char*)calloc(lenName, sizeof(char*));
    
    if (name != NULL) {
        for(i=0; i<lenName; i++) {
            a[i] = tolower(name[i]);
        }
    }
    a[0] = toupper(a[0]);
    return a;
}

// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
void Big(Name *name) {   
    char* first = formatCase(name->first);
    char* last = formatCase(name->last);
        
    if (name->middle == NULL) {
    	printf("%s %s\n", first, last);
	}	
	else
	{
        char* middle = formatCase(name->middle);
        printf("%s %s %s\n", first, middle, last);
        free(middle);
	}
    free(first);
    free(last);
}

// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name) {
	char* first = formatCase(name->first);
    char* last = formatCase(name->last);

    printf("%s, %s\n", last, first);
    free(first);
    free(last);
    
}

// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name) {
    char* first = formatCase(name->first);
    char* last = formatCase(name->last);

    printf("%s %s\n", name->first, name->last);
    free(first);
    free(last);
}

// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name) {
    char* first = formatCase(name->first);
    char* last = formatCase(name->last);

    if (name->middle == NULL)
	{
		printf("%s %s\n", first, last);
	}
	else
	{
        char* middle = formatCase(name->middle);
		printf("%s %c. %s\n", first, middle[0], last);
        free(middle);
	}			 
    free(first);
    free(last);
}

// Print the first name only.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
void Small(Name *name){
    char* first = formatCase(name->first);
    printf("%s\n", first);
    free(first);
}

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// Imported string function "toupper()" to convert case
void FormatName(Name *name, char format){
    format = toupper(format);

    if (format == 'B') {
        Big(name);
    }
    else if (format == 'L') {
        Last(name);
    }
    else if (format == 'R') {
        Reg(name);
    }
    else if (format == 'M') {
        Mid(name);
    }
    else if (format == 'S') {
        Small(name);
    }
    else {
        printf("Invalid format choice");
    }
}

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest) {
    format = toupper(format);
    char* first = formatCase(name->first);
    char* last = formatCase(name->last);
    int fullName;
    int counter = 100; // Defined length of dest

    if (format == 'B') {
        if (name->middle == NULL) {
            fullName = snprintf(dest, counter, "%s %s\n", first, last);
        }
        else {
            char* middle = formatCase(name->middle);
            fullName = snprintf(dest, counter, "%s %s %s\n", first, middle, last);
            free(middle);
        }
     }
     else if (format == 'L') {
         fullName = snprintf(dest, counter, "%s, %s\n", last, first);           
     }
     else if (format == 'R') {
         fullName = snprintf(dest, counter, "%s %s\n", first, last);
     }
     else if (format == 'M') {
         if (name->middle == NULL) {
             fullName = snprintf(dest, counter, "%s %s\n", first, last);
         }
         else {
             char* middle = formatCase(name->middle);
             fullName = snprintf(dest, counter, "%s %c. %s\n", first, middle[0], last);
             free(middle);
        }    
     }
     else if (format == 'S') {
         fullName = snprintf(dest, counter, "%s\n", first);
     }
     else {
         printf("Invalid format choice");
     }
     free(first);
     free(last);
//     free(*counter);
}
