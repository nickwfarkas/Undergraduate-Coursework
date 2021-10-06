//
//  Shirt.cpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Pants.hpp"
#include "Shirt.hpp"

Shirt::Shirt(string color, string type): Clothing(color)
{
    _type = type;
}

string Shirt::getType(){return _type;}

void Shirt::setType(string type){_type = type;}

ostream& operator<<(ostream& o, Shirt& shirt)
{
    o<<shirt.getColor()<<" "<<shirt._type<<endl;
    return o;
}

istream& operator>>(istream& i, Shirt& shirt)
{
    string c;
    cout<<"What color would you like these shirt to be: "<<endl;
    i>>c;
    shirt.setColor(c);
    cout<<"What style would you like these pants to be: "<<endl;
    i>>shirt._type;
    return i;
}

bool Shirt::operator == (Pants pant)
{
    if (pant.getColor() == getColor())
    {
        return true;
    }
    else
    {
        return false;
    }
}

