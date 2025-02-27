//Jesse Reid CIS-115 lab 9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

//Function Prototypes
void addInt(int **intPtr, int *intCount);
void addDbl(double **dblPtr, int *dblCount);
void addChr(char **chrPtr, int *chrCount);

void printInts(int *intPtr, int intCount);
void printDbls(double *dblPtr, int dblCount);
void printChrs(char *chrPtr, int chrCount);

int main(){
	//Keep track of the number of each type entered as well as the user's choice for each iteration of the main loop
	int intCount = 0, dblCount = 0, chrCount = 0, userChoice = 0;

	//Create our pointers initially with no memory allocated to them
	int *intPtr = (int *)malloc(sizeof(int) * 0);
	double *dblPtr = (double *)malloc(sizeof(double) * 0);
	char *chrPtr = (char *)malloc(sizeof(char) * 0);


	//Loop until the user chooses to exit
	while (userChoice != 4){
		//Retrieve input from user
		printf("\nWhich value will you add?\n1. Integer\n2. Double\n3. Character\n4. Exit\n");
		scanf("%d%*c", &userChoice);

		//Call different functions based on the user's choice
		switch (userChoice){
		case 1:
			//Add an integer to the int pointer
			addInt(&intPtr, &intCount);
			break;
		case 2:
			//Add a double to the dbl pointer
			addDbl(&dblPtr, &dblCount);
			break;
		case 3:
			//Add a character to the chr pointer
			addChr(&chrPtr, &chrCount);
			break;
		default:
			printf("\nProgram Complete!\n");
			break;

		}

		//Print all three pointers at the end of every iteration
		printInts(intPtr, intCount);
		printDbls(dblPtr, dblCount);
		printChrs(chrPtr, chrCount);
		printf("\n");
	}

	// free memory for all pointers
	free(intPtr);
	free(dblPtr);
	free(chrPtr);
	getchar();

	return 0;
}

//Function to add a value to the int pointer and increment the amount of values in the pointer
void addInt(int **intPtr, int *intCount){
	int value;
	printf("Enter your value: ");
	scanf("%d%*c", &value);

	//Dereference and increment our intCount
	(*intCount)++;
	//Dereference and reallocate memory to our intPtr
	(*intPtr) = realloc((*intPtr), sizeof(int) * (*intCount));
	//Store the entered value into the proper position of our intPtr
	(*intPtr)[(*intCount) - 1] = value;
}

//Function to add a value to the dbl pointer and increment the amount of values in the pointer
void addDbl(double **dblPtr, int *dblCount){
	double value;
	// Ask user for double value
	printf("Enter your value: ");
	scanf("%lf%*c", &value);

	// Dereference and increment the dblCount
	(*dblCount)++;
	// Dereference and reallocate memory to the dblPtr
	(*dblPtr) = realloc((*dblPtr), sizeof(double) * (*dblCount));
	// Store the entered value into the proper position of the dblPtr
	(*dblPtr)[(*dblCount) - 1] = value;
}

//Function to add a value to the chr pointer and increment the amount of values in the pointer
void addChr(char **chrPtr, int *chrCount){
	char value;
	// Ask user for char value
	printf("Enter your value: ");
	scanf("%c%*c", &value);

	// Dereference and increment the dblCount
	(*chrCount)++;
	// Dereference and reallocate memory to the dblPtr
	(*chrPtr) = realloc((*chrPtr), sizeof(char) * (*chrCount));
	// Store the entered value into the proper position of the dblPtr
	(*chrPtr)[(*chrCount) - 1] = value;
}

//Print our integer pointer
void printInts(int *intPtr, int intCount){
	int i = 0;

	printf("\nInts: ");
	for (i = 0; i < intCount; i++){
		printf("%d ", intPtr[i]);
	}
}

//Print our double pointer
void printDbls(double *dblPtr, int dblCount){
	int d = 0;

	printf("\nDbls: ");
	for (d = 0; d < dblCount; d++){
		printf("%.2lf ", dblPtr[d]);
	}
}


//Print our character pointer
void printChrs(char *chrPtr, int chrCount){
	int c = 0;

	printf("\nChars: ");
	for (c = 0; c < chrCount; c++){
		printf("%c ", chrPtr[c]);
	}
}
