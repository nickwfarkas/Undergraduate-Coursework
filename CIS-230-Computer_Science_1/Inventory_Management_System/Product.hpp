//
//  Product.hpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas on 5/12/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Product
{
protected:
    int _productId;
    string _productName;
    string _productDescription;
    float _productPrice;
    string _productType;
public:
    virtual void printInformation();
    virtual void reOrder();
    virtual void postData();
    virtual void postData(int);
    virtual int getQuantity();
    virtual void setQuantity(int);
    virtual void updateQuantity();
    int getID();
    string getProductType();
    string getProductName();
    Product(int);
    
};

#endif /* Product_hpp */
