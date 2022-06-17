//
//  Date.hpp
//  Test_2
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Date
{
private:
    int _month;
    int _day;
    int _year;
public:
    Date(int, int, int);
    friend ostream& operator<<(ostream&, Date&);
};



#endif /* Date_hpp */
