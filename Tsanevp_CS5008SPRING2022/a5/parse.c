#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_ARGV 5

// Method to parse the command entered on the shell and store it in argv
int parse(char* buf, char* delimeter, char** argv) {
    char* token;
    token = strtok(buf, delimeter);
    int i = 0;
    while (token != NULL) {
        // If the number of tokens reaches six, return error
        if (i == MAX_ARGV) {
            return 0;
        }
        // Otherwise store token in argv
        argv[i] = token;
        token = strtok(NULL, delimeter);
        i++;
    }

    // Replace any empty indicies with NULL
    for (i ; i < sizeof(argv); i++) {
        argv[i] = NULL;
    }
}

