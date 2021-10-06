//
//  Service.hpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Service_hpp
#define Service_hpp

#include "Product.hpp"
#include "Employee.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Service : public Product
{
private:
    float _timeOfService;
    Employee _certifiedEmployees;
public:
    Service(int);
    void printInformation();
    void postData();
    void postData(int);
    void reOrder();
    int getQuantity();
    void setQuantity(int);
    void updateQuantity();
};

#endif /* Service_hpp */
