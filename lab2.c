//Jesse Reid CIS-115 lab 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    //Initialize all variables
    int userAgeYears;
    int userAgeDays;
    long long int userAgeMinutes;
    long long int userAgeSeconds;
    long long int totalHeartbeats;
    int beatPerMinute;
    int totalSneezes;
    int totalBreaths;
    int breathPerMinute;
    int totalCalories;
    int totalPBJ;
 

    //Define macros
    #define avgSneezesPerYear 200
    #define daysPerMonth 30
    #define daysPerYear 365
    #define minutesPerDay 1440
    #define secondsPerDay 86400
    #define avgCalorieUsage 2000
    #define caloriesInPBJ 390
    #define beatUnder5 80
    #define breathUnder5 20
    #define beatUnder13 70
    #define breathUnder13 18
    #define beatOver13 60
    #define breathOver13 12
    #define heartbeatInFiveYears ((long long)minutesPerDay * daysPerYear * 5 * beatUnder5) //calculations for five full years of age
    #define breathInFiveYears ((long long)minutesPerDay * daysPerYear * 5 * breathUnder5)  //calculations for five full years of age
    #define heartbeatInSevenYears ((long long)minutesPerDay * daysPerYear * 7 * beatUnder13)  //calculations for seven full years of age between 6 and 12
    #define breathInSevenYears ((long long)minutesPerDay * daysPerYear * 7 * breathUnder13)  //calculations for seven full years of age between 6 and 12


    //Start program

    //Ask user their age in years
    printf("What is your age in years? ");
    scanf("%d", &userAgeYears);

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();


    //Calculations

    //Age calculations
    userAgeDays = userAgeYears * daysPerYear;
    userAgeMinutes = (long long)userAgeDays * minutesPerDay;
    userAgeSeconds = (long long)userAgeDays * secondsPerDay;
 
    //Health Calculations
    totalSneezes = userAgeYears * avgSneezesPerYear;
    totalCalories = userAgeDays * avgCalorieUsage;
    totalPBJ = totalCalories / caloriesInPBJ;

    //calculate beats and breaths per minute by age
    if (userAgeYears <= 5)
        {
            totalHeartbeats = (long long)beatUnder5 * userAgeMinutes;
            totalBreaths = (long long)breathUnder5 * userAgeMinutes;
        }else if (userAgeYears > 5 && userAgeYears <= 12) //If a user is over five, then subtract five years, do the calculation, then add the five years on at the end
        {
            totalHeartbeats = (long long)(userAgeYears - 5) * beatUnder13 + heartbeatInFiveYears;
            totalBreaths = (long long)(userAgeYears - 5) * breathUnder13 + breathInFiveYears;
        }else if (userAgeYears > 12)  //If a user is over 12, then subtract five years, do the calculation, then add the 12 years on at the end
        {
            totalHeartbeats = (long long)(userAgeYears - 12) * beatOver13 + heartbeatInFiveYears + heartbeatInSevenYears;
            totalBreaths = (long long)(userAgeYears - 12) * breathOver13 + breathInFiveYears + breathInSevenYears;
        }


    //Print the calculated data
    printf("\nYou are %d days old.\n", userAgeDays);
    printf("You are %lld minutes old.\n", userAgeMinutes);
    printf("You are %lld seconds old.\n", userAgeSeconds);
    printf("You have sneezed %d times.\n", totalSneezes);
    printf("You have burned %d calories.\n", totalCalories);
    printf("Which would mean you could have eaten %d peanut butter and jelly sandwiches.\n", totalPBJ);
    printf("Your heart has beat %lld times.\n", totalHeartbeats);
    printf("You have taken %d breaths\n", totalBreaths);
    printf("Note: These values are all approximations and just in fun.\n");


    //Pause before exiting the program
    getchar();

    return 0;
}
