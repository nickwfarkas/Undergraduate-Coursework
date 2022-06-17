//
//  Computer.hpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"

using namespace std;

class Computer : public Player
{
public:
    Computer(string);
    void makeSelection();
//    void operator++();
};

#endif /* Computer_hpp */
