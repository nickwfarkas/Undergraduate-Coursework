//
//  main.cpp
//  Boolean_Algebra
//
//  Created by Nicholas Farkas on 4/28/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "TruthValue.hpp"

using namespace std;

char getStartingValue();
char validateStartingValue(char value);
string getUserEntry(TruthValue initial);
string validateUserEntry(string entry, TruthValue initial);
TruthValue isolateTruthValue(string entry);
char isolateOperator(string entry);
TruthValue multiplyTruthValue(TruthValue initial, TruthValue entry);
TruthValue addTruthValue(TruthValue initial, TruthValue entry);
void calculateAndOutput(TruthValue initial);
string getUserEntryAgain(TruthValue initial);
void printLetterTruthTable();
void printbooleanTruthTable();
int main()
{
    TruthValue initial(getStartingValue());
    
    cout<<"Please only use one operation at a time"<<endl;
    cout<<"Use + for addition and * for multiplication"<<endl;
    cin.ignore(100, '\n');
    
    calculateAndOutput(initial);
    
    return 0;
}

void calculateAndOutput(TruthValue initial)
{
    bool again = true;
    string userEntry;
    string buff;
    
    string userChoice;
    userEntry = getUserEntry(initial);
    
    while (again)
    {
        if (isolateOperator(userEntry) == '*')
        {
            cout<<initial<<userEntry;
            initial = multiplyTruthValue(initial, isolateTruthValue(userEntry));
            cout<<" = "<<initial<<endl;
        }
        else
        {
            cout<<initial<<userEntry;
            initial = addTruthValue(initial, isolateTruthValue(userEntry));
            cout<<" = "<<initial<<endl;
        }
        
        cout<<endl<<"Please enter:"<<endl;
        cout<<"1 to continue"<<endl;
        cout<<"2 to change your starting truth value"<<endl;
        cout<<"3 for a print out T and F example truth table and continue"<<endl;
        cout<<"4 for a print out boolean example truth table and continue"<<endl;
        cout<<"or any other key to quit: ";
        getline(cin, userChoice);
        
        if (userChoice == "1")
        {
            again = true;
            cout<<endl<<"Press enter to continue"<<endl;
            userEntry = getUserEntryAgain(initial);
            
        }
        else if (userChoice == "2")
        {
            initial.setValue(getStartingValue());
            userEntry = getUserEntryAgain(initial);
            again = true;
        }
        else if (userChoice == "3")
        {
            printLetterTruthTable();
            again = true;
            cout<<endl<<"Press enter to continue"<<endl;
            userEntry = getUserEntryAgain(initial);
        }
        else if (userChoice == "4")
        {
            printbooleanTruthTable();
            again = true;
            cout<<endl<<"Press enter to continue"<<endl;
            userEntry = getUserEntryAgain(initial);
        }
        else
        {
            cout<<"Your ending truth value was "<<initial<<endl;
            cout<<"Thank you for using the boolean calculator!"<<endl;
            again = false;
        }
    }
}

char getStartingValue()
{
    char value;
    
    cout<<"What is your starting truth value: ";
    cin>>value;
    if (cin.fail())
    {
        cin.ignore(100, '\n');
        cin.clear();
        cout<<"Not a valid entry"<<endl;
        value = getStartingValue();
    }
    
    return validateStartingValue(value);
}

char validateStartingValue(char value)
{
    if
    (
     tolower(value) != 't' && tolower(value) != 'f' &&
     tolower(value) != '1' && tolower(value) != '0'
    )
    {
        cout<<"Please enter a truth value in format 1/0 or T/F"<<endl;
//        cin.ignore(100,'\n');
        value = getStartingValue();
    }
    
    return value;
}

string getUserEntry(TruthValue initial)
{
    string entry;
    cout<<initial;
    getline(cin, entry);
    
    return validateUserEntry(entry, initial);
}

string getUserEntryAgain(TruthValue initial)
{
    cin.ignore(100,'\n');
    string entry;
    cout<<initial;
    getline(cin, entry);
    
    return validateUserEntry(entry, initial);
}

string validateUserEntry(string entry, TruthValue initial)
{
    if (entry.size() != 2)
    {
        cout<<"Please enter + or * followed by a valid truth value (1,0,T,F)"<<endl;
        entry = getUserEntry(initial);
    }
    else if (entry[0] != '*' && entry[0] != '+')
    {
        cout<<"Please enter + for addition or * for multiplication followed by your truth value"<<endl;
        entry = getUserEntry(initial);
    }
    else if
    (
     tolower(entry[1]) != 't' && tolower(entry[1]) != 'f' &&
     tolower(entry[1]) != '1' && tolower(entry[1]) != '0'
    )
    {
        cout<<"Please enter a truth value in format 1/0 or T/F"<<endl;
        entry = getUserEntry(initial);
    }
    
    return entry;
}

TruthValue isolateTruthValue(string entry)
{
    return TruthValue(entry[1]);
}

char isolateOperator(string entry)
{
    return entry[0];
}

TruthValue multiplyTruthValue(TruthValue initial, TruthValue entry)
{
    return initial * entry;
}

TruthValue addTruthValue(TruthValue initial, TruthValue entry)
{
    return initial + entry;
}

void printLetterTruthTable()
{
    TruthValue values[8][3] =
    {
        {TruthValue('T'), TruthValue('T'), TruthValue('T')},
        {TruthValue('T'), TruthValue('T'), TruthValue('F')},
        {TruthValue('T'), TruthValue('F'), TruthValue('T')},
        {TruthValue('T'), TruthValue('F'), TruthValue('F')},
        {TruthValue('F'), TruthValue('T'), TruthValue('T')},
        {TruthValue('F'), TruthValue('T'), TruthValue('F')},
        {TruthValue('F'), TruthValue('F'), TruthValue('T')},
        {TruthValue('F'), TruthValue('F'), TruthValue('F')}
    };
    TruthValue x('0');
    TruthValue y('0');
    TruthValue z('0');
    cout<<endl<<"A(x,y) = x+y"<<endl;
    cout<<"B(x,y) = x*y"<<endl;
    cout<<"C(x,y,z) = x+y+z"<<endl;
    cout<<"D(x,y,z) = x*y*z"<<endl;
    cout<<"E(x,y,z) = x+yz"<<endl;
    cout<<"F(x,y,z) = x(y+z)"<<endl;
    cout<<"G(x,y,z) = (x+y)(x+z)"<<endl;
    
    cout<<endl;
    cout<<" | "<<"x"<<" | "<<"y"<<" | "<<"z"<<" | "<<"A"<<" | "<<"B"<<" | "<<"C"<<" | "<<"D"<<" | "<<"E"<<" | "<<"F"<<" | "<<"G"<<" | "<<endl;
    cout<<" -----------------------------------------"<<endl;
    for (int i = 0; i < 8; i++)
    {
        x = values[i][0];
        y = values[i][1];
        z =values[i][2];
        cout<<" | "<<x<<" | "<<y<<" | "<<z<<" | "
            <<x+z<<" | "<<x*z<<" | "<<(x+y)+z<<" | "
            <<(x*y)*z<<" | "<<x+(y*z)<<" | "<<x*(y+z)<<" | "
            <<(x*x)+(x*z)+(y*x)+(y*z)<<" | "<<
        endl;
    }
}

void printbooleanTruthTable()
{
    TruthValue values[8][3] =
    {
        {TruthValue('1'), TruthValue('1'), TruthValue('1')},
        {TruthValue('1'), TruthValue('1'), TruthValue('0')},
        {TruthValue('1'), TruthValue('0'), TruthValue('1')},
        {TruthValue('1'), TruthValue('0'), TruthValue('0')},
        {TruthValue('0'), TruthValue('1'), TruthValue('1')},
        {TruthValue('0'), TruthValue('1'), TruthValue('0')},
        {TruthValue('0'), TruthValue('0'), TruthValue('1')},
        {TruthValue('0'), TruthValue('0'), TruthValue('0')}
    };
    
    TruthValue x('0');
    TruthValue y('0');
    TruthValue z('0');
    
    cout<<endl<<"A(x,y) = x+y"<<endl;
    cout<<"B(x,y) = x*y"<<endl;
    cout<<"C(x,y,z) = x+y+z"<<endl;
    cout<<"D(x,y,z) = x*y*z"<<endl;
    cout<<"E(x,y,z) = x+yz"<<endl;
    cout<<"F(x,y,z) = x(y+z)"<<endl;
    cout<<"G(x,y,z) = (x+y)(x+z)"<<endl;
    
    cout<<endl;
    cout<<" | "<<"x"<<" | "<<"y"<<" | "<<"z"<<" | "<<"A"<<" | "<<"B"<<" | "<<"C"<<" | "<<"D"<<" | "<<"E"<<" | "<<"F"<<" | "<<"G"<<" | "<<endl;
    cout<<" -----------------------------------------"<<endl;
    
    for (int i = 0; i < 8; i++)
    {
        x = values[i][0];
        y = values[i][1];
        z =values[i][2];
        cout<<" | "<<x<<" | "<<y<<" | "<<z<<" | "
        <<x+z<<" | "<<x*z<<" | "<<(x+y)+z<<" | "
        <<(x*y)*z<<" | "<<x+(y*z)<<" | "<<x*(y+z)<<" | "
        <<(x*x)+(x*z)+(y*x)+(y*z)<<" | "<<
        endl;
    }
}
