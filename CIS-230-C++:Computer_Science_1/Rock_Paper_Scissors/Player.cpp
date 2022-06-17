//
//  Player.cpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Player.hpp"

#include <iostream>

using namespace std;

Player::Player(string name)
{
    _wins = 0;
    _losses = 0;
    _name = name;
}

void Player::makeSelection()
{
    cout<<"Didn't work"<<endl;
}

void Player::operator --()
{
    ++_losses;
}

void Player::operator ++()
{
    ++_wins;
}

void Player::setSelection(string selection){_selection = selection;}

string Player::getSelection(){return _selection;}

string Player::getName(){return _name;}

int Player::getWins(){return _wins;}

int Player::getLosses(){return _losses;}

void Player::setLosses(int losses){_losses = losses;}

void Player::setName(string name){_name = name;}

void Player::setWins(int wins){_wins = wins;}

