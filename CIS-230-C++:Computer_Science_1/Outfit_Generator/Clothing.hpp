//
//  Clothing.hpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Clothing_hpp
#define Clothing_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Clothing
{
private:
    string _color;
public:
    Clothing(string);
    string getColor();
    void setColor(string);
};


#endif /* Clothing_hpp */
