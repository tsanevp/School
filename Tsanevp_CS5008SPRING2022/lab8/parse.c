#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void parse(char* string, char* delimeter) {
    char* stringToParse;
    stringToParse = strtok(string, delimeter);

    while (stringToParse != NULL) {
        printf("%s\n", stringToParse);
        stringToParse = strtok(NULL, delimeter);
    }
}

