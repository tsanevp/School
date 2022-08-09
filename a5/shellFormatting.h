#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SHELLFORMATTING_H
#define SHELLFORMATTING_H

/*
 * Method to reset the shell and formatting color to white.
 */
void resetColor();

/*
 * Method to change the shell and formatting color to red.
 */
void red();

/*
 * Method to change the shell and formatting color to green.
 */
void green();

/*
 * Method to center and print the passed text on the screen.
 *
 * INPUT: A string of text to print in the shell window.
 * INPUT: The field around which to center the text.
 */
void centerText(char* text, int fieldWidth);

/*
 * Method to format and print the initial shell intro message to the window.
 */
void shellWelcomeMessage();

#endif
