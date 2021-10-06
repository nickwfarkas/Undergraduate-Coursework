//
//  Outfit.cpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Outfit.hpp"
#include "Date.hpp"
#include "Clothing.hpp"
#include "Pants.hpp"
#include "Shirt.hpp"
#include <iostream>

ostream& operator<<(ostream& o, Outfit& outfit)
{
    o<<outfit._date;
    o<<": ";
    o<<outfit._shirt;
    o<<" & ";
    o<<outfit._pant;
    o<<endl;
    if (outfit._shirt.getColor() == outfit._pant.getColor())
    {
        o<<"This outfit Matches!"<<endl;
    }
    else
    {
        o<<"Your shirt doesn't match your pants!"<<endl;
    }
    return o;
}
