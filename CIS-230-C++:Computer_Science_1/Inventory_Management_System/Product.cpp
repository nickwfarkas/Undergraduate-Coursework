//
//  Product.cpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas on 5/12/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "Product.hpp"
#include <iostream>

Product::Product(int productId)
{
    _productId = productId;
}

void Product::postData(){}

void Product::printInformation(){}

void Product::reOrder(){}

int Product::getID(){return _productId;}

int Product::getQuantity(){return 0;}

void Product::setQuantity(int){}

void Product::updateQuantity(){}

void Product::postData(int){}

string Product::getProductType(){return _productType;}

string Product::getProductName(){return _productName;}
