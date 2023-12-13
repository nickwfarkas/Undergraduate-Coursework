//
//  Pants.hpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Pants_hpp
#define Pants_hpp

#include "Clothing.hpp"
#include <stdio.h>
#include <iostream>

class Pants : public Clothing
{
private:
    string _style;
public:
    Pants(string);
    Pants(string, string);
    string getStyle();
    void setStyle(string);
    friend ostream& operator<<(ostream&, Pants&);
    friend istream& operator>>(istream&, Pants&);
};

#endif /* Pants_hpp */
