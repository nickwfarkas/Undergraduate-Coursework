//
//  Student.cpp
//  Student_Athlete_Vector
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//
#include <iostream>
#include <iomanip>

#include "Student.hpp"

Student::Student(string last, string first, int grade)
{
    _last = last;
    _first = first;
    _grade = grade;
    _totalFees = 0;
}

void Student::operator += (float fee)
{
    _totalFees += fee;
}

ostream& operator << (ostream& o, Student student)
{
    o<<"Name: "<<student._first<<" "<<student._last<<endl;
    o<<"Grade: "<<student._grade<<"th"<<endl;
    o<<"Fees: "<<student._totalFees<<endl;
    return o;
}

bool Student::operator == (string last)
{
    if (_last == last)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Student::operator == (int grade)
{
    if (_grade == grade)
    {
        return true;
    }
    else
    {
        return false;
    }
}
