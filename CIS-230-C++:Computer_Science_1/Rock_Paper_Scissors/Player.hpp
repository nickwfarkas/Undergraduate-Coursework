//
//  Player.hpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Int.hpp"

using namespace std;

class Player
{
private:
    string _name;
    string _selection;
    int _wins = 0;
    int _losses = 0;
public:
    Player(string);
    string getSelection();
    void operator ++();
    void operator --();
    string getName();
    int getLosses();
    void setLosses(int);
    void setWins(int);
    void setName(string);
    void setSelection(string);
    int getWins();
    virtual void makeSelection();
};

#endif /* Player_hpp */
