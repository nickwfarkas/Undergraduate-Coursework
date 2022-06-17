/*
    Nick Farkas
 
 CIS 170-70
 
 Battleship Part 2:
 User Menu
 Game Setup
 Firing Guns
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void menu(char *, int);
int getLocation(char);
void setupBoard(char [8][8], int);
void printBoard(char [8][8]);
int mapColumnToValue(char);

int main()
{
    //Variable Declaration Block
    char playerOne[50] = "";
    char playerTwo[50] = "";
    int xFirePos = 0;
    int yFirePos = 0;
    
    char playerOneBoard[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            playerOneBoard[i][y]  = '*';
        }
    }
    
    char playerOneShotBoard[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            playerOneShotBoard[i][y]  = '*';
        }
    }
    
    char playerTwoBoard[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            playerTwoBoard[i][y]  = '*';
        }
    }
    
    char playerTwoShotBoard[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            playerTwoShotBoard[i][y]  = '*';
        }
    }
    
    menu(&playerOne, 1);
    menu(&playerTwo, 2);
    
    printf("Player 1: %s\n", playerOne);
    printf("Player 2: %s\n", playerTwo);
    
    setupBoard(playerOneBoard, 1);
    
    return 0;
}

void menu(char player[], int playerNum)
{
    char buffer;
    
    printf("Welcome to HFCC's Battleship!\n");
    printf("Prepare for ship to ship combat!\n");
    printf("Enter your name player %d: ", playerNum);
    scanf("%s", player);
    //scanf("%c", &buffer);
}

void setupBoard(char board[][8], int playerNum)
{
    printf ("Player %d, your board currently looks like this: \n", playerNum);
    printBoard(board);
}

void printBoard(char board[8][8])
{
    printf ("\t");
    int i = 1;
    int j = 0;
    
//    for (i = 1; i <= 8; i++)
//    {
//        printf ("%d\t", i);
//    }
    
    printf("A\tB\tC\tD\tE\tF\tG\tH");
    
    printf ("\n");
    
    for (i = 0; i < 8; i++)
    {
        printf ("%d\t", i + 1);
        for (j = 0; j < 8; j++)
        {
            printf ("%c\t", board[i][j]);
        }
        printf ("\n\n");
    }
}

int getLocation(char axis)
{
    char position;
    int positionValue;

    if (axis == 'x')
    {
        printf("Enter a column value A - H: ");
        scanf("%c", &position);
        
        positionValue = mapColumnToValue(position);
        while (mapColumnToValue(position) == -1)
        {
            printf("%c was not a valid entry.\n", position);
            printf("Please enter an uppercase A - H: ");
            scanf("%c",  &position);
            positionValue = mapColumnToValue(position);
        }
    }
    else
    {
        printf("Enter a row value 1 - 8: ");
        scanf("%d", &positionValue);
        
        while (positionValue <  1 || positionValue > 8)
        {
            printf("%d was not a valid entry.\n", positionValue);
            printf("Please enter a value between 1 - 8: ");
            scanf("%d", &positionValue);
        }
        positionValue--;
    }
    return positionValue;
}

int mapColumnToValue(char position)
{
    switch (toupper(position)) {
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
        default:
            return -1;
            break;
    }
}

