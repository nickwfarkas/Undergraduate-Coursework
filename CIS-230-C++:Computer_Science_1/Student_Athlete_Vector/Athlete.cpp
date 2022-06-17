//
//  Athlete.cpp
//  Student_Athlete_Vector
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include "Athlete.hpp"

Athlete::Athlete(string first, string last, string sport)
{
    _first = first;
    _last = last;
    _sport = sport;
}

float Athlete::getAthleticFee() {return athleticFee;}
string Athlete::getLast(){return _last;}

void Athlete::setFirst(string first) {_first = first;}
void Athlete::setLast(string last) {_last = last;}
void Athlete::setSport(string sport) {_sport = sport;}

ostream& operator <<(ostream& o, Athlete athlete)
{
    o<<athlete._first<<" "<<athlete._last<<" is enrolled in "<<athlete._sport<<endl;
    
    return o;
}

bool Athlete::operator == (string sport)
{
    if (_sport == sport)
    {
        return true;
    }
    else
    {
        return false;
    }
}


