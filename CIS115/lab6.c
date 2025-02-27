//Jesse Reid CIS-115 lab 6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Complete all 3 of the programming assignment versions given in Chapter 6.13 of the Zybook and combine them into one program.
// Make printing the statistics and printing the histogram separate functions.
// The final program should complete all 3 requirements as outlined in the zybook

// Calculates the number of times the sum of the randomly rolled dice equals each possible value from 2 to 12.
// Repeatedly asks the user for the number of times to roll the dice, quitting only when the user-entered number is less than 
// 1. Hint: Use a while loop that will execute as long as numRolls is greater than 1. Be sure to initialize numRolls correctly.
// Prints a histogram in which the total number of times the dice rolls equals each possible value is displayed by printing a character 
// like * that number of times, as shown below


// Print statistics on dice rolls
void PrintStats(int dieSide[], int options){
    printf("\n\nDice roll statistics:\n");
    // Itirate through the array and print the saved statistics
    for (int i = 0; i < options; ++i) {
        printf("%d's: %d\n", i + 2, dieSide[i]);
    }
    printf("\n");
}


// Print histogram on dice rolls
void PrintHistogram(int dieSide[], int options){
    printf("\nHistogram for roll statistics:\n");
    // Itirate through the array and print a histogram
    for (int i = 0; i < options; ++i) {
        printf("%d's: ", i + 2);
        // Alligns the histogram 
        if (i + 2 < 10){
            printf(" ");
        }
        // Calculates number of "#" needed for each number
        for (int h = 0; h < dieSide[i]; ++h) {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}

// Main function for dice rolling
int main(void){
    int numRolls;    // User defined number of rolls
    int die1;        // Die 1 values
    int die2;        // Die 2 values
    int rollTotal;   // Sum of dice values
    int dieSide[11] = {0}; // Array of two six sided dice
    int options = sizeof(dieSide) / sizeof(dieSide[0]); // calculate the size of the array
    
    // Initially ask user how many times to roll the dice
    printf("Enter number of rolls: \n");
    scanf("%d", &numRolls);

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();

    // Continue rolling until user selects 0
    while (numRolls > 0) {
        srand(time(0));
        
        // Roll dice numRoll times
        for (int i = 1; i <= numRolls; ++i) {
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            rollTotal = die1 + die2;
            // Loop though array of numbers and set value to corresponding position offset by 2 (2-12)
            for (int d = 0; d <= options; ++d){
                if (rollTotal == d + 2){
                    dieSide[d] = dieSide[d] + 1;
                }
            }
            // Print roll info
            printf("\nRoll %d is %d (%d+%d)", i, rollTotal, die1, die2);
        }
    

        // Ask user if they wish to roll the dice again
        printf("\n\nEnter number of rolls (0 to stop): \n");
        scanf("%d", &numRolls);

        //Consume the leftover newline character to allow for a pause before exiting at the end of the script
        getchar();
    }

    // Call function to print stats based on calculations made above
    PrintStats(dieSide, options); 
    // Call functiont to print histogram based on calculations made above
    PrintHistogram(dieSide, options);

    //Pause before exiting the program
    getchar();

    return 0;
}
