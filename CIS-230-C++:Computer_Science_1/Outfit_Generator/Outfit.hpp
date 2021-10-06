//
//  Outfit.hpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Outfit_hpp
#define Outfit_hpp

#include "Date.hpp"
#include "Clothing.hpp"
#include "Pants.hpp"
#include "Shirt.hpp"
#include <stdio.h>
#include <iostream>

class Outfit// : public Pants, public Shirt, public Date
{
private:
    Pants _pant;
    Shirt _shirt;
    Date _date;
public:
//    Outfit(Pants pant, Shirt shirt, Date date, string style, string type, int month, int day, int year, string color);
    Outfit();
    friend ostream& operator<<(ostream& o, Outfit& outfit);
};

#endif /* Outfit_hpp */
