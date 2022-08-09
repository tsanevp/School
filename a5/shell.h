#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#ifndef SHELL_H
#define SHELL_H

// -------------------------------------------------------------------------- //
// The following declared method signitures represent the commands that are
// built-in to the custom shell. Each command and its function is derived from
// the UNIX built-in commands, and should have similar functionality.
// -------------------------------------------------------------------------- //

/*
 * Method to reset the shell and its formatting colors, destory the defined
 * linked list that is used to store command line inputs, and after exit the
 * program itself.
 */
void resetShellFormat();

/*
 * Method to obtain and return the username of the current shell user.
 *
 * INPUT: A char array to store the username in.
 * RETURN: The username of the current shell user.
 */
char* getUser(char* username);

/*
 * Method to change the current directory to the relative path given. Has the
 * ability to traverse up or traverse down directories, depending on the path
 * the shell user gives. If only "cd" is passed as the only command, the
 * current directory will always be moved to the current users home directory,
 * defined as: "/home/$USERNAME".
 *
 * INPUT: A string input representing the arguements to pass to the cd command.
 *        The input, if valid, should be the relative directory path to move to.
 */ 
void* cd(char* input);


/*
 * Method to view the past user inputs on the command line.
 */ 
void* history();

/*
 * Method to get the current directory path the user is in.
 */
void* pwd();

/*
 * Method to clear the current shell screen and move the command line to the
 * top of the window.
 */
void* clear();

/*
 * Method to print the contents of the directory path passed as an arguement.
 * If no relative path is given, gets the contents of the current directory.
 *
 * INPUT: A string input representing the arguements to pass to the ls command.
 *        The input, if valid, should be a relative directory path whose
 *        contents should be printed.
 */
void* ls(char* input);

/*
 * Method to print-out all the built-in commands the shell provides and a brief
 * description of their function/purpose.
 */
void* help();

/*
 * Method to play a game. The game will be a guessing game where a number 1
 * 15 is randomly generated, and the user has 3 attempt to guess the correct
 * value of the number.
 */
void* game();

/*
 * Wrapper of fork(). Checks for fork erros, quits on error.
 *
 * RETURN: Process id.
 */
pid_t Fork(void);

/*
 * Method to get and store the user input from the command line.
 *
 * INPUT: A pointer to an array of chars where the string read is stored.
 * INPUT: The maximum number of characters to be read.
 * INPUT: The pointer to a FILE object that identifies the stream where
 *        characters are read from.
 * RETURN: The same str parameter, but with the stream stored inside.
 */
char* Fgets(char* ptr, int n, FILE* stream);

/*
 * Method to validate whether the command from the shell user input is a valid
 * built-in function, if yes, calls the function and passes argvs to it.
 *
 * INPUT: The user input, but parsed and stored in an argv char array.
 * RETURN: 1 if it is a custom shell built-in command, otherwise 0.
 */
int builtin_command(char** argv);

/*
 * Method to run a Unix built-in command that is located in the /bin directory
 * of the current system.
 *
 * INPUT: The user input, but parsed and stored in an argv char array.
 */
void createUnixCommandPath(char** argv);

/*
 * Method to handle user input evaluation and command calls.
 *
 * INPUT: The shell command line user input.
 */
void eval(char* cmdline);

/*
 * Method to exit loop on CTR-C input.
 */
void sighandler(int);

/*
 * Method that waits for a signal resets and exits shell on CTR-C input.
 */
void sighandler(int signum);

#endif
