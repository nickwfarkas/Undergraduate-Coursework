//
//  Service.cpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include"Service.hpp"
#include <fstream>
#include <map>

Service::Service(int productId):
Product(productId)
{

}

//Posts Data from user entered file name into service object
void Service::postData()
{
    string fileName;
    ifstream inputfile;
    int tempId;
    string tempName;
    
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
        getline(inputfile, _productDescription);
        inputfile >> _productPrice;
        inputfile >> _timeOfService;
        inputfile >> tempId;
        getline(inputfile, tempName);

        inputfile.close();
    }
}

//Posts Data from files named service followed by a integer into service object
void Service::postData(int i)
{
    ifstream inputfile;
    string fileName = "Service" + to_string(i) + ".txt";
    int tempId;
    string tempName;
    
    inputfile.open(fileName);
    
    if (!inputfile.is_open())
    {
        throw "Stream broken";
    }
    else
    {
        getline(inputfile, _productType);
        getline(inputfile, _productName);
        getline(inputfile, _productDescription);
        inputfile >> _productPrice;
        inputfile >> _timeOfService;
        inputfile >> tempId;
        getline(inputfile, tempName);
        _certifiedEmployees.setEmployeeID(tempId);
        _certifiedEmployees.setEmployeeName(tempName);
        
        inputfile.close();
    }
}

//Prints all information from service object
void Service::printInformation()
{
    cout<<endl<<"ID: "<<_productId<<endl;
    cout<<"Product Type: "<<_productType<<endl;
    cout<<"Name: "<<_productName<<endl;
    cout<<"Description: "<<_productDescription<<endl;
    cout<<"Price: "<<_productPrice<<endl;
    cout<<"Average Time of Service: "<<_timeOfService<<" Minutes"<<endl;
    cout<<"Certified Employee ID: "<<_certifiedEmployees.getEmployeeID()<<endl;
}

void Service::reOrder(){cout<<"Cannot reOrder a service"<<endl;}

int Service::getQuantity(){return 0;}

void Service::setQuantity(int){}

void Service::updateQuantity(){cout<<"Cannot update a service"<<endl;}
