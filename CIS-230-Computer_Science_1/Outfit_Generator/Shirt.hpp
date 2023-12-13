//
//  Shirt.hpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Shirt_hpp
#define Shirt_hpp

#include "Clothing.hpp"
#include <stdio.h>
#include <iostream>

class Shirt : public Clothing
{
private:
    string _type;
public:
    Shirt(string, string);
    string getType();
    void setType(string);
    friend ostream& operator<<(ostream& o, Shirt& shirt);
    friend istream& operator>>(istream& i, Shirt& shirt);
    bool operator == (Pants pant);
};

#endif /* Shirt_hpp */
