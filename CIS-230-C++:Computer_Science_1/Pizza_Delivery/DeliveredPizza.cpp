#include "Pizza.hpp"
#include "DeliveredPizza.hpp"

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

DeliveredPizza::DeliveredPizza
(
    string deliveryAddress, string size, string type, vector<string> toppings
)
: Pizza(size, type, toppings)
{
    _deliveryAddress = deliveryAddress;
    
    if (getPrice() > 20)
    {
        _deliveryFee = 3.5;
    }else
    {
        _deliveryFee = 5;
    }

    _totalPrice = getPrice() + _deliveryFee;
}

float DeliveredPizza::getDeliveryFee(){return _deliveryFee;}
float DeliveredPizza::getTotalPrice(){return _totalPrice;}
string DeliveredPizza::getDeliveryAddress(){return _deliveryAddress;}