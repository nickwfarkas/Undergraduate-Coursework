//
//  Assignment 1: Parking Garage
//
//  Created by Nicholas Farkas on 1/20/20.
//
//  User inputs number of hours in a decimal format and program calculates parking charge
//

#include<iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;

//Prototypes
float userTimeValidation();
float userTime();
float calculateCharge();
void printCharge();
string userEntrySentinal();
bool userInputValidation();

int main()
{
    printCharge();
    return 0;
}

//Gets time parked from the user
float userTime()
{
    float time;
    
    cout <<"Please enter your how many hours you were parked in a decimal format: ";
    cin >> time;
    
    return time;
}

//Validates Time parked aquired from the user
float userTimeValidation()
{
    float time;
    
    time = userTime();
    
    while(time > 24 || time <= 0)
    {
        if(userInputValidation() == false)
        {
            cout<<"That is not a valid entry please try again"<< endl;
        }
        else
        {
            cin.ignore(100, '\n');
            cout<<"That is not a valid entry please try again"<< endl;
        }

        time = userTime();
    }
    return time;
}

//Calculates amount charged based on time
float calculateCharge()
{
    float time = 0;
    
    time = ceil(userTimeValidation());
    
    float charge = 2;
    
    if(time > 3)
    {
        charge = 2 + ((.5) * (time - 3));
        
        if (charge > 10)
        {
            charge = 10;
        }
    }
    
    return charge;
}

//Asks user if they want to calculate more parking and either restarts the program or stops it
string userEntrySentinal()
{
    string userEntry;
    
    cout<<"Would you like to calculate more parking (y or n): ";
    cin >> userEntry;
    
    while ((tolower(userEntry[0]) != 'y') && (tolower(userEntry[0]) != 'n'))
    {
        cout << "That is not a valid entry please try again!" << endl;
        cin.clear();
        cin.ignore(100,'\n');
        
        cout<<"Would you like to calculate more parking (y or n): ";
        cin >> userEntry;
        
        if (userInputValidation() == false)
        {
            userEntry = 'z';
        }
    }
    
    return userEntry;
}

//Prints final information to the screen
void printCharge()
{
    string userEntry = "y";

    while (tolower(userEntry[0]) == 'y')
    {
        float charge = calculateCharge();
        cout<<fixed<<setprecision(2)<<"Your charge for the day is $" << charge << endl;
        userEntry = userEntrySentinal();
    }
    
    cout<<"Have a great day!"<<endl;
}

//Checks if user entered values will throw a error
bool userInputValidation()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        return false;
    }
    else
    {
        return true;
    }
}

