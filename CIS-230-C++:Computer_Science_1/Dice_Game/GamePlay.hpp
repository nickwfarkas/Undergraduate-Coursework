//
//  GamePlay.hpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef GamePlay_hpp
#define GamePlay_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Player.hpp"

class GamePlay
{
private:
    vector<Player> _players;
    int _numOfPlayers;
public:
    void GameSetup();
};

#endif /* GamePlay_hpp */
