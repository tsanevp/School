# Assignment 1 Directory
## This assignment contains the following files:
- warmup.c
- rectangle.c
- fancy_rectangle.c
## How to run each file & file descriptions:
### warmup.c
This probelm already includes the example "VICTORY!" statement in its main function. If the user wants to adjust the number of times the string is prints, the option is there. The statement to print can also be adjusted. To run the code, the file can be complied and ran.

### rectangle.c
This probelm allows the user easily adjust the width and height of the empty rectangle. Once the desired width and height are set, the code can be compiled and ran and the rectangle will be printed in the terminal.

### fancy_rectangle.c
This program allows the user to adjust the width, height, symbol, and fill of the rectangle that will be printed in the terminal. Once all the desired parameters have been adjusted by the current user, the file can be compiled and ran.
## Example Input/Outputs:
### warmup.c:
void str_to_print(char* str, int num_itt) <br />
Sample Output: <br />
str_to_print("VICTORY!\n", 3) <br />
VICTORY!\
VICTORY!\
VICTORY!
### rectangle.c
void PrintRectangle(int width, int height) <br />
Sample Output: <br />
PrintRectangle(5, 4) <br />
<pre>
$$$$$ <br />
$   $ <br />
$   $ <br />
$$$$$ <br />
*Note that in the assignment, dash characters '-' are used instead of '$' characters
</pre>
### fancy_rectangle.c
void PrintFancyRectangle(int width, int height, char symbol, int fill) <br />
Sample Output: <br />
PrintFancyRectangle(5, 4, %, 1) <br />
<pre>
%%%%% <br />
%%%%% <br />
%%%%% <br />
%%%%%
</pre>
## External Libraries:
None were used for this assignment.
## Assumptions Made:
- All constants and variables used in each file are valid inputs.
- No negative values are used for any int variables.
## Time Spent On Assignment:
I spent around three hours on the assignment. The first problem was a piece of cake, while the second and third were a tad tricky. I was originally trying to find a shortcut for creating/printing the square in pb2/pb3 that did not use a for loop, but soon gave up. Once I implemented the nested for loops, the problems were simple.

