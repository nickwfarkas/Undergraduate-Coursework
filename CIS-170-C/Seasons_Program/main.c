//
//  main.c
//  Seasons Program
//
//  Created by Nicholas Farkas on 9/18/19.
//  Copyright © 2019 Nicholas Farkas. All rights reserved.
//

#include <stdio.h>
char menu(void);

int main()
{
    char selection;
    selection  = menu();
    
    switch (selection) {
        case 'A':
            printf("Your favorite season is Spring!\n");
            break;
        case 'B':
            printf("Your favorite season is Summer!\n");
            break;
        case 'C':
            printf("Your favorite season is Fall!\n");
            break;
        case 'D':
            printf("Your favorite season is Winter!\n");
            break;
        default:
            printf("That is an invalid entry and is not a season.");
            break;
    }
    printf("Thank you and Goodbye!");
    
    return 0;
}

char menu()
{
    char season;
    
    printf("Please Select Your favorite season: \n");
    printf("A. Spring \n");
    printf("B. Summer \n");
    printf("C. Fall \n");
    printf("D. Winter \n");
    printf("Please enter your selection here: ");
    scanf("%c", &season);

    return season;
}
