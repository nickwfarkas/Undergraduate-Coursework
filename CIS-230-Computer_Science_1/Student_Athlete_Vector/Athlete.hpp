//
//  Athlete.hpp
//  Student_Athlete_Vector
//
//  Created by Nicholas Farkas on 4/16/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Athlete_hpp
#define Athlete_hpp

#include <iostream>
#include <iomanip>

using namespace std;

class Athlete
{
private:
    string _last;
    string _first;
    string _sport;
    
public:
    Athlete(string first, string last, string sport);
    string getLast();
    static float athleticFee;
    void setFirst(string);
    void setLast(string);
    void setSport(string);
    static float getAthleticFee();
    friend ostream& operator <<(ostream& o, Athlete athlete);
    bool operator == (string sport);
};


#endif /* Athlete_hpp */
