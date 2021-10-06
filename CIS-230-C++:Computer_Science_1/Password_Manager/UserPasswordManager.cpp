//
//  UserPasswordManager.cpp
//  Password_Manager
//
//  Created by Nicholas Farkas on 4/24/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "UserPasswordManager.hpp"
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>

bool checkLength(string password);
bool checkLowercase(string password);
bool checkUppercase(string password);
bool checkDigit(string password);
bool checkSpecialCharacter(string password);
bool isSpecial(char character);
bool checkIllegalValue(string password);
bool checkOldPassword(string password, vector<string> oldPasswords);
int sumDigits(string password);
int sumUppercase(string password);
int sumLowercase(string password);
char calculateDigits(char value, int offset);
char calculateLowercaseCharacter(char value, int offset);
char calculateUppercaseCharacter(char value, int offset);
int charToDigit(char digit);

UserPasswordManager::UserPasswordManager()
{
    createPassword();
}

void UserPasswordManager::createPassword()
{
    string password;
    
    _validPassword = false;
    
    while (!_validPassword)
    {
        cout<<"Please enter a password: ";
        getline(cin, password);
        _validPassword = validatePassword(password);
    }
    
    _currentPassword = encryptPassword(password);
}

bool UserPasswordManager::verifyPassword()
{
    string password;
    cin.ignore(100, '\n');
    cout<<"Please enter your password: ";
    getline(cin, password);
    
    if (encryptPassword(password).compare(_currentPassword) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UserPasswordManager::changePassword()
{
    string password;
    
    _validPassword = false;
    
    cin.ignore(100, '\n');
    
    while (!_validPassword)
    {
        cout<<"Please enter a new password: ";
        getline(cin, password);
        if (encryptPassword(password).compare(_currentPassword) == 0)
        {
            cout<<"New passwords can't be the same as current ones"<<endl;
            _validPassword = false;
        }
        else
        {
            _validPassword = validatePassword(password);
        }
    }
    
    _oldPassword.insert(_oldPassword.begin(), _currentPassword);
    
    cout<<"Password was successfully changed"<<endl;
    
    _currentPassword = encryptPassword(password);
}

bool UserPasswordManager::validatePassword(string password)
{
    if (
        checkOldPassword(password, _oldPassword)*checkLength(password)*checkLowercase(password)*checkUppercase(password)*checkDigit(password)*checkSpecialCharacter(password)*checkIllegalValue(password)
        )
    {
        return true;
    }
    else
    {
        cout<<"Password was not changed"<<endl;
        return false;
    }
}

string UserPasswordManager::encryptPassword(string password)
{
    string lowerOffsetStr;
    string upperOffsetStr;
    int digitOffset = sumDigits(password);
    int upperOffset = sumUppercase(password);
    int lowerOffset = sumLowercase(password);

    for (int i = 0; i < password.size(); i++)
    {
        if (isdigit(password[i]))
        {
            password[i] = calculateDigits(password[i], digitOffset);
        }
        else if (islower(password[i]))
        {
            password[i] = calculateLowercaseCharacter(password[i], lowerOffset);
        }
        else if (isupper(password[i]))
        {
            password[i] = calculateUppercaseCharacter(password[i], upperOffset);
        }
    }
    
    if (upperOffset < 10)
    {
        upperOffsetStr = "0"+to_string(upperOffset);
    }
    else
    {
        upperOffsetStr = to_string(upperOffset);
    }
    if (lowerOffset < 10)
    {
        lowerOffsetStr = "0"+to_string(lowerOffset);
    }
    else
    {
        lowerOffsetStr = to_string(lowerOffset);
    }

    return upperOffsetStr + lowerOffsetStr + to_string(digitOffset) + password;
}

int charToDigit(char digit)
{
    switch (digit)
    {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return 0;
            break;
    }
}

char calculateDigits(char value, int offset)
{
    if (value + offset > '9')
    {
        return (char)((value + offset)-9);
    }
    else
    {
        return (char)(value + offset);
    }
}

char calculateLowercaseCharacter(char value, int offset)
{
    if (value + offset > 'z')
    {
        return (char)(((value+offset)-26));
    }
    else
    {
        return (char)((value+offset));
    }
}

char calculateUppercaseCharacter(char value, int offset)
{
    if (value + offset > 'Z')
    {
        return (char)(((value+offset)-26));
    }
    else
    {
        return (char)((value+offset));
    }
}

int sumDigits(string password)
{
    int total = 0;
    for (int i = 0; i < password.size(); i++)
    {
        if (isdigit(password[i]))
        {
            total += charToDigit(password[i]);
        }
    }
    
    if (total > 9)
    {
        total %= 9;
    }
    
    return total+1;
}

int sumUppercase(string password)
{
    int total = 0;
    for (int i = 0; i < password.size(); i++)
    {
        if (isupper(password[i]))
        {
            total += (int)(password[i]);
        }
    }
    
    if (total > 26)
    {
        total %= 26;
    }
    
    return total+1;
}

int sumLowercase(string password)
{
    int total = 0;
    for (int i = 0; i < password.size(); i++)
    {
        if (islower(password[i]))
        {
            total += (int)(password[i]);
        }
    }
    
    if (total > 26)
    {
        total %= 26;
    }
    
    return total+1;
}

bool UserPasswordManager::checkOldPassword(string password, vector<string> oldPasswords)
{
    for (int i = 0; i < oldPasswords.size(); i++)
    {
        if (oldPasswords[i].compare(encryptPassword(password)) == 0)
        {
            cout<<"Please create a password that was not previously used!"<<endl;
            return false;
        }
    }
    
    return true;
}

bool checkLength(string password)
{
    if (password.size() < 8)
    {
        cout<<"Password must contain 8 or more characters."<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool checkLowercase(string password)
{
    for (int i = 0; i < password.size(); i++)
    {
        if (islower(password[i]))
        {
            return true;
        }
    }
    
    cout<<"Password must contain a lowercase letter."<<endl;
    return false;
}

bool checkUppercase(string password)
{
    for (int i = 0; i < password.size(); i++)
    {
        if (isupper(password[i]))
        {
            return true;
        }
    }
    
    cout<<"Password must contain a uppercase letter."<<endl;
    return false;
}

bool checkDigit(string password)
{
    for(int i = 0; i < password.size(); i++)
    {
        if(isdigit(password[i]))
        {
            return true;
        }
    }
    
    cout<<"Password must contain a numeric digit"<<endl;
    return false;
}

bool checkSpecialCharacter(string password)
{
    char specialCharacters[27] = {'!','@','#','$','%','~','^','&','*','(',')','_','+','=','-','`','<','>','?',':','"','|','\\','[',']','{','}'};
    
    for (int i = 0; i < password.size(); i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (password[i] == specialCharacters[j])
            {
                return true;
            }
        }
    }
    
    cout<<"Password must contain one of the following: ";
    for (int i = 0; i < 27; i++)
    {
        cout<<specialCharacters[i]<<" ";
    }
    cout<<endl;
    return false;
}

bool checkIllegalValue(string password)
{
    for (int i = 0; i < password.size(); i++)
    {
        if (!isalnum(password[i]))
        {
            if (!isSpecial(password[i]))
            {
                if (password[i] == ' ')
                {
                    cout<<"Password cannot contain a space"<<endl;
                }
                else
                {
                    cout<<"Password cannot contain "<<password[i]<<"."<<endl;
                }
                return false;
            }
        }
    }
    
    return true;
}

bool isSpecial(char character)
{
    char specialCharacters[27] = {'!','@','#','$','%','~','^','&','*','(',')','_','+','=','-','`','<','>','?',':','"','|','\\','[',']','{','}'};
    
    for (int i = 0; i < 27; i++)
    {
        if (character == specialCharacters[i])
        {
            return true;
        }
    }
    
    return false;
}
