# Assignment A5

## My Name:
Peter Tsanev

##  Objectives
* Create a custom shell that any user can use.
* The shell successfully parses and stores user input.
* Implement at least three built-in functions to the shell and create a game the user can play.

## Collaboration
For this assignment, I briefly discussed some methods with Lena and Brian in class. Other than that, I did not
collaborate with other students or TAs.

## External Resources Used
* (https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm)
* (https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/)
* (https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program)
* (https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1046380353&id=1044780608)
* (https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-getcwd-get-path-name-working-directory)

## Running my shell
To run my shell, one just needs to make the Makefile. To do so, call `make` and the shell will compile and run.

## Time Spent On Assignment:
Overall, I spent around 12 to 15 hours on this assignment. Once the while loop for the shell itself was running, the
rest of the assignment was pretty simple. I just spent some time understanding processes and implements some of my
built-in functions. Also, quite a while was invested into formatting and making the shell actually look nice.

## What did you like about this assignment?
I really liked the freedom we had to go in any direction with the shell. If I have more time and enery, I probably would
have made my shell a little more intense and implemented cooler built-ins with full functionality, but I kinda burnt out
at the end.

## How could this assignment be improved?
I think this assignment was really fun and useful, and personally, there wasn't much I would change about it.

## My COMMANDS 
BTW FLAGS ARE NOT CURRENTLY IMPLEMENTED INTO MY BUILT-IN COMMANDS.

### My Game Command
My game in the shell is a random number guessing game. A number, 1-15, is randomly generated, and then the game take a
user input that is compared to the random number. The shell user will have three attempts to try and guess the number,
and if they don't, they lose. If the user guesses a number out of range of 1-15 (inclusive), it does not penalize them a
turn and they can go again.

### My History Command
My history built-in function is essentially a doubly linked list that stores all of the past user input commands. It
does not allow the user to remove any commands or add commands to the head of the list. Overall, it is more like a
queue. In the future, I may use the list to implement scrolling through the list with arrow keys to re-call previous
commands.

### Other Commands
All other commands have descriptions in the code... see code.


