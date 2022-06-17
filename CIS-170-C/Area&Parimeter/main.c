//
//  In-Class Assignment 1: Area and Perimeter with Functions
//
//  Created by Nicholas Farkas & Jake Reich on 9/11/19.
//
//

//libraries
#include <stdio.h>

//prototype
void calc(void);
float getWidth(void);
float getLength(void);

//Where program will start
int main()
{
    calc();
    return 0;
}

//Gets length from user
float getLength()
{
    float length = 0;
    printf("Please enter length: ");
    scanf("%f", &length);
    return length;
}

//Gets Width from user
float getWidth()
{
    float width = 0.0;
    printf("Please enter length: ");
    scanf("%f", &width);
    return width;
}

//calculates Area and Parameter and prints it out
void calc()
{
    float width = 0;
    float length = 0;
    width = getWidth();
    length = getLength();
    
    printf("The Area is: %.2f\n",(width * length));
    printf("The Parimeter is: %.2f\n", ((width * 2)+(length * 2)));
    
}
