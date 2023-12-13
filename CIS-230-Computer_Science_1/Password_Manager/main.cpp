//
//  main.cpp
//  Password_Manager
//
//  Created by Nicholas Farkas on 4/24/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "UserPasswordManager.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int validateChoice();

int main()
{
    int choice;
    
    UserPasswordManager userPassword;
    
    cout<<endl<<"Please enter\n1. To change your password\n2. To Login\nChoice: ";
    choice = validateChoice();
    
    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
                userPassword.changePassword();
                cout<<"Choice: ";
                cin>>choice;
                break;
            case 2:
                if (userPassword.verifyPassword())
                {
                    cout<<"Success"<<endl;
                }
                else
                {
                    cout<<"Incorrect"<<endl;
                }
                cout<<"Choice: ";
                cin>>choice;
                break;
            case 3:
                break;
            default:
                cout<<"Not a valid entry"<<endl;
                break;
        }
    }
    
    cout<<"Thank you"<<endl;
    
    return 0;
}

int validateChoice()
{
    int choice;
    cin>>choice;
    
    if (cin.fail())
    {
        cin.clear();
        cout<<"Invalid entry please try again!"<<endl;
        validateChoice();
    }
    
    if (choice > 3 || choice < 1)
    {
        cout<<"Please enter values 1, 2, or 3"<<endl;
        validateChoice();
    }
    
    return choice;
}
