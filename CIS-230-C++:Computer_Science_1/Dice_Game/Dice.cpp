//
//  Dice.cpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Dice.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int Dice::getValue(){return _value;}

void Dice::rollDice()
{
    for (int i = 0; i < 6; i++)
    {
        _dye[i] = 1+rand()%3;
    }
}

void Dice::rollDye(int i)
{
    _dye[i] = 1+rand()%3;
}

int Dice::getDye(int i)
{
    return _dye[i];
}
