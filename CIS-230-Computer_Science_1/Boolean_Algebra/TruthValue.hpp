//
//  TruthValue.hpp
//  Boolean_Algebra
//
//  Created by Nicholas Farkas on 4/29/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef TruthValue_hpp
#define TruthValue_hpp

#include <stdio.h>
#include <iostream>


using namespace std;

class TruthValue
{
protected:
    char _value;
    
public:
    TruthValue(char);
    char getValue();
    void setValue(char);
    //int truthValueToInteger();
    TruthValue operator + (TruthValue);
    TruthValue operator * (TruthValue);
    friend ostream& operator << (ostream& o, TruthValue tv);
};


#endif /* TruthValue_hpp */
