//Jesse Reid CIS-115 lab 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    //Initialize the numPyramid variable and ask the user to input a number
    int numPyramid;
    printf("Please enter a number: ");
    scanf("%d", &numPyramid);

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();

    //Print the tree
    printf("\n   *  \n");
    printf("  *** \n");
    printf(" *****\n");
    printf("*******\n");
    printf("  *** \n\n");

    //Print the cat
    printf("^   ^ \n");
    printf(" o o \n");
    printf("=   =\n");
    printf(" ___\n\n");

    //Print the pyramid based on the user input
    printf("  %d  \n", numPyramid);
    printf(" %d%d%d \n", numPyramid, numPyramid, numPyramid);
    printf("%d%d%d%d%d\n\n", numPyramid, numPyramid, numPyramid, numPyramid, numPyramid);

    //Pause before exiting the program
    getchar();

    return 0;
}