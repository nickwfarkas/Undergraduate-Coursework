//
//
//  Homework 3 Program 1
//
//  Created by Nicholas Farkas on 10/30/19.
//
//  Takes user inputed numbers and stores the values
//  Prints intial values, Prints Smallest and Largest values,and Prints sorted values
//

#include <stdio.h>

//Prototypes

int * inputArray(void);
int * sortArray(void);
void printArray(int *);
void largest(int *);
void smallest(int *);


int main()
{
    int * sortedAr = sortArray();
    
    smallest(sortedAr);
    largest(sortedAr);
    
    printf("Sorted Array: ");
    printArray(sortedAr);
    
    return 0;
}

//User enters inital Array and Print entered array back to user
int * inputArray()
{
    
    static int ar[10];
    
    int i = 0;
    
    for (i = 0; i < 10; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &ar[i]);
    }
    
    printf("Array: ");
    printArray(ar);

    return ar;
}

// Prints largest value in array
void largest(int * ar)
{
    printf("Largest: %d\n", *(ar + 9));
}

// Prints smallest value in array
void smallest(int * ar)
{
    printf("Smallest: %d\n", *(ar));
}

// Sorts inputted array from least to greatest
int * sortArray()
{
    int * ar = inputArray();

    int i, j, a;
    
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (*(ar + i) > *(ar + j))
            {

                a =  *(ar + i);
                *(ar + i) = *(ar + j);
                *(ar + j) = a;
            }
        }
    }

    
    return ar;
}

// Prints any array that has 10 values
void printArray(int * ar)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            printf("%d\n", *(ar + i));
        }
        else
        {
            printf("%d, ", *(ar + i));
        }
    }
}
