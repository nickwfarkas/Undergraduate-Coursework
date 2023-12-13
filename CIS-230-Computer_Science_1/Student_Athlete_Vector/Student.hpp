//
//  Student.hpp
//  Student_Athlete_Vector
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Student
{
    
private:
    string _last;
    string _first;
    int _grade;
    float _totalFees;
    
public:
    Student(string last, string first, int grade);
    int getGrade();
    void operator += (float fee);
    friend ostream& operator << (ostream& o, Student s);
    bool operator == (string last);
    bool operator == (int grade);
    
};


#endif /* Student_hpp */
