//Jesse Reid CIS-115 lab 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Create a program that reads in a letter from a file and prints that letter in the following shapes to another file:
// Triangle
// Square
// Diamond
// Your program should contain functions to print each of the shapes individually, as well as one to retrieve the letter to be printed.
// Note: Add Input.txt and Output.txt to your Source files the same way you add your source code (.c) files. Simple give them the proper extension (.txt).


//Function to open Input.txt and read contents
char ReadChar() {
    FILE* inFile = NULL; // File pointer
    char inputChar;     // Data value from file

    //Opening Input.txt returnign an error if it fails
    inFile = fopen("Input.txt", "r");
    if (inFile == NULL) {
        printf("Could not open file Input.txt.\n");
        return 1;
    }
    //Reading file
    fscanf(inFile, "%c" , &inputChar);  
    //Closing file
    fclose(inFile);
    //Returning variable
    return inputChar;
}


//Print a triangle
void PrintTriangle(char inputchar, FILE* outFile) {
    fprintf(outFile, "\n  %c  \n", inputchar);
    fprintf(outFile, " %c%c%c \n", inputchar, inputchar, inputchar);
    fprintf(outFile, "%c%c%c%c%c\n\n", inputchar, inputchar, inputchar, inputchar, inputchar);
}


//Print a square
void PrintSquare(char inputchar, FILE* outFile) {
    fprintf(outFile, "\n%c%c%c%c\n", inputchar, inputchar, inputchar, inputchar);
    fprintf(outFile, "%c  %c\n", inputchar, inputchar);
    fprintf(outFile, "%c%c%c%c\n\n", inputchar, inputchar, inputchar, inputchar);
}


//Print a diamond
void PrintDiamond(char inputchar, FILE* outFile) {
    fprintf(outFile, "  %c  \n", inputchar);
    fprintf(outFile, "%c   %c\n", inputchar, inputchar);
    fprintf(outFile, "  %c  \n\n", inputchar);
}


//Main function to run program
int main(void) {
    FILE* outFile = NULL; //File pointer
    char inputChar;
    //Calls function to read Input.txt
    inputChar = ReadChar();
    
    //Open outFile
    outFile = fopen("Outfile.txt", "w");
    if (outFile == NULL) {
        printf("Could not open file Outfile.txt.\n");
        return 1;
    }

    //Functions to print shapes
    PrintTriangle(inputChar, outFile);
    PrintSquare(inputChar, outFile);
    PrintDiamond(inputChar, outFile);

    //Close outFile
    fclose(outFile);

    return 0;
}