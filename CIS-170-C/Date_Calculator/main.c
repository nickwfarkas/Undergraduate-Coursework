/*
 Nick Farkas
 
 CIS 170-70
 
Homework 2
Program 1
 */

//Libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Prototypes
int isLeap(int);
bool monthValidation(int);
bool dayValidation(int, int, int);
bool yearValidation(int);
void displayDate(int, int, int);
char numericToString(int);
int isLeap(int);
int monthsToDays(int, int);

// Asks for user input and Validates it
// After validation is past calculations are ran and it prints to the View
int main()
{

    int month = 0;
    int day = 0;
    int year = 0;
    
    
    do
    {
        printf("Please enter the date you would like to convert to a date number (In Format MM/DD/YYYY): ");
        //Seperates the month, day, and year from the dashes
        scanf("%d%*c%d%*c%d", &month, &day, &year);
    }
    while
    (
        // where validation is done
        // if any return false the program will ask for re input
        monthValidation(month) == false ||
        dayValidation(day, month, year) == false ||
        yearValidation(year) == false
    );
    
    //Displays final result
    displayDate(month, day, year);
    
    return 0;
}

//Checks if month is between 1-12
bool monthValidation(int month)
{
    if(month < 1 || month > 12)
    {
        printf("%d is not a valid month\n", month);
        return false;
    }
    return true;
}

//Validates Day
bool dayValidation(int day, int month, int year)
{
    //If months are 1,3,5,7,8,10,12 checks if day is between 1-31
    if(
       month == 1 ||
       month == 3 ||
       month == 5 ||
       month == 7 ||
       month == 8 ||
       month == 10 ||
       month == 12
       )
    {
        if (day < 1 || day > 31)
        {
            printf("%d is not a valid day for month selected\n", day);
            return false;
        }
    }
    //If months are 4,6,9,11 checks if day is between 1-30
    else if
        (
         month == 4 ||
         month == 6 ||
         month == 9 ||
         month == 11
        )
    {
        if (day < 1 || day > 30)
        {
            printf("%d is not a valid day for month selected\n", day);
            return false;
        }
    }
    //If month is 2 must check for leap year
    //If month is 2 and day is 29 and not a leap year, program asks for re-entry
    else if(month == 2)
    {
        
        if (day < 1 || day > 29)
        {
            printf("%d is not a valid day for month selected\n", day);
            return false;
        }
        //Validates based on Year
        else if (day == 29 && (isLeap(year) == 0))
        {
            printf("%d is not a valid day for month and year selected\n", day);
            return false;
        }
    }
    return true;
}

//Checks for incorrect years on interval (-Infinity, 0]
bool yearValidation(int year)
{
    if(year < 1)
    {
        printf("%d is not a valid year\n", year);
        return false;
    }
    return true;
}

//Reconstructs date to be printed with the final calculation
void displayDate(int month, int day, int year)
{
    
    //Since we can't store strings without many array accesses
    //We make switches based on months
    switch (month) {
        case 1:
            printf("Your date, January %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 2:
            printf("Your date, Febuary %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 3:
            printf("Your date, March %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 4:
            printf("Your date, April %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 5:
            printf("Your date, May %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 6:
            printf("Your date, June %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 7:
            printf("Your date, July %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 8:
            printf("Your date, August %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 9:
            printf("Your date, September %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 10:
            printf("Your date, October %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 11:
            printf("Your date, November %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        case 12:
            printf("Your date, December %d, %d is day number %d\n", day, year, monthsToDays(month, year) + day);
            break;
        default: printf("Your Date, %d,%d,%d is day number %d\n", month, day, year, monthsToDays(month, year) + day);
            break;
    }
}

//Checks is year entered is a leap year
int isLeap(int year)
{
    //Compound Conditions in ONE if Statement
    if (((year % 4 == 0)&&(year % 100 != 0))||
        ((year % 4 == 0)&&(year % 100 == 0)&&(year % 400 == 0)))
    {
        //Using 1 and 0 to make converting months to days less complicated
        return 1;
    }
    return 0;
}


//Converts Months to Days for easy Calculation
int monthsToDays(int month, int year)
{
    //(month - 1) because the day data point already counts days for inputted month
    switch (month - 1) {
        case 0:
            return 0;
            break;
        case 1:
            return 31;
            break;
        case 2:
            return 59;
            break;
        case 3:
            //Starts Adding Leap year Day
            //isLeap() returns 1 or 0 so it just adds one of those values to our months
            return 90 + isLeap(year);
            break;
        case 4:
            return 120 + isLeap(year);
            break;
        case 5:
            return 151 + isLeap(year);
            break;
        case 6:
            return 181 + isLeap(year);
            break;
        case 7:
            return  212 + isLeap(year);
            break;
        case 8:
            return 243 + isLeap(year);
            break;
        case 9:
            return 273 + isLeap(year);
            break;
        case 10:
            return 304 + isLeap(year);
            break;
        case 11:
            return 334 + isLeap(year);
            break;
        default:
            break;
    }
    return 0;
}

