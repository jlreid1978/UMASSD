#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void Explore(int* allVals, int* pickedVals, bool* inUse, int totalPicked, int arraySize){
    int i;

    // Base case: All values are picked
    if (totalPicked == arraySize) {
        for (i = 0; i < totalPicked; ++i){
            printf("%d ", pickedVals[i]);
        }
        printf("\n");
    }
    // Recursive case
    else {
        if (!inUse[i]) {
            inUse[i]  = true;     
               
        for (i = 0; i < arraySize; ++i){
            pickedVals[totalPicked] = allVals[i];
            Explore(allVals, pickedVals, inUse, totalPicked + 1, arraySize);
            inUse = false;
        }
    }
    }
}

int main(void){
    int arraySize;
    int* valsToPick = NULL;
    int* picks = NULL;
    bool* inUse = NULL;
    int i;

    scanf("%d", &arraySize);

    valsToPick = (int*) malloc(sizeof(int) * arraySize);
    picks = (int*) malloc(sizeof(int) * arraySize);
    inUse = (bool*) malloc(sizeof(int) * arraySize);

    for (i = 0; i< arraySize; ++i) {
        scanf("%d", &(valsToPick[i]));
    }

    printf("All possible ways to order an array of size %d:\n", arraySize);

    Explore(valsToPick, picks, inUse, 0, arraySize);

    free(valsToPick);
    free(picks);
    free(inUse);

    return 0;

}