//
//  BulkLiquid.hpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas on 5/12/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef BulkLiquid_hpp
#define BulkLiquid_hpp

#include <stdio.h>
#include <iostream>
#include "Product.hpp"

class BulkLiquid : public Product
{
private:
    bool _isHazmat;
    string _manufacture;
    int _reOrderQuantity;
    int _quantity;
public:
    BulkLiquid(int);
    void postData();
    void printInformation();
    void reOrder();
    int getQuantity();
    void setQuantity(int);
    void updateQuantity();
    int getSale();
    void checkQuantity();
    void postData(int);
};

#endif /* BulkLiquid_hpp */
