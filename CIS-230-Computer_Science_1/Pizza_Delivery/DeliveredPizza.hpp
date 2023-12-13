#ifndef DELIVEREDPIZZA_HPP
#define DELIVEREDPIZZA_HPP

#include "Pizza.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class DeliveredPizza : public Pizza
{
private:
    float _deliveryFee;
    float _totalPrice;
    string _deliveryAddress;
public:
    DeliveredPizza(string, string, string, vector<string>);
    float getDeliveryFee();
    float getTotalPrice();
    string getDeliveryAddress();

    friend ostream& operator << (ostream&, DeliveredPizza&);
};

#endif