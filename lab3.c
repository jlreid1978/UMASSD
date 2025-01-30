//Jesse Reid CIS-115 lab 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Define macros
#define daysPerMonth 30
#define daysPerYear 365
#define minutesPerDay 1440
#define secondsPerDay 86400
#define beatUnder5 80
#define beatUnder13 70
#define beatOver13 60
#define breathUnder5 20
#define breathUnder13 18
#define breathOver13 12
#define avgSneezesPerYear 200
#define avgCalorieUsage 2000
#define caloriesInPBJ 390


//Age Functions
//Original function to get the age in years from user
int UserAgeInYears(void) {
    int userAgeYears;
    printf("What is your age in years? ");
    scanf("%d", &userAgeYears);

    return userAgeYears; 
}


long long AgeInDays(int years){
    long long userAgeDays = years * daysPerYear;

    return userAgeDays;
} 


long long AgeInMinutes(long long userAgeYears){
    long long userAgeMinutes = AgeInDays(userAgeYears) * minutesPerDay;

    return userAgeMinutes;
}


long long AgeInSeconds(long long userAgeYears){
   long long userAgeSeconds = AgeInDays(userAgeYears) * secondsPerDay;

    return userAgeSeconds;
}


//Function to calculate historical beats
long long Beats(int userAgeYears){
    long long oldBeats;
    if (userAgeYears > 5 && userAgeYears <= 12) {
        oldBeats = (minutesPerDay * daysPerYear * 5 * beatUnder5);
    }else if (userAgeYears > 12){
        oldBeats = (minutesPerDay * daysPerYear * 7 * beatUnder13)+ (minutesPerDay * daysPerYear * 5 * beatUnder5);
    }
    
    return oldBeats;
}


//Function to calculate historical breaths
long long Breaths(int userAgeYears){
    long long oldBreaths;
    if (userAgeYears > 5 && userAgeYears <= 12) {
        oldBreaths = (minutesPerDay * daysPerYear * 5 * breathUnder5);
    }else if (userAgeYears > 12){
        oldBreaths = (minutesPerDay * daysPerYear * 7 * breathUnder13) + (minutesPerDay * daysPerYear * 5 * breathUnder5);
    }
    
    return oldBreaths;
}


//Function to calculate total heartbeats
long long TotalHeartbeats(int userAgeYears){
    long long totalHeartbeats;
    if (userAgeYears <= 5)
            {
                totalHeartbeats = beatUnder5 * AgeInMinutes(userAgeYears);
            }else if (userAgeYears > 5 && userAgeYears <= 12) //If a user is over five, then subtract five years, do the calculation, then add the five years on at the end
            {
                totalHeartbeats = (userAgeYears - 5) * beatUnder13 + Beats(userAgeYears);
            }else if (userAgeYears > 12)  //If a user is over 12, then subtract five years, do the calculation, then add the 12 years on at the end
            {
                totalHeartbeats = (userAgeYears - 12) * beatOver13 + Beats(userAgeYears);
            }

    return totalHeartbeats;

}


//Function to calculate total breaths
long long TotalBreaths(int userAgeYears){
    long long totalBreaths;
    if (userAgeYears <= 5)
            {
                totalBreaths = breathUnder5 * AgeInMinutes(userAgeYears);
            }else if (userAgeYears > 5 && userAgeYears <= 12) //If a user is over five, then subtract five years, do the calculation, then add the five years on at the end
            {
                totalBreaths = (userAgeYears - 5) * breathUnder13 + Breaths(userAgeYears);
            }else if (userAgeYears > 12)  //If a user is over 12, then subtract five years, do the calculation, then add the 12 years on at the end
            {
                totalBreaths = (userAgeYears - 12) * breathOver13 + Breaths(userAgeYears);
            }
    return totalBreaths;

}


//Sneeze function
int SneezeCalculator(int userAgeYears){
    int sneezes = userAgeYears * avgSneezesPerYear;

    return sneezes;
}


//Calculate Calories
int CalCalculator(int userAgeYears){
    int calories = AgeInDays(userAgeYears) * avgCalorieUsage;

    return calories;
}


//Calcualte calories in PB&J
int PBJCalories(int totalCalories){
    int pbjCalories = totalCalories / caloriesInPBJ;

    return pbjCalories;
}


//Main function
int main(void) {
    //Initialize all variables
    int userAgeYears;
    int userAgeDays;
    long long int userAgeMinutes;
    long long int userAgeSeconds;
    long long int totalHeartbeats;
    int totalSneezes;
    int totalBreaths;
    int breathPerMinute;
    int totalCalories;
    int totalPBJ;
 

    //Start program
    userAgeYears = UserAgeInYears();

    //Consume the leftover newline character to allow for a pause before exiting at the end of the script
    getchar();


    //Calculations

    //Age calculations use age functions
    userAgeDays = AgeInDays(userAgeYears);
    userAgeMinutes = AgeInMinutes(userAgeYears);
    userAgeSeconds = AgeInSeconds(userAgeYears);
 
    //Sneeze calculation uses sneeze function
    totalSneezes = SneezeCalculator(userAgeYears);

    //Calorie calculations use the calorie functions
    totalCalories = CalCalculator(userAgeYears);
    totalPBJ = PBJCalories(totalCalories);

    //Use TotalHeartbeats function to calculate value
    totalHeartbeats = TotalHeartbeats(userAgeYears);

    //Use TotalBreaths function to calculate value
    totalBreaths = TotalBreaths(userAgeYears);


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
