#include <stdio.h> 
#include <stdlib.h>

//Function Prototypes
void addInt(int **intPtr, int *intCount);
// add prototypes for char and double here

void printInts(int *intPtr, int intCount);
// add prototypes for char and double here

int main(){
	//Keep track of the number of each type entered as well as the user's choice for each iteration of the main loop
	int intCount = 0, dblCount = 0, chrCount = 0, userChoice = 0;

	//Create our pointers initially with no memory allocated to them
	int *intPtr = (int *)malloc(sizeof(int) * 0);


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
			// function call to addDouble
			break;
		case 3:
			//Add a character to the chr pointer
			//function call to addCharachter
			break;
		default:
			printf("\nProgram Complete!\n");
			break;
		}

		//Print all three pointers at the end of every iteration
		printInts(intPtr, intCount);
		// print the double pointer
		// print the charachter pointer
		printf("\n");
	}

	free(intPtr);
	// free double pointer
	// free charachter pointer
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
// complete the function to addDdbl
}

//Function to add a value to the chr pointer and increment the amount of values in the pointer
void addChr(char **chrPtr, int *chrCount){
// complete function to add charachter
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
// complete function to print a double pointer
	}
}

//Print our character pointer
void printChrs(char *chrPtr, int chrCount){
// complete function to print a charachter pointer
	}
}