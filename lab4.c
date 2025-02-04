//Jesse Reid CIS-115 lab 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Create a simple calculator that performs addition, subtraction, multiplication, and division.
// Your program should prompt the user for  the operation they wish to perform followed by the numbers they wish to operate on.
// You should have a function for each operation and use branches to determine which function to call.


// Function to calculate adding num1 and num2
long long Addition(double num1, double num2) {
    return num1 + num2;
}


// Function to calculate subtracting num2 from num1
long long Subtraction(double num1, double num2) {
    return num1 - num2;
}


// Function to calculate multiplying num1 and num2
long long Multiplication(double num1, double num2) {
    return num1 * num2;
}


// Function to calculate dividing num2 by num1
long long Division(double num1, double num2) {
    return num1 / num2;
}


//Main function
int main(void){
    double num1;
    double num2;
    double result;
    int selection;
    

    //Ask user for their selection
    printf("Please select the number of whatever function you wish to use?\n"
    "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &selection);

    //Validation for selection. If selection is valid, ask for two numbers.
    if ((selection >= 1) && (selection <= 4)){
        printf("\nPlease enter number 1: ");
        scanf("%lf", &num1);

        printf("\nPlease enter number 2: ");
        scanf("%lf", &num2);
    }
    else{
        printf("You have entered an invalid selection.\n\n");
        return 0;
    }

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();
    

    //Select which function to use based on the branch condition
    if (selection == 1){
        result = Addition(num1, num2);
    }
    else if (selection == 2){
        result = Subtraction(num1, num2);
    }
    else if (selection == 3){
        result = Multiplication(num1, num2);
    }
    else if (selection == 4){
        result = Division(num1, num2);
    }
    else{
        printf("Unable to complete your request at this time.\n\n");
    }

    //Print the result
    printf("Your answer is: %lf\n\n", result);

    //Pause before exiting the program
    getchar();

    return 0;
}