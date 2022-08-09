#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#include "shell.h"
#include "parse.h"
#include "history.h"
#include "shellFormatting.h"

#define MAXARGS 5
#define MAXLINE 8192
#define BIN "/bin/"
#define HOMEDIR "/home/"
#define TRAVERSEUPDIR ".."
#define STAYDIR "."
LinkedListPtr list;

// Method to reset shell and formatting color, destroy linked list, and exit.
void resetShellFormat() {
    resetColor();
    DestroyLinkedList(list);
    exit(0);
}

// A char array that stores the names of this shell's custom built-in commands.
char* commands[] = {"cd", "history", "pwd", "clear", "ls", "help", "game",
    "exit"};

// An array of function pointers that stores pointers to the built-in commands.
void* (*command_functions[])(char*) = {cd, history, pwd, clear, ls, help, game};

// Method to obtain and return the user name of the current shell user.
char* getUser(char* username) {
    cuserid(username);
    return username;
}

// Method to change and move directories while using the shell.
void* cd(char* input) {
    char cwd[MAXLINE];  // String to store cwd
    getcwd(cwd, MAXLINE);  // C function to obtain cwd

    // If input is NULL, aka only "cd" entered on command line enter IF
    // Else, chdir(input)
    if (input == NULL) {
        // C function to determine and store user's username
        char homedir[MAXLINE];
        char username[MAXLINE];

        // Copy and cat username to "/home" and compare to defined home dir
        strcpy(homedir, HOMEDIR);
        strcat(homedir, getUser(username));

        // If cwd len is less than homedir, must be in parent dir -- do nothing
        // Else, move a directory level up until cwd matches defined home dir
        if (strlen(cwd) < strlen(homedir)) {
            chdir(STAYDIR);
        } else {
            while (strcmp(cwd, homedir)) {
                chdir(TRAVERSEUPDIR);
                getcwd(cwd, MAXLINE);
            }
        }
    } else {
        chdir(input);
    }
}

// Method to get the command history of the shell.
void* history() {
    centerText("****Command Line Input History****", 50);
    PrintLinkedList(list);
    centerText("****End Of History****", 50);
}

// Method to get the current working directory.
void* pwd() {
    long size;
    char* buf;
    char* ptr;
    // Gets and prints current working directory
    size = pathconf(STAYDIR, _PC_PATH_MAX);
    if ((buf = (char*)malloc((size_t)size)) != NULL) {
        ptr = getcwd(buf, (size_t)size);
        printf("%s\n", ptr);
    }
    free(buf);
}

// Method to clear the current shell window and move the shell to the top.
void* clear() {
    printf("\e[1;1H\e[2J");
}

// Method to get the directory contents of the directory path passed.
void* ls(char* input) {
    DIR *dirToView;
    struct dirent *dir;

    // Stays in and views current directory contents
    if (input == NULL) {
        input = STAYDIR;
    }

    // Error message if directory user tries to access is invalid
    if ((dirToView = opendir(input)) == NULL) {
        char errmsg[MAXLINE];
        strcpy(errmsg, "ls: cannot access ");
        perror(strcat(errmsg, input));
    }

    // Opens and reads contents of given directory path
    if (dirToView) {
        while ((dir = readdir(dirToView)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(dirToView);
    }
    return 0;
}

// Method to display all the built-in functions that the shell utilizes.
void* help() {
    printf("\n");
    centerText("****Built-In Commands Of Custom K-SEA-SHELL****\n", 81);
    printf("1:   cd    -- Command to change the current working directory to "
            "directory path\n"
            "              specified. It has one parameter, the path of the new"
            " directory.\n\n"
            "2: history -- Command to view and print the past user inputs on "
            "the command line.\n\n"
            "3:   pwd   -- Command to get and print the current working"
            " directory path on the\n"
            "              command line.\n\n"
            "4:  clear  -- Command to clear the current shell window and move"
            "the command line\n"
            "              to the top of the terminal window.\n\n"
            "5:    ls   -- Command to print the contents of the directory path"
            " that is passed\n"
            "              as a parameter. If no path is passed, prints the "
            "the contents of the\n"
            "              current working directory.\n\n"
            "6:   help  -- Command to print out all the built-in commands this "
            "custom shell\n"
            "              provides and offers.\n\n"
            "7:   game  -- Command to run and play a numbers guessing game"
            " where a number, 1\n"
            "              through 15 (inclusive), is generated, and the user"
            " must guess the\n"
            "              number.\n\n");
}

// Method to play guessing game where the user has to guess a number 1-15.
void* game() {
    printf("\nWelcome to my guessing game! You have 3 attempts to guess the\n"
            "number whose value ranges from 1 to 15...\n\n");
    srand(time(NULL));
    int maxNumGuesses = 3;
    int maxNum = 15;
    int numToGuess = rand() % maxNum;
    int i = 1;
    int guess;
    while (i <= maxNumGuesses) {
        printf("Guess number %d... Enter a number: ", i);
        scanf("%d", &guess);
        if (guess == numToGuess) {
            printf("THAT GUESS IS CORRECT! YOU WIN!\n\n");
            return;
        } else if (guess > maxNum) {
            printf("That guess value exceeds %d... try again!\n\n", maxNum);
        } else if (guess < 0) {
            printf("Guess values cannot be negative... try again!\n\n");
        } else {
            i++;
        }
    }
    printf("Sorry... you ran out of attempts, the number to guess was: %d\n\n",
            numToGuess);
}

// Wrapper of fork(). Checks for fork errors, quits on error.
pid_t Fork(void) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
        exit(0);
    }
    return pid;
}

// Wrapper of fgets. Checks and quits on Unix error.
char* Fgets(char *ptr, int n, FILE *stream) {
    char *rptr;
    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
        fprintf(stderr, "%s\n", "fgets error");
        exit(0);
    }
    return rptr;
}

// Method to check if command is built into shell, if yes, executes call
int builtin_command(char** argv) {
    // Loop through and compare built-in commands to user input
    int i, res;
    for (i = 0; i < (sizeof(commands) / sizeof(commands[0])); i++) {
        res = strcmp(commands[i], argv[0]);
        if (!res) {  // Built-in command exists
            if (!strcmp(commands[i], "exit")) resetShellFormat();
            (*command_functions[i])(argv[1]);  // Calls command and passes argv
            return 1;
        }
    }
    return 0;
}

// Method to define and create a file path to the current user's system bin
// directory. All the UNIX built-in functions are found there.
void createUnixCommandPath(char** argv) {
    char filepath[MAXLINE];
    strcpy(filepath, BIN);
    strcat(filepath, argv[0]);
    argv[0] = filepath;
}

// Method to evaluate and execute some command based on the cmd line input.
void eval(char *cmdline) {
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE]; /* Holds modified command line */
    pid_t pid; /* Process id */

    strcpy(buf, cmdline); /* Copy command line into buffer */

    // Create a copy of buffer and store it to tail of linked list
    char *copy = (char*)malloc(strlen(buf) + 1);
    strcpy(copy, buf);
    addRight(list, strtok(copy, "\n"));

    // Parse buffer and store each token in an index of args. Max 5 args
    int numArgv = parse(buf, " \n", argv);
    if (!numArgv) {
        printf("k-sea-shell: Too many command arguements. Try again. \n");
        return;
    }

    if (argv[0] == NULL) return; /* Ignore empty lines */

    // Check to see if command is built-into shell
    if (!builtin_command(argv)) {
        // Check to see if command is built-into linux bash shell
        if (fork() == 0) {
            createUnixCommandPath(argv);
            int res = execve(argv[0], argv, NULL);

            // Given command does not exist
            if (res < 0) printf("k-sea-shell: command not found\n");
        } else {
            wait(NULL);
        }
    }
    return;
}

// Method to exit loop on CTR-C input.
void sighandler(int);

// Method that resets and exits shell on CTR-C input.
void sighandler(int signum) {
    resetShellFormat();
}

// Main method, runs the program.
int main() {
    shellWelcomeMessage();
    char cmdline[MAXLINE]; /* command line buffer */
    char username[MAXLINE];

    // Creates the linked list that holds past commands
    list = CreateLinkedList();

    // Waits for CRT-C key input
    signal(SIGINT, sighandler);

    while (1) {
        // Sets the shell color format to green
        green();
        // Print command prompt
        printf("k-sea-shell-%s$ ", getUser(username));

        // Read input from user
        Fgets(cmdline, MAXLINE, stdin);

        // If we get the eof, quit the program/shell
        if (feof(stdin)) exit(0);

        // Otherwise, evaluate the input and execute
        eval(cmdline);
    }
}
