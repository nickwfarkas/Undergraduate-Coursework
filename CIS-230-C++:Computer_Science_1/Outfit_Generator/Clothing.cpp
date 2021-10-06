//
//  Clothing.cpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Clothing.hpp"
#include <iostream>

Clothing::Clothing(string color)
{
    _color = color;
}

string Clothing::getColor(){return _color;}
void Clothing::setColor(string color){_color = color;}
