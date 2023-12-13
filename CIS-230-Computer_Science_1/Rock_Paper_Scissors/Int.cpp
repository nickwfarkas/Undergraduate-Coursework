//
//  Int.cpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/9/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Int.hpp"

Int::Int(){}

Int::Int(int i)
{
    this->i = i;
}

Int& Int::operator ++()
{
    i++;
    return *this;
}
