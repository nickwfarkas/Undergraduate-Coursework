//
//  main.cpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/3/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int randomNumber();
int menu();
int getMenu();
void playGame(Player *player1, Player *player2);
string getName(int i);
string convertToLower(string input);
void determineWinner(Player *player1, Player *player2);
void readFile(string line[2]);
void writeFile(Player *player1, Player *player2);


int main()
{
    string data[6];
    string keepPlaying = "Yes";
    srand((unsigned)time(0));
    Player *player1Ptr;
    Player *player2Ptr;

    int playerOption = menu();
    
    if (playerOption == 1)
    {
        cin.ignore(100,'\n');
        readFile(data);
        Human pvp1(data[0]);
        Human pvp2(data[1]);
        player1Ptr = &pvp1;
        player2Ptr = &pvp2;
        player1Ptr->setWins(stoi(data[2]));
        player2Ptr->setWins(stoi(data[3]));
        player1Ptr->setLosses(stoi(data[4]));
        player2Ptr->setLosses(stoi(data[5]));
        playGame(player1Ptr, player2Ptr);
        cout<<endl;
        
    }
    else if (playerOption == 2)
    {
        readFile(data);
        Human pve(data[0]);
        Computer evp("Computer");
        player1Ptr = &pve;
        player2Ptr = &evp;
        player1Ptr->setWins(stoi(data[1]));
        player2Ptr->setWins(stoi(data[2]));
        playGame(player1Ptr, player2Ptr);
    }
    else
    {
        Computer cvc1("Computer 1");
        Computer cvc2("Computer 2");
        player1Ptr = &cvc1;
        player2Ptr = &cvc2;
        playGame(player1Ptr, player2Ptr);
    }
    
    writeFile(player1Ptr, player2Ptr);
    
    cout<<"Check you output file for stats"<<endl;

    return 0;
}

void readFile(string line[6])
{
    string fileName;
    ifstream inputfile;
    
    //cin.ignore(100,'\n');
    
    cout<<"Please enter the name of the file: ";
    getline(cin, fileName);
    
    inputfile.open(fileName + ".txt");
    
    for (int i = 0; i < 6; i++)
    {
        inputfile>>line[i];
    }

    inputfile.close();
}

void writeFile(Player *player1, Player *player2)
{
    ofstream outputFile;
    
    string fileName;
    
    cout<<"Please enter the name of the file: ";
    getline(cin, fileName);
    outputFile.open(fileName + ".txt");
    
    outputFile<<player1->getName()<<endl;
    outputFile<<player2->getName()<<endl;
    outputFile<<player1->getWins()<<endl;
    outputFile<<player2->getWins()<<endl;
    outputFile<<player1->getLosses()<<endl;
    outputFile<<player2->getLosses()<<endl;
    
    outputFile.close();
}

int menu()
{
    cout<<"Please enter:\n1: Player v Player\n2: Player v Enemy(Computer)\n3: Enemy(Computer) v Enemy(Computer)\nPlease make a selection: ";
    return getMenu();
}

int getMenu()
{
    int selection;
    cin>>selection;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout<<endl<<"Invalid entry please try again!"<<endl;
        cout<<"Enter a numeric value 1-3"<<endl;
        selection = menu();
    }
    else if(selection < 1 || selection > 3)
    {
        cout<<endl<<"Invalid entry please try again!"<<endl;
        cout<<"Enter a numeric value 1-3"<<endl;
        selection = menu();
    }
    
    return selection;
}

void playGame(Player *player1, Player *player2)
{
    cout<<endl<<player1->getName()<<" please make a selection:"<<endl;
    player1->makeSelection();
    
    cout<<endl<<player2->getName()<<" please make a selection:"<<endl;
    player2->makeSelection();
    
    determineWinner(player1, player2);
}

void determineWinner(Player *player1, Player *player2)
{
    if (convertToLower(player1->getSelection()) == "rock")
    {
        if (convertToLower(player2->getSelection()) == "paper")
        {
            cout<<player2->getName()<<" Wins!"<<endl;
            ++*player2;
            --*player1;
        }
        else if (convertToLower(player2->getSelection()) == "scissors")
        {
            cout<<player1->getName()<<" Wins!"<<endl;
            ++*player1;
            --*player2;
        }
        else if (convertToLower(player2->getSelection()) == "rock")
        {
            cout<<"Tie!"<<endl;
        }
    }
    if (convertToLower(player1->getSelection()) == "paper")
    {
        if (convertToLower(player2->getSelection()) == "paper")
        {
            cout<<"Tie!"<<endl;
            
        }
        else if (convertToLower(player2->getSelection()) == "scissors")
        {
            cout<<player2->getName()<<" Wins!"<<endl;
            ++*player2;
            --*player1;
           
        }
        else if (convertToLower(player2->getSelection()) == "rock")
        {
            cout<<player1->getName()<<" Wins!"<<endl;
            ++*player1;
            --*player2;
            
        }
    }
    if (convertToLower(player1->getSelection()) == "scissors")
    {
        if (convertToLower(player2->getSelection()) == "paper")
        {
            cout<<player1->getName()<<" Wins!"<<endl;
            ++*player1;
            --*player2;
        }
        else if (convertToLower(player2->getSelection()) == "scissors")
        {
            cout<<"Tie!"<<endl;
        }
        else if (convertToLower(player2->getSelection()) == "rock")
        {
            cout<<player2->getName()<<" Wins!"<<endl;
            ++*player2;
            --*player1;
        }
    }
}

string convertToLower(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        input[i] = tolower(input[i]);
    }
    
    return input;
}



