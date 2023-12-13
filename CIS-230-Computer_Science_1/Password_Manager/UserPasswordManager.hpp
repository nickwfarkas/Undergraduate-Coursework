//
//  UserPasswordManager.hpp
//  Password_Manager
//
//  Created by Nicholas Farkas on 4/24/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef UserPasswordManager_hpp
#define UserPasswordManager_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class UserPasswordManager
{
private:
    bool _validPassword;
    string _currentPassword;
    vector<string> _oldPassword;
    
    void createPassword();
    bool validatePassword(string);
    string encryptPassword(string);
public:
    UserPasswordManager();
    void changePassword();
    bool verifyPassword();
    bool checkOldPassword(string password, vector<string> oldPasswords);
};

#endif /* UserPasswordManager_hpp */
