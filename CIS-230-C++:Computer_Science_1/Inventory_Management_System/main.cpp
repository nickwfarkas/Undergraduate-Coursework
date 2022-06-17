//
//  main.cpp
//  Inventory_Management_System
//
//  Created by Nicholas Farkas
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Product.hpp"
#include "Service.hpp"
#include "Employee.hpp"
#include "BulkLiquid.hpp"
#include "AutoPart.hpp"

using namespace std;

void fillProducts(vector<Product*>& products, AutoPart);
void fillProducts(vector<Product*>& products, BulkLiquid);
void fillProducts(vector<Product*>& products, Service);
void addProduct(vector<Product*>& products, AutoPart, int id);
void addProduct(vector<Product*>& products, BulkLiquid, int id);
void addProduct(vector<Product*>& products, Service, int id);
int getId(vector<Product*>& products);
void postSale(vector<Product*>& products);
void printProductsById(vector<Product*> products);
void printAllProducts(vector<Product*> products);
void printProductsByType(vector<Product*> products);
int getUserEnteredType();
string getType();

void fillProducts(vector<Product*>& products, AutoPart, int i);
void fillProducts(vector<Product*>& products, AutoPart, int i);
void fillProducts(vector<Product*>& products, BulkLiquid, int i);
void fillProducts(vector<Product*>& products, Service, int i);
void addProduct(vector<Product*>& products, AutoPart, int id, int i);
void addProduct(vector<Product*>& products, BulkLiquid, int id, int i);
void addProduct(vector<Product*>& products, Service, int id, int i);
int getMenuChoice(vector<Product*>& products);
int chooseProduct(vector<Product*>& products);
void direct(vector<Product*>& products, int choice);
void menu(vector<Product*>& products);
void deleteProductByID(vector<Product*>& products);
int getProductToDelete(vector<Product*>& products);

//Computer Generated IDs
static int ID = 0;

//Awesome feature but wish I could come up with a better use case
//returns the size of any vector
template <class myType>
long ExitProgram (myType T)
{
    return T.size();
}

int main()
{
    vector<Product*> products;

    menu(products);
    
    return 0;
}

//Deletes product by inputed ID
void deleteProductByID(vector<Product*>& products)
{
    int id;
    bool didDelete = false;
    cout<<"What is the ID of the product you would like to delete: ";
    id = getProductToDelete(products);
    
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i]->getID() == id)
        {
            didDelete = true;
            cout<<products[i]->getProductName()<<" has been deleted"<<endl;
            products.erase(products.begin()+i);
        }
    }
    
    if (!didDelete)
    {
        cout<<"There is no product with a ID of "<<id<<endl;
    }
    cout<<endl;
}

//Validates inputted ID for deletion
int getProductToDelete(vector<Product*>& products)
{
    int choice;
    cin>>choice;
    
    if (cin.fail())
    {
        cout<<"Not a valid entry please try again"<<endl<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        deleteProductByID(products);
    }
    
    return choice;
}

//Prints and gets choices from user
void menu(vector<Product*>& products)
{
    int choice;
    
    cout<<"Please make a selection:"<<endl;
    cout<<"1. Post Sale and Update Inventory"<<endl;
    cout<<"2. Add a Product to Inventory"<<endl;
    cout<<"3. Add Multiple Products to Inventory"<<endl;
    cout<<"4. Print Products by ID"<<endl;
    cout<<"5. Print Products by Type"<<endl;
    cout<<"6. Print All Products"<<endl;
    cout<<"7. Delete Product by ID"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Selection: ";
    choice = getMenuChoice(products);
    
    direct(products, choice);
}

//Takes user choice and directs them to corresponding functionality
void direct(vector<Product*>& products, int choice)
{
    long temp;
    int productChoice;
    switch (choice)
    {
        case 1:
            postSale(products);
            menu(products);
            break;
        case 2:
            cout<<"What type of product would you like to add\n1. Auto Parts\n2. Bulk Liquids\n3. Services\nOption: ";
            productChoice = chooseProduct(products);
            if (productChoice == 1)
            {
                ID++;
                addProduct(products, AutoPart(0), ID);
                cout<<"Success!"<<endl<<endl;
            }
            else if (productChoice == 2)
            {
                ID++;
                addProduct(products, BulkLiquid(0), ID);
                cout<<"Success!"<<endl<<endl;
            }
            else if (productChoice == 3)
            {
                ID++;
                addProduct(products, Service(0), ID);
                cout<<"Success!"<<endl<<endl;
            }
            
            menu(products);
            break;
        case 3:
            cout<<endl<<"Make sure file names are formatted correcrtly!"<<endl;
            temp = products.size();
            fillProducts(products, AutoPart(0), 1);
            fillProducts(products, BulkLiquid(0), 1);
            fillProducts(products, Service(0), 1);
            temp = products.size()-temp;
            cout<<temp<<" products were added!"<<endl;
            cout<<"Success!"<<endl<<endl;
            menu(products);
            break;
        case 4:
            printProductsById(products);
            menu(products);
            break;
        case 5:
            printProductsByType(products);
            menu(products);
            break;
        case 6:
            printAllProducts(products);
            menu(products);
            break;
        case 7:
            deleteProductByID(products);
            menu(products);
            break;
        case 8:
            cout<<"Your product inventory contained "<<ExitProgram(products)<<" products"<<endl;
            cout<<endl<<"Thank you for using this Inventory Management System!"<<endl;
            break;
        default:
            break;
    }
}

//Gets and validates user choice to choose product type to insert
int chooseProduct(vector<Product*>& products)
{
    int choice;
    cin>>choice;
    
    if (cin.fail())
    {
        cout<<"That is a invalid entry please try again"<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        direct(products, 2);
    }
    
    if (choice > 3 || choice < 1)
    {
        cout<<"Please choose a option between 1-3"<<endl;
        direct(products, 2);
    }
    
    return choice;
}

//Gets and validates user choice when at main menu
int getMenuChoice(vector<Product*>& products)
{
    int choice;
    cin>>choice;
    
    if (cin.fail())
    {
        cout<<"Not a valid entry please try again"<<endl<<endl;
        cin.clear();
        cin.ignore(100, '\n');
        menu(products);
    }
    
    if (choice < 0 || choice > 8)
    {
        cout<<"Please make a selection 1-8"<<endl<<endl;
        menu(products);
    }
    
    return choice;
}

//Adds AutoPart to products
void addProduct(vector<Product*>& products, AutoPart, int id)
{
    products.push_back(new AutoPart(id));
    
    products[id-1]->postData();
}

void addProduct(vector<Product*>& products, AutoPart, int id, int i)
{
    products.push_back(new AutoPart(id));
    
    products[id-1]->postData(i);
}

//Adds BulkLiquid to products
void addProduct(vector<Product*>& products, BulkLiquid, int id)
{
    products.push_back(new BulkLiquid(id));
    
    products[id-1]->postData();
}

void addProduct(vector<Product*>& products, BulkLiquid, int id, int i)
{
    products.push_back(new BulkLiquid(id));
    
    products[id-1]->postData(i);
}

//Adds Service to products
void addProduct(vector<Product*>& products, Service, int id)
{
    products.push_back(new Service(id));
    
    products[id-1]->postData();
}

void addProduct(vector<Product*>& products, Service, int id, int i)
{
    products.push_back(new Service(id));
    
    products[id-1]->postData(i);
}

//Used to add AutoPart to vector
void fillProducts(vector<Product*>& products, AutoPart)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, AutoPart(0), ID);
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            fill = false;
        }
    }
}

void fillProducts(vector<Product*>& products, AutoPart, int i)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, AutoPart(0), ID, i);
            i++;
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            fill = false;
        }
    }
}

//Used to add BulkLiquid to vector
void fillProducts(vector<Product*>& products, BulkLiquid)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, BulkLiquid(0), ID);
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            fill = false;
        }
    }
}

void fillProducts(vector<Product*>& products, BulkLiquid, int i)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, BulkLiquid(0), ID, i);
            i++;
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            
            fill = false;
        }
    }
}

//Used to add Service to vector
void fillProducts(vector<Product*>& products, Service)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, Service(0), ID);
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            fill = false;
        }
    }
}

void fillProducts(vector<Product*>& products, Service, int i)
{
    bool fill = true;
    
    while (fill)
    {
        try
        {
            ID++;
            addProduct(products, Service(0), ID, i);
            i++;
        }
        catch(char const* e)
        {
            ID--;
            products.erase(products.end() - 1);
            fill = false;
        }
    }
}

//Updates inventory of a single product ID
void postSale(vector<Product*>& products)
{
    int id;
    cout<<"Please enter the product ID to update inventory quantity: ";
    id = getId(products);
    
    for (int i = 0; i < products.size(); i++)
    {
        if(products[i]->getID() == id)
        {
            products[i]->updateQuantity();
            return;
        }
    }
    
    cout<<"There is no product with the ID of "<<id<<endl;
    cout<<"Please try again later"<<endl<<endl;
}

//Gets and Validates product ID from user
int getId(vector<Product*>& products)
{
    int id;
    
    cin>>id;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Not a valid entry please try again!"<<endl;
        postSale(products);
    }
    
    return id;
}

//Gets and Validates product ID from user
int getPrintId(vector<Product*>& products)
{
    int id;
    
    cin>>id;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Not a valid entry please try again!"<<endl;
        printProductsById(products);
    }
    
    return id;
}

//Prints product of a given id
void printProductsById(vector<Product*> products)
{
    int id;
    
    cout<<"Please enter the product ID you would like to view: ";
    id = getPrintId(products);
    
    for (int i = 0; i < products.size(); i++)
    {
        if(products[i]->getID() == id)
        {
            products[i]->printInformation();
            return;
        }
    }
    
    cout<<"There is no product with the ID of "<<id<<endl;
    cout<<"Please try again later"<<endl<<endl;
}

//Prints all the products in the vector
void printAllProducts(vector<Product*> products)
{
    for (int i = 0; i < products.size(); i++)
    {
        products[i]->printInformation();
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Prints products of a given type
void printProductsByType(vector<Product*> products)
{
    bool gotType = false;
    string type;
    
    type = getType();
    
    for (int i = 0; i < products.size(); i++)
    {
        if(type == products[i]->getProductType())
        {
            gotType = true;
            products[i]->printInformation();
            cout<<endl;
        }
    }
    if (!gotType)
    {
        cout<<"No products in inventory of type "<<type<<endl<<endl;
    }
}

//Converts user entered type into type to be used to compare types
string getType()
{
    int type;
    cout<<"What type of products would you like to view\n1. Auto Parts\n2. Bulk Liquids\n3. Services"<<endl;
    type = getUserEnteredType();
    
    switch (type)
    {
        case 1:
            return "AutoPart";
            break;
        case 2:
            return "BulkLiquid";
            break;
        case 3:
            return "Service";
            break;
        default:
            cout<<endl;
            return "";
            break;
    }
}

//Gets and validates type from user
int getUserEnteredType()
{
    int type;
    
    cin>>type;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Not a valid entry please try again!"<<endl;
        getType();
    }
    
    if (type > 3 || type < 1)
    {
        cout<<"Please choose a option 1-3"<<endl;
        getType();
    }
    
    return type;
}
