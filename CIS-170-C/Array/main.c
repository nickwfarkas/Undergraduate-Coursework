//
//  main.c
//  InClass3
//
//  Created by Nicholas Farkas on 10/16/19.
//  Copyright © 2019 Nicholas Farkas. All rights reserved.
//

#include <stdio.h>

int main()
{
    int newArray[9];
    int originalArray[9] = defineArray(originalArray);
    for (int i = 0; i < 9; i++)
    {
        printf("Please enter a value into the array: ");
        scanf("%d",&originalArray[i]);
    }
    
    int d = 8;
    for (int l = 0; l < 9; l++)
    {
        newArray[l] = originalArray[d];
        d--;
    }
    
    return 0;
}

int defineArray(int array[9])
{
    for (int i = 0; i < 9; i++)
    {
        printf("Please enter a value into the array: ");
        scanf("%d",&array[i]);
    }
    
    return *array;
}

void printArray(int array[9])
{
    for (int i = 0; i < 9; i++ )
    {
        if(i == 0)
        {
            printf("The array has the values: %d, ", array[i]);
        }
        else if (i == 8)
        {
            printf("and %d\n", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }
}

int copyArray(int originalArray[9], int copyArray[9])
{
    int a = 0;
    for (int j = 0; j < 9; j++)
    {
        copyArray[a] = originalArray[j];
        a++;
    }
    return *copyArray;
}

int reverseArray(int originalArray[9], int newArray[9])
{
    int i = 8;
    for (int l = 0; l < 9; l++)
    {
        newArray[l] = originalArray[i];
        i--;
    }
    return *newArray;
}
