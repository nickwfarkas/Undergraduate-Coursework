//
//  Human.cpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Human.hpp"
#include <iostream>

using namespace std;

Human::Human(string name): Player(name){ }

//void Human::operator++()
//{
//    setWins(getWins()+1);
//}

void Human::makeSelection()
{
    string selection;
    cout<<"Rock?\nPaper?\nor Scissors?"<<endl;
    getline(cin, selection);
    setSelection(selection);
}
