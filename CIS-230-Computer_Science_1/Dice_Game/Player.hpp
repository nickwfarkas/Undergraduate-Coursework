//
//  Player.hpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <stdio.h>
#include "Dice.hpp"

using namespace std;

class Player
{
private:
    string _name;
    int _score;
public:
    bool inTheGame = false;
    Dice dice[6];
    Player(string);
    string getName();
    int getScore();
    void setScore(int);
};

#endif /* Player_hpp */
