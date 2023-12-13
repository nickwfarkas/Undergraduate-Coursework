//
//  Assignment 1: Ice Cream Program
//
//  Created by Nicholas Farkas on 1/21/20.
//
//  User inputs number of scoops for the month of each flavor and prints report
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;

//Data object with name and number of scoop attributes
class Scoop
{
    public:
        string name;
        int scoopNum;

//Member functions to help printing specific attributes
        void printName()
        {
            cout<<name;
        }

        void printScoop()
        {
            cout<<scoopNum;
        }
};

//Prototypes
void userEntry(Scoop *);
void printView(Scoop *);
void sortScoops(Scoop *);
void swapArray(Scoop *, Scoop *);
void printSigNum(string, Scoop *, int);
bool userInputValidation();

int main()
{
    Scoop scoopStore[5];
    
    cout <<"Welcome to Scoop Tracker" << endl;
    cout <<"Please enter the number of scoops of each flavor for a Scoop Report!" << endl << endl;
    
    userEntry(scoopStore);
    
    sortScoops(scoopStore);
    
    printView(scoopStore);
    
    return 0;
}

//Gets user entered number of scoops and stores them in array
void userEntry(Scoop scoopStore[5])
{
//Defaults the names in the array of Scoops
    scoopStore[0].name = "Vanilla";
    scoopStore[1].name = "Butter Pecan";
    scoopStore[2].name = "Superman";
    scoopStore[3].name = "Chocolate Fudge";
    scoopStore[4].name = "Strawberry";
    
    bool validation;

    for (int i = 0; i < 5; i++)
    {
        validation = true;
        
        do
        {
            if (validation  == false)
            {
                cout<<"That is not a valid entry please try again!"<<endl;
            }
            
            cout<<"Please enter the number of scoops for ";
            scoopStore[i].printName();
            cout<<": ";
            cin >> scoopStore[i].scoopNum;
            
            validation = userInputValidation();
            
        }while (validation == false);
    }
}

//Prints all needed Report information to the console
void printView(Scoop scoopStore[5])
{
    int total = 0;
    int greatestNum = scoopStore[4].scoopNum;
    int leastNum = scoopStore[0].scoopNum;
    
    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout<<"Total ";
        scoopStore[i].printName();
        cout << " scoops sold: ";
        scoopStore[i].printScoop();
        cout<<endl;
        total += scoopStore[i].scoopNum;
    }
    
    cout<<"Total scoops sold for the month: " <<total<<endl;
    
    printSigNum("Best", scoopStore, greatestNum);
    
    printSigNum("Worst", scoopStore, leastNum);
}

//Function to print all Best and Worst selling Flavors
void printSigNum(string type, Scoop scoopStore[5], int sigNum)
{
    for (int i = 0; i < 5; i++)
    {
        if (scoopStore[i].scoopNum == sigNum)
        {
            cout << type << " selling scoops for the month: ";
            scoopStore[i].printName();
            cout << endl;
        }
    }
}

//Sorts the array of scoops using the primitive bubble sort
void sortScoops(Scoop scoopStore[5])
{
    int i, j;
    Scoop temp;
    
    for (i = 0; i < 5; i++)
        
        for (j = 0; j < 5-i-1; j++)
        {
            if (scoopStore[j].scoopNum > scoopStore[j+1].scoopNum)
            {
                swapArray(&scoopStore[j], &scoopStore[j+1]);
            }
        }
}

//Swaps numbers in array used for bubble sort
void swapArray(Scoop *array, Scoop *array1)
{
    Scoop temp = *array;
    *array = *array1;
    *array1 = temp;
}

//Returns false if user typed in a error throwing value
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
