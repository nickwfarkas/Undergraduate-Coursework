//
//  AutoPart.cpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas on 5/12/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include "AutoPart.hpp"
#include <fstream>

AutoPart::AutoPart(int productId): Product(productId){}

//Posts Data from files that user entered the name of
void AutoPart::postData()
{
    string fileName;
    ifstream inputfile;
    string temp;
    
    cin.ignore(100,'\n');
    
    cout<<"Please enter the name of the file or enter to end inventory input: ";
    getline(cin, fileName);
    
    inputfile.open(fileName + ".txt");
    
    if (!inputfile.is_open())
    {
        throw "Stream broken";
    }
    else
    {
        getline(inputfile, _productType);
        getline(inputfile, _productName);
        getline(inputfile, _manufacture);
        getline(inputfile, _productDescription);
        inputfile >> _productPrice;
        inputfile >> _quantity;
        inputfile >> _reOrderQuantity;
        while (!inputfile.eof())
        {
            inputfile >> temp;
            _compatableVINs.insert(temp);
        }
        
        inputfile.close();
    }
}

//Posts Data from files named service followed by a integer into service object
void AutoPart::postData(int i)
{
    ifstream inputfile;
    string temp;
    string fileName = "AutoPart" + to_string(i) + ".txt";
    
    inputfile.open(fileName);

    if (!inputfile.is_open())
    {
        throw "Stream broken";
    }
    else
    {
        getline(inputfile, _productType);
        getline(inputfile, _productName);
        getline(inputfile, _manufacture);
        getline(inputfile, _productDescription);
        inputfile >> _productPrice;
        inputfile >> _quantity;
        inputfile >> _reOrderQuantity;
        while (!inputfile.eof())
        {
            inputfile >> temp;
            _compatableVINs.insert(temp);
        }

        inputfile.close();
    }
}

//Prints all members of BulkLiquid object
void AutoPart::printInformation()
{
    set<string>::iterator iter = _compatableVINs.begin();
    
    cout<<endl<<"ID: "<<_productId<<endl;
    cout<<"Product Type: "<<_productType<<endl;
    cout<<"Name: "<<_productName<<endl;
    cout<<"Manufacture: "<<_manufacture<<endl;
    cout<<"Description: "<<_productDescription<<endl;
    cout<<"Price: "<<_productPrice<<endl;
    cout<<"Quantity: "<<_quantity<<endl;
    cout<<"Reorder Quantity: "<<_reOrderQuantity<<endl;
    cout<<"Compatable VINs: ";
    for (int i = 0; i < _compatableVINs.size(); i++)
    {
        if (i == _compatableVINs.size()-1)
        {
            cout<<*iter<<endl;
        }
        else
        {
            cout<<*iter<<", ";
            ++iter;
        }
    }
    cout<<endl;
}

//Sets _quanity to the reOrder Quanity of the object
void AutoPart::reOrder()
{
    cout<<"A reOrder was made for "<<_productName<<endl<<endl;
    _quantity = _reOrderQuantity;
}

int AutoPart::getQuantity(){return _quantity;}

void AutoPart::setQuantity(int quantity){_quantity = quantity;}

//Updates quanity based on user inputted information
void AutoPart::updateQuantity()
{
    int sale;
    
    cout<<"How much "<<_productName<<" was sold: "<<endl;
    sale = getSale();
    
    _quantity -= sale;
    
    cout<<endl<<"Quantity Updated!"<<endl;
    cout<<_productName<<" Quantity: "<<_quantity<<endl<<endl;
    
    checkQuantity();
}

//Gets and Validates sale user information
int AutoPart::getSale()
{
    int sale;
    cin>>sale;
    string reset;
    
    if (cin.fail())
    {
        cin.ignore(100, '\n');
        cin.clear();
        cout<<"Not a valid entry please try again!"<<endl;
        updateQuantity();
    }
    
    if (sale > _quantity)
    {
        cout<<sale<<" is greater than the quantity in stock!"<<endl;
        cout<<"Would you like to reset quantity to zero type Y for yes or any other key to reenter quantity sold: ";
        cin.ignore(100,'\n');
        getline(cin, reset);
        if (tolower(reset[1]) == 'y')
        {
            return 0;
        }
        else
        {
            updateQuantity();
        }
    }
    
    return sale;
}

//Reorders when  _quanity gets to zero
void AutoPart::checkQuantity()
{
    if (_quantity <= 0)
    {
        reOrder();
    }
}
