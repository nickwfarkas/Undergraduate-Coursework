//
//  GamePlay.cpp
//  Dice_Game
//
//  Created by Nicholas Farkas on 5/11/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "GamePlay.hpp"

void GamePlay::GameSetup()
{
    string name;
    
    cout<<"How many players are playing: ";
    cin>>_numOfPlayers;
    
    for (int i = 0; i < _numOfPlayers; i++)
    {
        cout<<"What is player "<<i+1<<"'s name: ";
        getline(cin, name);
        _players.insert(_players.begin()+i, Player(name));
    }
}

int convertToScore(int dye)
{
    if (dye == 1)
    {
        return 500;
    }
    else if(dye == 5)
    {
        return 50;
    }
    else
    {
        return 0;
    }
}



void GamePlay::checkThree(int playerNum)
{
    for (int i = 0; i < 6; i++)
    {
        int dicePosition[3];
        for (int j = 0; j < 6; j--)
        {
            if (_players[playerNum].dice[i].getValue == _players[playerNum].dice[j].getValue && i != j)
            {
                dicePosition[1] = i;
                dicePosition[2] = j;
                for (<#initialization#>; <#condition#>; <#increment#>) {
                    <#statements#>
                }
            }
        }
    }
}
