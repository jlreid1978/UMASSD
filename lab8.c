//Jesse Reid CIS-115 lab 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a program that performs the following tasks:
// Define a macro arraySize of size n
// Create two arrays of size n.
// Pass these arrays to a function fillArrays that randomizes enough integers between 1-100 (inclusive) to fill both arrays.
// Print both of these arrays.
// Pass the filled arrays to a second function mergeArrays that creates a third array of size 2n.
// Store the data from the first two arrays into the third array.
// Print out your sorted array.

// Define Macros
#define Array_Len 10
#define Merged_Len (Array_Len * 2)
#define Min_Num 1
#define Max_Num 100


// Function to randomly fill arrays
void fillArrays(int To_Be_Filled[]){
    for (int i = 0; i < Array_Len; ++i){
        To_Be_Filled[i] = Min_Num + rand() % (Max_Num - Min_Num + 1);
    }
}


// Function to print arrays
void printArrays(int print_Array[], char* array_Name, int Print_Len){
    printf("%s: ", array_Name);
    for (int p = 0; p < Print_Len; ++p){
        printf("%d ", print_Array[p]);
    }
    printf("\n");
}


// Function to merge the first two arrays into a third
void mergeArrays(int Arr1[], int Arr2[], int thirdArray[], char* array_Name){
    // Fill thrid array with the first array values
    for (int i = 0; i < Array_Len; ++i){
        thirdArray[i] = Arr1[i];
    }
    // Fill third array with the second array values
    for (int i = 0; i < Array_Len; ++i){
        thirdArray[i + Array_Len] = Arr2[i];
    }
    // Call the print function using the length of the new merged third array
    printArrays(thirdArray, array_Name, Merged_Len);
}


// Main function to run the program
int main(void) {
    int firstArray[Array_Len];
    int secondArray[Array_Len];
    int thirdArray[Array_Len * 2];
    char Array1[7] = "Array 1";
    char Array2[7] = "Array 2";
    char Array3[7] = "Array 3";

    // Seed random number generator 
    srand(time(NULL));

    // Call function to fill the first two arrays
    fillArrays(firstArray);
    fillArrays(secondArray);
    // Call function to print the first two arrays
    printArrays(firstArray, Array1, Array_Len);
    printArrays(secondArray, Array2, Array_Len);
    // Call function to merge the first two arrays
    mergeArrays(firstArray, secondArray, thirdArray, Array3);

}