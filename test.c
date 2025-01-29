#include <stdio.h>

int main(void) {
   int birthMonth;
   int birthYear;

   printf("Input your month:");
   scanf("%d", &birthMonth);
   printf("Input your year: ");
   scanf("%d", &birthYear);
   printf("%d/%d\n", birthMonth, birthYear);/* Your solution goes here  */

   return 0;
}