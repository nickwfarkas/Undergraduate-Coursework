//
//  TruthValue.cpp
//  Boolean_Algebra
//
//  Created by Nicholas Farkas on 4/29/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "TruthValue.hpp"
#include <iostream>

using namespace std;

int truthValueToInteger(char value);

TruthValue::TruthValue(char value)
{
    _value = value;
}

char TruthValue::getValue(){return _value;}
void TruthValue::setValue(char v){_value = v;}

ostream& operator << (ostream& o, TruthValue tv)
{
    o<<tv._value;
    return o;
}

TruthValue TruthValue::operator + (TruthValue value)
{
    int i = truthValueToInteger(_value) + truthValueToInteger(value.getValue());
    
    if (i == 2)
    {
        i = 1;
    }
    
    if (_value == '0' || _value == '1')
    {
        switch (i)
        {
            case 0:
                return TruthValue('0');
                break;
            case 1:
                return TruthValue('1');
            default:
                break;
        }
    }
    else
    {
        switch (i)
        {
            case 0:
                return TruthValue('F');
                break;
            case 1:
                return TruthValue('T');
            default:
                break;
        }
    }
    
    return TruthValue('0');
}

TruthValue TruthValue::operator * (TruthValue value)
{
    int i = truthValueToInteger(_value) * truthValueToInteger(value.getValue());
    
    if (_value == '0' || _value == '1')
    {
        switch (i)
        {
            case 0:
                return TruthValue('0');
                break;
            case 1:
                return TruthValue('1');
            default:
                break;
        }
    }
    else
    {
        switch (i)
        {
            case 0:
                return TruthValue('F');
                break;
            case 1:
                return TruthValue('T');
            default:
                break;
        }
    }
    
    return TruthValue('0');
}

int truthValueToInteger(char value)
{
    if (value != '0' && value != '1')
    {
        value = toupper(value);
    }
    
    switch (value)
    {
        case 'T':
            return 1;
            break;
        case 'F':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '0':
            return 0;
            break;
        default:
            return -1;
            break;
    }
}
