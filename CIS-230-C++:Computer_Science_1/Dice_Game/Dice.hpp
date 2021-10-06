//
//  Dice.hpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <stdio.h>

class Dice
{
private:
    int _value;
    bool _active = true;
public:
    void rollDice();
    void rollDye(int);
    int getDye(int);
    int getValue;
};

#endif /* Dice_hpp */
