#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Pizza
{
private:
    string _size;
    string _type;
    vector<string> _toppings;
    float _price;
    void calculatePrice();
public:
    Pizza(string size, string type, vector<string> toppings);

    string getSize();
    string getType();
    vector<string> getTopping();
    string getTopping(int);

    float getPrice();

    void intToSize(int);
    void intToType(int);
    void populateToppings(vector<int>);

    void printToppings(ostream&);

    friend ostream& operator<<(ostream&, Pizza&);
};

#endif