//
//  Human.hpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"
using namespace std;

class Human : public Player
{
public:
    Human(string);
    void makeSelection();
//    void operator ++();
};

#endif /* Human_hpp */
