//
//  main.c
//  HW_4_Program_1
//
//  Created by Nicholas Farkas on 12/4/19.
//
//  Zero color roulette wheel
//

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

bool makeBetValidation(int);
void makeBet(int *, int *);
bool betOnNumberValidation(int);
bool betOnEvenOrOddValidation(int);
float getBetAmount(int, int);
float figureWinnings(int, int, float);
void buffer(void);
void showInstructions(void);
char playAgainValidation(char);
bool betOnDozenValidation(int);

int main()
{
    srand(((unsigned)time(0)));
    int userNumber;
    int typeOfBet;
    float amount;
    float winnings;
    char sent = 'y';
    
    showInstructions();
    
    while (sent == 'y' || sent == 'Y')
    {
        makeBet(&userNumber, &typeOfBet);
        amount = getBetAmount(typeOfBet, userNumber);
        winnings = figureWinnings(userNumber, typeOfBet, amount);
        
        if (winnings > 0)
        {
            printf("Congradulations you have won $%.2f from the $%.2f you bet!\n", winnings, amount);
        }
        else
        {
            printf("You lost the $%.2f you bet.\nBetter luck next time!\n", amount);
        }
        buffer();
        printf("Would you like to make another bet? (Y for yes, N for no): ");
        scanf("%c", &sent);
        sent  = playAgainValidation(sent);
        buffer();
    }
    
    printf("Thank you for playing!\n");
    
    return 0;
}

char playAgainValidation(char terminator)
{
    while (tolower(terminator) != 'y' && tolower(terminator) != 'n')
    {
        buffer();
        printf("%c is not a valid response please try again\n", terminator);
        printf("Would you like to make another bet? (Y for yes, N for no): ");
        scanf("%c", &terminator);
    }
    
    return terminator;
}

void buffer()
{
    char buff;
    scanf("%c", &buff);
}

//Prints Instructions
void showInstructions()
{
    printf("Instructions:\n");
    printf("Select your type of bet\n\n");
    
    printf("Betting on a number\n");
    printf("Choose a number, make a bet, and payout is 36 times the bet\n\n");
    
    printf("Betting on odd or even\n");
    printf("Choose odd or even, make a bet, and payout is 2 times the bet\n\n");
    
    printf("Betting on a dozen\n");
    printf("Choose first 1-12, second 13-24, or third 25-36, make a bet, and payout is 3 times the bet\n\n");
}

//Gets user bet based on what type of bet they have chosen
void makeBet(int * numberPointer, int * typeOfBet)
{
    int betType = 0;
    int bet = 0;
    do
    {
        printf("Please select a number corresponding to your type of bet\n");
        printf("1. Bet on a number\n");
        printf("2. Bet on odd or even\n");
        printf("3. Bet on dozen\n");
        printf("What type of bet would you like to make: ");
        scanf("%d", &betType);
    }while (makeBetValidation(betType) == false);
    
    if (betType == 1)
    {
        bet = 0;
        do
        {
            printf("You chose to bet on a number!\n");
            printf("What number would you like to bet on 0-36: ");
            scanf("%d", &bet);
        }while (betOnNumberValidation(bet) == false);
        
        *numberPointer = bet;
    }
    
    if (betType == 2)
    {
        bet = 0;
        do
        {
            printf("You chose to bet on a even or odd!\n");
            printf("Please enter 1 for odd or 2 for even: ");
            scanf("%d", &bet);
        }while (betOnEvenOrOddValidation(bet) == false);
        
        *numberPointer = bet;
    }
    
    if (betType == 3)
    {
        bet = 0;
        do
        {
            printf("You chose to bet on a dozen!\n");
            printf("You can choose:\n1 for first dozen (1-12)\n2 for second dozen (13-24)\n3 for third dozen (25-36)\nPlease make a selection: ");
            scanf("%d", &bet);
        }while (betOnDozenValidation(bet) == false);
        
        *numberPointer = bet;
    }
    
    *typeOfBet = betType;
    
}

//Validates when betting on dozen
bool betOnDozenValidation(int bet)
{
    if (bet < 1 || bet > 3)
    {
        printf("%d, is not a valid entry\n", bet);
        printf("Please try again\n");
        return false;
    }
    else return true;
}

//Validates when betting on number
bool betOnNumberValidation(int bet)
{
    if (bet < 0 || bet > 36)
    {
        printf("%d, is not a valid entry\n", bet);
        printf("Please try again\n");
        return false;
    }
    else return true;
}

//Validates when betting on odd or even
bool betOnEvenOrOddValidation(int bet)
{
    if (bet < 1 || bet > 2)
    {
        printf("%d, is not a valid entry\n", bet);
        printf("Please try again\n");
        return false;
    }
    else return true;
}

//Validates the bet type
bool makeBetValidation(int betType)
{
    if (betType < 1 || betType > 3)
    {
        printf("%d, is not a valid entry\n", betType);
        printf("Please try again\n");
        return false;
    }
    else return true;
}

//Gets bet amount from user
float getBetAmount(int typeOfBet, int number)
{
    char betTxt[50];
    
    switch (typeOfBet)
    {
        case 1:
            sprintf(betTxt, "%d", number);
            break;
        case 2:
            if (number == 1)
            {
                strcpy(betTxt, "odd");
            }
            else
            {
                strcpy(betTxt, "even");
            }
            break;
        case 3:
            if (number == 1)
            {
                strcpy(betTxt, "the first dozen");
            }
            else if (number == 2)
            {
                strcpy(betTxt, "the second dozen");
            }
            else
            {
                strcpy(betTxt, "the third dozen");
            }
            break;
        
        default:
            break;
    }
    
    float amount;
    printf("How much would you like to bet on %s: $", betTxt);
    scanf("%f", &amount);
    
    return amount;
}

//Returns random number
int spinWheel()
{
    int spin = 0;
    
    spin = rand() % 37;
    
    return spin;
}

//Figures winnings or losses based on the  wheel spin and bet information
float figureWinnings(int number, int typeOfBet, float amount)
{
    int result = 0;
    int wheelResult = spinWheel();
    
    printf("The wheel has stopped on %d\n", wheelResult);
    
    switch (typeOfBet)
    {
        case 1:
            if(number == wheelResult)
            {
                return amount * 36;
            }
            else
            {
                return amount * (-1);
            }
            break;
            
        case 2:
            if (wheelResult == 0)
            {
                return amount * (-1);
            }
            
            result = wheelResult % 2;
            
            if(result == 0 && number == 2)
            {
                return amount * 2;
            }
            else if(result != 0 && number == 1)
            {
                return amount * 2;
            }
            else
            {
                return amount * (-1);
            }
            break;
        case 3:
            if (wheelResult == 0)
            {
                return amount * (-1);
            }
            
            if (wheelResult <= 12)
            {
                result = 1;
                if (result == number)
                {
                    return amount * 3;
                }
                else
                {
                    return amount * (-1);
                }
            }
            else if (wheelResult > 12 && wheelResult < 25)
            {
                result = 2;
                if (result == number)
                {
                    return amount * 3;
                }
                else
                {
                    return amount * (-1);
                }
            }
            else
            {
                result = 3;
                if (result == number)
                {
                    return amount * 3;
                }
                else
                {
                    return amount * (-1);
                }
            }
        default:
            break;
    }
    
    return 0;
}
