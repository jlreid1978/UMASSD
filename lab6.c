//Jesse Reid CIS-115 lab 5
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


int i;           // Loop counter iterates numRolls times
int d;
int p;
int numRolls;    // User defined number of rolls
int die1;        // Dice values
int die2;        // Dice values
int rollTotal;   // Sum of dice values
int dieSide[12];
int options;


// Print statistics on dice rolls
void PrintStats(dieSide, options){
    printf("\n\nDice roll statistics: \n");
    for (p = 1; p <= options; ++p){
        printf("%ds: %d\n",p, dieSide[p]);
    }
    printf("\n");

}


int main(void){
    int dieSide[12] = {0}; // Array of two six sided dice
    options = sizeof(dieSide) / sizeof(dieSide[0]);

    printf("Enter number of rolls: \n");
    scanf("%d", &numRolls);

    while (numRolls > 0) {
        srand(time(0));
        
        // Roll dice numRoll times
        for (i = 1; i <= numRolls; ++i) {
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            rollTotal = die1 + die2;
            
            for (d = 0; d < options; ++d){
                if (rollTotal == i){
                    dieSide[d] = dieSide[d] + 1;
                }
            }

            printf("\nRoll %d is %d (%d+%d)", i + 1, rollTotal, die1, die2);
        }
        
        PrintStats(dieSide, options);        

        printf("Enter number of rolls (0 to stop): \n");
        scanf("%d", &numRolls);
    }
    
    return 0;
}



