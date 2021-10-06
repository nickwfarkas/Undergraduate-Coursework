//
//
//  Homework 3 Program 2
//
//  Created by Nicholas Farkas on 10/30/19.
//
//  Takes user inputed string and stores it
//  Prints number of each vowel and total of vowels
//

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void getString(char [100]);
int getCount(char *, char);

int main()
{
	//Stores User Entered string here
	char string[100];
	getString(string);
	
	//Gets count of each vowel and total and stores them in array
	
	int vowels[6] =
	{
		getCount(string, 'a'),
		getCount(string, 'e'),
		getCount(string, 'i'),
		getCount(string, 'o'),
		getCount(string, 'u'),
		(
		 getCount(string, 'a') + getCount(string, 'e') +
		 getCount(string, 'i') + getCount(string, 'o') +
		 getCount(string, 'u')
		)
	};
	
	//For making printing easier
	
	char letters[6] = {'A', 'E', 'I', 'O', 'U'};
	
	
	//Prints counts for each vowel and total
	printf("Totals:\n");
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			printf("Total: ");
			printf("%d\n", vowels[i]);
		}
		else
		{
			printf("%c's: ",letters[i]);
			printf("%d\n", vowels[i]);
		}
	}
	
    return 0;
}

//User enters string
void getString(char string[100])
{
    printf("Enter a string:" );
    scanf("%[^\n]s", string);
}

//Gets letter count based on vowell letter
int getCount(char * userEntry, char letter)
{
	
	int count = 0;
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        if(tolower(userEntry[i]) == letter)
        {
            count++;
        }
    }
    
    return count;
}


