//
//  Pants.cpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Pants.hpp"
#include <iostream>

Pants::Pants(string color):Clothing(color){}

Pants::Pants(string color, string style): Clothing(color)
{
    _style = style;
}

string Pants::getStyle(){return _style;}

void Pants::setStyle(string style){_style = style;}

ostream& operator<<(ostream& o, Pants& pant)
{
    o<<pant.getColor()<<" "<<pant._style<<endl;
    return o;
}

istream& operator>>(istream& i, Pants& pant)
{
    string c;
    cout<<"What color would you like these pants to be: "<<endl;
    i>>c;
    pant.setColor(c);
    cout<<"What style would you like these pants to be: "<<endl;
    i>>pant._style;
    return i;
}
