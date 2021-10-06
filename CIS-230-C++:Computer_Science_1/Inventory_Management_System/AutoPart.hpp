//
//  AutoPart.hpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef AutoPart_hpp
#define AutoPart_hpp

#include <stdio.h>
#include <set>
#include <iostream>
#include "Product.hpp"

class AutoPart : public Product
{
private:
    string _manufacture;
    set<string> _compatableVINs;
    int _reOrderQuantity;
    int _quantity;
public:
    set<string> getVINs(){return _compatableVINs;}
    string getManufacture(){return _manufacture;}
    void printInformation();
    AutoPart(int);
    void postData();
    void postData(int);
    void reOrder();
    int getQuantity();
    void setQuantity(int);
    void updateQuantity();
    int getSale();
    void checkQuantity();
};

#endif /* AutoPart_hpp */
