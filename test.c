#include <stdio.h>

int main() {


   char myString[100] = "1053 17.5 42 Smith";
    float val1; 
    int val2;
    int val3; 
    int val4;

    sscanf(myString, "%f %d %d %d", &val1, &val2, &val3, &val4); 

    printf("%f %d %d %d\n", val1, val2, val3, val4); 

    return 0;
}