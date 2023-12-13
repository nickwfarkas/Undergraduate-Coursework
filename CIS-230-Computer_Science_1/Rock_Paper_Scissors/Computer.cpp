//
//  Computer.cpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Computer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber();

Computer::Computer(string name) : Player(name) { }

//void Computer::setSelection(string selection) {_selection = selection;}

//void Computer::operator++()
//{
//    setWins(getWins()+1);
//}

void Computer::makeSelection()
{
    switch (1+rand()%3)
    {
        case 1:
            setSelection("Rock");
            cout<<"Rock"<<endl;
            break;
        case 2:
            setSelection("Paper");
            cout<<"Paper"<<endl;
            break;
        case 3:
            setSelection("Scissors");
            cout<<"Scissors"<<endl;
            break;
        default:
            cout<< "Error";
            break;
    }
}
