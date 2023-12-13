//
//  Date.cpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Date.hpp"
#include <iostream>

Date::Date(int month, int day, int year)
{
    _month = month;
    _day = day;
    _year = year;
}

ostream& operator<<(ostream& o, Date& date)
{
    o<<date._month<<"/"<<date._day<<"/"<<date._year<<endl;
    return o;
}
