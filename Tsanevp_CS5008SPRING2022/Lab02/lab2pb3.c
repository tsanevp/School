#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * Replaces all digits in a string with a '*'. 
 *
 *
 * Example(s):
 * - redact("The part failed 58% of the time") ::
 *          "The part failed **% of the time"
 * - redact("There were 13 As in the class") :: "There were ** As in the class"
 *
 * @param  str      host string for old_char
 */

void redact(char* str) {
	int len;
	int i;
	int idx;
	char star;
	
	star = '*';
	i = 0;
	while(str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			str[i] = star;
		}
		i++;
	}
	printf(str);
}

int main() {
	char str[] = "The 30000000 parts failed 58 percent of the time 89789789\n";
	redact(str);	

	return 0;
}
