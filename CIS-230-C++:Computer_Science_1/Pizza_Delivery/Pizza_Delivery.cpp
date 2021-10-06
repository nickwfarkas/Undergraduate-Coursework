//
//Nicholas Farkas
//Inheritance Program #1: Pizza Delivery
//

#include "Pizza.cpp"
#include "DeliveredPizza.cpp"
#include <iostream>
#include <vector>

using namespace std;

void userOrder(string& size, string& type, vector<string>& toppings, int& delivery, string& address, string toppingChoices[6]);
string pizzaSize();
string pizzaSizeToString(int size);
string pizzaType();
string pizzaTypeToString(int type);
vector<string> pizzaToppings(string toppingsChoices[6]);
vector<string> pizzaToppingsToString(vector<int> toppings);
int toppingValidation(string toppingChoices[6], vector<int>);
int pizzaDelivery();
string pizzaDeliveryAddress();
void printToppingChoices(string toppings[6]);
int eliminateToppingsDuplicate(vector<int>, int);

//Prints completed Pizza carryout order
ostream& operator << (ostream& o, Pizza& pi)
{
    o << "You ordered a " << pi.getSize() << " " << pi.getType() << " ";
    pi.printToppings(o);

    o<< "Pizza Price: $" << fixed << setprecision(2) << pi.getPrice() << endl;

    return o;
}

//Prints completed Pizza delivery order
ostream& operator << (ostream& o, DeliveredPizza& pi)
{
    o << "You ordered a " << pi.getSize() << " " << pi.getType() << " ";
    pi.printToppings(o);

    o<< "Pizza Price:  $ " << fixed << setprecision(2) << pi.getPrice() << endl;
    o<< "Delivery Fee: $ " << fixed << setprecision(2) << pi.getDeliveryFee() << endl;
    o<< "Total Price:  $ " << fixed << setprecision(2) << pi.getTotalPrice() << endl << endl;
    o<< "Delivered to:  "<< pi.getDeliveryAddress() << endl;

    return o;
}

int main()
{
    string size, type;
    vector<string> orderToppings;
    int delivery;
    string address;
    string toppings[] = 
    {
        "Pepperoni", "Mushrooms", "Onions", 
        "Green Pepper", "Tomatoes", "Jalapenos"
    }; 

    userOrder(size, type, orderToppings, delivery, address, toppings);

    if (delivery == 2)
    {
        DeliveredPizza order(address, size, type, orderToppings);
        cout << order;
    }
    else
    {
        Pizza order(size, type, orderToppings);
        cout << order;
    }
    
}

//Gets pizza size, type, topping, and delivery option
void userOrder(string& size, string& type, vector<string>& toppings, int& delivery, string& address, string toppingChoices[6])
{
    size = pizzaSize();

    type = pizzaType();

    toppings = pizzaToppings(toppingChoices);

    delivery = pizzaDelivery();

    if (delivery == 2)
    {
        address = pizzaDeliveryAddress();
    }
}

//Asks and validates user for pizza size
string pizzaSize()
{
    int size;
    bool validate = false;

    while (validate == false)
    {
        cout<<"What size pizza would you like to order?\n1 - Small\n2 - Medium\n3 - Large"<<endl;
        cin >> size;

        if (cin.fail())
        {
            cout <<endl<< "Not a valid entry please try again"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            validate = false;
        }
        else if(size > 3 || size < 1)
        {
            cout <<endl<< "Not a valid entry please try again"<<endl;
            validate = false;
        }
        else
        {
            validate = true;
        }
    }

    return pizzaSizeToString(size);
}

//Converts number size to name of size
string pizzaSizeToString(int size)
{
    switch (size)
    {
    case 1: 
        return "Small";
        break;
    case 2:
        return "Medium";
        break;
    case 3:
        return "Large";
        break;
    default: return "Non-Valid";
        break;
    }
}

//Asks and validates user for pizza type
string pizzaType()
{
    int type;
    bool validate = false;
    cout<<endl;
    while (validate == false)
    {
        cout<<"What type of crust would you like to order?\n1 - Classic\n2 - Deep Dish\n3 - Thin Crust"<<endl;
        cin >> type;

        if (cin.fail())
        {
            cout <<endl<< "Not a valid entry please try again"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            validate = false;
        }
        else if(type > 3 || type < 1)
        {
            cout <<endl<< "Not a valid entry please try again"<<endl;
            validate = false;
        }
        else
        {
            validate = true;
        }
    }

    return pizzaTypeToString(type);
}

//Converts number type to name of type
string pizzaTypeToString(int type)
{
    switch (type)
    {
    case 1: 
        return "Classic";
        break;
    case 2:
        return "Deep Dish";
        break;
    case 3:
        return "Thin Crust";
        break;
    default: return "Non-Valid";
        break;
    }
}

//Asks and validates user for pizza toppings
vector<string> pizzaToppings(string toppingsChoices[6])
{
    vector<int> toppings;
    int choice = -1;
    int i = 0;
    
    while (choice != 0)
    {
        choice = toppingValidation(toppingsChoices, toppings);

        if (choice != 0)
        {
            toppings.insert(toppings.begin() + i, choice);
        }

        i++;
    }

    return pizzaToppingsToString(toppings);
}

//Converts pizza toppings number to toppings names
vector<string> pizzaToppingsToString(vector<int> toppings)
{
    vector<string> stringToppings;
    
    for (int i = 0; i < toppings.size(); i++)
    {
        switch (toppings[i])
        {
        case 1:
            stringToppings.insert(stringToppings.begin() + i, "Pepperoni");
            break;
        case 2:
            stringToppings.insert(stringToppings.begin() + i, "Mushrooms");
            break;
        case 3:
            stringToppings.insert(stringToppings.begin() + i, "Onions");
            break;
        case 4:
            stringToppings.insert(stringToppings.begin() + i, "Green Pepper");
            break;
        case 5:
            stringToppings.insert(stringToppings.begin() + i,  "Tomatoes");
            break;
        case 6:
            stringToppings.insert(stringToppings.begin() + i, "Jalapenos");
            break;
        default: 
            break;
        }
    }

    return stringToppings;
}

//Validates pizza toppings
int toppingValidation(string toppingChoices[6], vector<int> currentChoices)
{
    int choice;

    cout<<endl<<"Choose from the following toppings or 0 to quit"<<endl;
    printToppingChoices(toppingChoices);
    cin >> choice;

    if (cin.fail())
    {
        cout << "Not a valid entry please try again"<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        choice = -1;
    }

    choice = eliminateToppingsDuplicate(currentChoices, choice);

    while (choice > 6 || choice < 0)
    {
        cout <<"Not a valid entry please try again"<<endl;
        cout <<"Choose from the following toppings or 0 to quit"<<endl;
        printToppingChoices(toppingChoices);
        cin >> choice;

        if (cin.fail())
        {
            cout << "Not a valid entry please try again"<<endl;
            cin.clear();
            cin.ignore(100,'\n');
            choice = -1;
        }

        choice = eliminateToppingsDuplicate(currentChoices, choice);
    }

    return choice;
}

//Elimates duplicates from user entered toppings
int eliminateToppingsDuplicate(vector<int> currentItems, int newItem)
{
    for (int i = 0; i < currentItems.size(); i++)
    {
        if (currentItems[i] == newItem)
        {
            cout << "That topping is already selected, ";
            return -1;
        }
    }
    return newItem;
}

//Asks and validates user for delivery type
int pizzaDelivery()
{
    int delivery;
    bool validate = false;


    while (validate == false)
    {
        cout <<endl<<"Would you like 1 - pick up or 2 - delivery: ";
        cin >> delivery;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            validate = false;
            cout << "Not a valid entry please try again"<<endl;
        }
        else if(delivery > 2 || delivery < 1)
        {
            validate = false;
            cout << "Not a valid entry please try again"<<endl;
        }
        else
        {
            validate = true;
        }
    }

    cin.ignore(100, '\n');
    return delivery;
}

//Asks user for delivery address
string pizzaDeliveryAddress()
{
    string address;

    cout<<endl<<"Please enter your address: ";
    getline(cin, address);

    return address;
}

//Prints topping choices 
void printToppingChoices(string toppings[6])
{
    for (int i = 0; i < 6; i++)
    {
        cout<<i+1<<": "<<toppings[i]<<endl;
    }
}


