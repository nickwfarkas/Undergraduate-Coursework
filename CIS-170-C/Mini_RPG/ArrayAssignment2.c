//
//
//  Homework 4 Program 2
//
//  Created by Nicholas Farkas on 11/05/19.
//
//  RPG Part 4
//

//Libraries
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Creates struct with viarables acting as character attributes
typedef struct character
{
    char userName[50];
    char genderName[50];
    char userTitle[50];
    char raceName[50];
    char className[50];
    int userAge;
    int userHeightFeet;
    int userHeightInches;
    int playerStats[6];
    struct character * next;
}CHARACTER;

//typedef for cleaner code

//Prototypes
void name(char *);
int gender(void);
void getGender(int, char *);
void title(char *);
int race(void);
void getRace(int, char *);
int class(void);
void getClass(int, char *);
int age(void);
int feet(void);
int inches(void);
int randomGenerator(void);
int generateCharacterStat(void);
void acceptStats(int *);
void printPlayerStats(int *);
void buffer(void);
CHARACTER createCharacter(int i);
void printView(CHARACTER[5], int);
void characterNumber(int);
char multCharacterValidation(char);

int main()
{
    printf("Welcome to Henry Ford's RPG!\n");
    
    CHARACTER party[5];
    
    CHARACTER * partyPoint = party;
    
    char terminator = 'y';
    int i = 0;
    int j;
    
    while ((tolower(terminator) == 'y') && (i < 5))
    {
        party[i] = createCharacter(i+1);
        i++;
        buffer();
        if (i == 5)
        {
            terminator = 'n';
        }
        else
        {
            printf("Would you likey to create another character (Maximum of 5 y or n)? ");
            scanf("%c", &terminator);
            terminator  = multCharacterValidation(terminator);
            buffer();
        }
    }
    
    for (j=0; j < i; j++)
    {
        printView(partyPoint, j);
    }
    
    
    return 0;
}

void printView(CHARACTER character[5], int i)
{
        printf("\n");
        
        printf("Character %d: ", i+1);
        
        printf("Welcome %s %s!\n", character[i].userName, character[i].userTitle);
        
        printf("Gender: %s\n", character[i].genderName);
        
        printf("Race: %s\n", character[i].raceName);
        
        printf("Class: %s\n", character[i].className);
        
        printf("Age: %d\n", character[i].userAge);
        
        printf("Height: %d'%d\"\n",character[i].userHeightFeet, character[i].userHeightInches);
        
        printPlayerStats(character[i].playerStats);
}

CHARACTER createCharacter(int i)
{
    CHARACTER newCharacter;
    
        characterNumber(i);
        name(newCharacter.userName);
        buffer();
        getGender(gender(), newCharacter.genderName);
        buffer();
        title(newCharacter.userTitle);
        getRace(race(), newCharacter.raceName);
        getClass(class(), newCharacter.className);
        newCharacter.userAge = age();
        newCharacter.userHeightFeet = feet();
        newCharacter.userHeightInches = inches();
        acceptStats(newCharacter.playerStats);
    
    return newCharacter;
}

char multCharacterValidation(char terminator)
{
    while (tolower(terminator) != 'y' && tolower(terminator) != 'n')
    {
        buffer();
        printf("%c is not a valid response please try again\n", terminator);
        printf("Would you likey to create another character (Maximum of 5 y or n)? ");
        scanf("%c", &terminator);
    }
    
    return terminator;
}

void characterNumber(int i)
{
    switch (i) {
        case 1:
            printf("Please enter the following information about your character:\n");
            break;
        case 2:
            printf("Please enter the following information about your 2nd character:\n");
            break;
        case 3:
            printf("Please enter the following information about your 3rd character:\n");
            break;
        case 4:
            printf("Please enter the following information about your 4th character:\n");
            break;
        case 5:
            printf("Please enter the following information about your 5th and final character:\n");
            break;
        default:
            break;
    }
}

//Clears Buffer
void buffer()
{
    char buff;
    scanf("%c", &buff);
}

void name(char * name)
{
    printf("What is your character’s name: ");
    scanf("%[^\n]s", name);
}

void title(char * title)
{
    printf("What is your character’s title: ");
    scanf("%[^\n]s", title);
}

//Gets and validates gender from user
int gender()
{
    int gender = 0;
    
    printf("What is your characters Gender?\n");
    printf("1. Male\n2. Female\n3. Non-binary\n");
    scanf("%i", &gender);
    
    //Validates user entered 1-3
    while (gender < 1 || gender > 3)
    {
        printf("You entered an invalid selection.\n");
        printf("What is your characters Gender?\n");
        printf("1. Male\n2. Female\n3. Non-binary\n");
        scanf("%i", &gender);
    }
    
    return gender;
}

//Converts user entered interger into gender
void getGender(int numGender, char genderName[50])
{
    switch (numGender)
    {
        case 1:
            strcpy(genderName, "Male");
            break;
        case 2:
            strcpy(genderName, "Female");
            break;
        case 3:
            strcpy(genderName,"Non-Binary");
            break;
        default:
            break;
    }
}

//Gets and validates race from user
int race()
{
    int race = 0;
    
    printf("What is your character's race: \n");
    printf("1.  Dragonborn\n2.  Dwarf\n3.  Elf\n4.  Goblin\n5.  Halfling\n6.  Half-Elf\n7.  Half-Orc\n8.  Human\n9.  Tiefling\n");
    scanf("%i", &race);
    
    //Validates user entered 1-9
    while (race < 1 || race > 9)
    {
        printf("You entered an invalid selection.\n");
        printf("What is your character's race: \n");
        printf("1.  Dragonborn\n2.  Dwarf\n3.  Elf\n4.  Goblin\n5.  Halfling\n6.  Half-Elf\n7.  Half-Orc\n8.  Human\n9. Tiefling\n");
        scanf("%i", &race);
    }
    
    return race;
}

//Converts user entered interger into race
void getRace(int numRace, char * race)
{
    switch (numRace)
    {
        case 1:
            strcpy(race, "Dragonborn");
            break;
        case 2:
            strcpy(race, "Dwarf");
            break;
        case 3:
            strcpy(race, "Elf");
            break;
        case 4:
            strcpy(race,"Goblin");
            break;
        case 5:
            strcpy(race, "Halfling");
            break;
        case 6:
            strcpy(race, "Half-elf");
            break;
        case 7:
            strcpy(race, "Half-Orc");
            break;
        case 8:
            strcpy(race, "Human");
            break;
        case 9:
            strcpy(race, "Tiefling");
            break;
        default:
            break;
    }
}

//Gets and validates class from user
int class()
{
    int class = 0;
    
    printf("What is your character's class: \n");
    printf("1.  Bard\n2.  Cleric\n3.  Druid\n4.  Fighter\n5.  Paladin\n6.  Ranger\n7.  Rogue\n8.  Sorcerer\n9.  Witch\n10.  Wizard\n");
    scanf("%i", &class);
    
    //Validates user entered 1-10
    
    while (class < 1 || class > 10)
    {
        printf("You entered an invalid selection.\n");
        printf("What is your character's class: \n");
        printf("1.  Bard\n2.  Cleric\n3.  Druid\n4.  Fighter\n5.  Paladin\n6.  Ranger\n7.  Rogue\n8.  Sorcerer\n9.  Witch\n10.  Wizard\n");
        scanf("%i", &class);
    }
    
    return class;
}

//Converts user entered interger into class
void getClass(int numClass, char * class)
{
    switch (numClass)
    {
        case 1:
            strcpy(class, "Bard");
            break;
        case 2:
            strcpy(class, "Cleric");
            break;
        case 3:
            strcpy(class, "Druid");
            break;
        case 4:
            strcpy(class, "Fighter");
            break;
        case 5:
            strcpy(class, "Paladin");
            break;
        case 6:
            strcpy(class, "Ranger");
            break;
        case 7:
            strcpy(class, "Rogue");
            break;
        case 8:
            strcpy(class, "Sorcerer");
            break;
        case 9:
            strcpy(class, "Witch");
            break;
        case 10:
            strcpy(class, "Wizard");
            break;
        default:
            break;
    }
}

int age()
{
    int age = 0;
    
    printf("What is your characters age in years: \n");
    scanf("%i", &age);
    
    return age;
}

//Gets height in feet from user
int feet()
{
    int feet = 0;
    
    printf("What is your character's height in feet: \n");
    scanf("%i", &feet);
    
    return feet;
}

//Gets remaining height in inches from user and validates it
int inches()
{
    int inches = 0;
    
    printf("What is your character's inches: \n");
    scanf("%i", &inches);
    
    //Validates user entered 0-11
    
    while (inches < 0 || inches > 11)
    {
        printf("%d is not a valid height in inches", inches);
        printf("What is your character's inches: \n");
        scanf("%d", &inches);
    }
    
    return inches;
}

//Genearates random array of 4 and adds top 3 values
int generateCharacterStat()
{
    int stat[4];
    int i, key, j;
    
    //Generates array of 4 random numbers
    for (i = 0; i < 4; i++)
    {
        stat[i] = (rand() % 6) + 1;
    }
    
    //Sorts genderated array
    for (i = 1; i < 4; i++)
    {
        key = stat[i];
        j = i - 1;
        
        while (j >= 0 && stat[j] > key)
        {
            stat[j + 1] = stat[j];
            j = j - 1;
        }
        stat[j + 1] = key;
    }
    
    //Takes top 3 values and sums them up
    int myStat = stat[0] + stat[1] + stat[2];
    
    return myStat;
}

//Creates Random array of 6 user stats and asks user if they accept
void acceptStats(int userArray[6])
{
    srand(((unsigned)time(0)));
    
    int userAnswer = 2;
    int i = 0;
    
    //Runs until sentinal value is entered
    
    while (userAnswer != 1)
    {
        if(i == 0)
        {
            printf("The following stats were generated by the program:\n");
        }
        else
        {
            printf("The following stats were re-generated by the program:\n");
        }
        
        //Puts randomly generated values in array
        
        int array[6] = {generateCharacterStat(), generateCharacterStat(), generateCharacterStat(), generateCharacterStat(), generateCharacterStat(), generateCharacterStat()};
        
        //Prints array values
        
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
                case 0:
                    printf("Strength: %d, ", array[0]);
                    break;
                case 1:
                    printf("Dexterity: %d, ", array[1]);
                    break;
                case 2:
                    printf("Constitution: %d, ", array[2]);
                    break;
                case 3:
                    printf("Intelligence: %d, ", array[3]);
                    break;
                case 4:
                    printf("Wisdom: %d, ", array[4]);
                    break;
                case 5:
                    printf("Charisma: %d\n", array[5]);
                    break;
                default:
                    break;
            }
            
            
        }
        
        // Asks for user to accept stats
        
        printf("Do you accept these stats?\n 1. Yes\n 2. No\n");
        scanf("%d", &userAnswer);
        
        // Valids user acceptance status
        
        while (userAnswer != 1 && userAnswer != 2)
        {
            printf("Not a valid choice please enter 1 or 2\n");
            printf("Do you accept these stats?\n 1. Yes\n 2. No\n");
            scanf("%d", &userAnswer);
        }
        
        // Stores array value location in pointer
        
        for (i = 0; i < 6; i++)
        {
            userArray[i] = array[i];
        }
    }
}


// Prints accepted user stats array

void printPlayerStats(int array[6])
{
    int i;
    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
            case 0:
                printf("Strength: %d\n", array[0]);
                break;
            case 1:
                printf("Dexterity: %d\n", array[1]);
                break;
            case 2:
                printf("Constitution: %d\n", array[2]);
                break;
            case 3:
                printf("Intelligence: %d\n", array[3]);
                break;
            case 4:
                printf("Wisdom: %d\n", array[4]);
                break;
            case 5:
                printf("Charisma: %d\n", array[5]);
                break;
            default:
                break;
        }
        
        
    }
}


