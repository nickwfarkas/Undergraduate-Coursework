//
//  Player.cpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Player.hpp"

Player::Player(string name){_name = name;}

string Player::getName(){return _name;}

int Player::getScore(){return _score;}

void Player::setScore(int score){_score = score;}
