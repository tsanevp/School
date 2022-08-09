#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shellFormatting.h"

// Method to reset the shell and formatting color to white.
void resetColor() {
    printf("\033[0;37m");
}

// Method to change the shell and formatting color to red.
void red() {
    printf("\033[1;31m");
}

// Method to change the shell and formatting color to green.
void green() {
    printf("\033[0;32m");
}

// Method to center and print string passed as parameter, based on width input.
void centerText(char* text, int fieldWidth) {
    int spaceLen = (fieldWidth - strlen(text)) / 2;
    printf("%*s%s%*s\n", spaceLen, "", text, spaceLen, "");
}

// Method to set formatting of shell and print intro message to shell window.
void shellWelcomeMessage() {
    red();
    printf("\e[1;;1H\e[2J");
    printf("******************************************************************"
            "**************\n\n");
    centerText("ASSIGNMENT 5: CREATING A CUSTOM SHELL!", 81);
    centerText("WELCOME TO MY SHELL, ENJOY HOW AWESOME IT IS ... and the cool"
            "printout below!", 81);
    printf(""
            "  _  __            _____  ______                       _____  _   "
            "         "
            "_  _         \n"
            " | |/ /           / ____||  ____|    /\\               / ____|| | "
            "         "
            "| || |       \n"
            " | ' /   ______  | (___  | |__      /  \\     ______  | (___  | |_"
            "_    ___ "
            "| || |       \n"
            " |  <   |______|  \\___ \\ |  __|    / /\\ \\   |______|  \\___ \\"
            " | '_ \\ "
            " / _ \\| || |\n"
            " | . \\            ____) || |____  / ____ \\            ____) || |"
            " | ||  __"
            "/| || |      \n"
            " |_|\\_\\          |_____/ |______|/_/    \\_\\          |_____/ |"
            "_| |_| \\"
            "___||_||_|\n\n");
    centerText("... However, use my shell AT YOUR OWN RISK ...\n", 81);
    printf("******************************************************************"
            "**************\n\n");
}
