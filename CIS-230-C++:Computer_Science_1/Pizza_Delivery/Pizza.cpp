#include "Pizza.hpp"

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

Pizza::Pizza(string size, string type, vector<string> toppings)
{
    _size = size;
    _type = type;
    _toppings = toppings;

    calculatePrice();
}

string Pizza::getSize(){return _size;}
string Pizza::getType(){return _type;}
float Pizza::getPrice(){return _price;}
vector<string> Pizza::getTopping(){return _toppings;}

string Pizza::getTopping(int i){return _toppings[i];}

void Pizza::calculatePrice()
{
    if (tolower(_size[0]) == 's')
    {
        _price = 10;
    }
    else if (tolower(_size[0]) == 'm')
    {
        _price = 14;
    }
    else if(tolower(_size[0]) == 'l')
    {
        _price = 17;
    }
    
    _price = (_toppings.size() * 2) + _price; 

}

void Pizza::intToSize(int i)
{
    switch (i)
    {
    case 1:
        _size = "Small";
        break;
    case 2:
        _size = "Medium";
        break;
    case 3:
        _size = "Large";
        break;
    
    default:
        break;
    }
}

void Pizza::intToType(int i)
{
    switch (i)
    {
    case 1:
        _type = "Classic";
        break;
    case 2:
        _type = "Deep Dish";
        break;
    case 3:
        _type = "Thin Crust";
        break;
    
    default:
        break;
    }
}

string intToTopping(int i)
{
    string topping;

    switch (i)
    {
    case 1:
        topping = "Pepperoni";
        break;
    case 2:
        topping = "Mushrooms";
        break;
    case 3:
        topping = "Onions";
        break;
    case 4:
        topping = "Green Pepper";
        break;
    case 5:
        topping = "Tomatoes";
        break;
    case 6:
        topping = "Jalapenos";
        break;
    default:
        topping = "None";
        break;
    }

    return topping;
}

void Pizza::populateToppings(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        _toppings[i] = intToTopping(nums[i]);
    }
}

void Pizza::printToppings(ostream& o)
{
    if (_toppings.size() == 0)
    {
        o<< "with no toppings"<<endl;
    }
    else
    {
        o<< "with ";
        for (int i = 0; i < _toppings.size(); i++)
        {
            o<<_toppings[i] << " ";
        }
        o<<endl;
    }
}