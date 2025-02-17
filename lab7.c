//Jesse Reid CIS-115 lab 7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Create a recursive function to print a multi-digit number vertically.
 
// For example, 2378 should be printed as
// 2
// 3
// 7
// 8
 
// Be sure to test your program with numbers of different length.
// The recursive function should return an int and take an int as a parameter.
// The function should have a base case where the parameter is 0 and this should return 0
// Define a temp variable using the remainder operator where temp is equal to the number passed to the function % 10 this will give you the last digit of the number
// Call the recursive function again with the parameter/10
// print the number from temp.


// Recursive counter function
int Counter(int numbers) {
    // Base case where all numbers are already printed
    if (numbers == 0) {
        return 0;
    }

    // Recursive function to print each number on one line
    else{
        // Temp variable set to last number in sequence
        int temp = numbers % 10;
        // Recursive call drops the last number and proceeds with the rest
        Counter(numbers / 10);
        // Print the number stored in temp as it comes out of the recursive call
        printf("%d\n", temp);
        return 0;
    }
}


// Main function to process gathering data and calling recursive counter function
int main(void) {
    int numbers;

    // Ask user for an integer
    scanf("%d", &numbers);

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();

    // Call to recursive counter function
    Counter(numbers);

    //Pause before exiting the program
    getchar();

    return 0;
}
