#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "parse.h"
define MAX_BUFFER 84

int main() {
    printf("Enter the command: ");
    char string[MAX_BUFFER];
    fgets(string, MAX_BUFFER, stdin);
    parse(string, " ");

    return 0;
}

