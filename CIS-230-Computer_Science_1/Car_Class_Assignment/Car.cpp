
#include "Car.hpp"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
Car::Car(int year, string make, string model)
{
    _year = year;
    _make = make;
    _model = model;
    _speed = 0;
    _gallons = 10;
    _isOn = false;
}

int Car::getYear(){return _year;}
string Car::getMake(){return _make;}
string Car::getModel(){return _model;}
float Car::getSpeed(){return _speed;}
float Car::getGallon(){return _gallons;}
bool Car::getCarStatus(){return _isOn;}


//Accelerates the virtual car. Checks if car is not on or out of gas
//Raises the speed and lowers the fuel
void Car::accelerate()
{
    
    if (!_isOn)
    {
        cout<<"\nCar is not on"<<endl;
    }
    else if(_gallons <= 0)
    {
        cout<<"\nOut of Gas"<<endl;
    }
    else
    {
        cout<<"\nGas"<<endl;
        _speed += 5;
        _gallons -= .5;
    }
}

//Slows down the car. Checks if already stopped
//Raises the speed and lowers the fuel
void Car::brake()
{
    if (_speed > 0)
    {
        cout<<"\nBrake"<<endl;
        _speed -= 5;
        _gallons -= .2;
    }
    else
    {
        cout<<"\nCar is stopped"<<endl;
    }
}

//Fills up fuel. Checks for stopped
//Raises the fuel but checks for full
void Car::fillUp()
{
    if (_speed > 0)
    {
        cout<<"\nPlease Stop The Car"<<endl;
    }
    else
    {     
        if (_gallons >= 22)
        {
            cout<<"Tank is full"<<endl;
            _gallons = 22;
        }
        else
        {
            cout<<"\nFueling"<<endl;   
            _gallons += 1;
        }
    }
}


//Starts car
//Checks for gas and if car is already on
void Car::startCar()
{
    if(_isOn == true)
    {
        cout<<"\nCar is already on"<<endl;
    }
    else if (_gallons <= 0)
    {
        cout<<"\nCar out of gas"<<endl;
    }
    
    else if (_isOn == false)
    {
        cout<<"\nTurned Car On"<<endl;
        _isOn = true;
        _gallons -= .5;

    }
}

//Turns off car
//Checks speed and if the car is already off
void Car::shutOff()
{
    if(_speed > 0)
    {
        cout<<"\nPlease Stop The Car"<<endl;
    }
    else if(_isOn == false)
    {
        cout<<"\nCar is not on"<<endl;
    }
    else if (_speed == 0 && _isOn == true)
    {
        cout<<"\nTurned Car Off"<<endl;
        _isOn = false;
    }
}

//Prints current gage to user
void Car::printGage()
{
    cout<<"Speed: "<<_speed<<endl;
    cout<<"Fuel: "<<setprecision(3)<<(_gallons)<<"%"<<endl;
    if (_isOn)
    {
        cout<<"Engine is running"<<endl;
    }
    else
    {
        cout<<"Engine is not running"<<endl;
    }
}

//Checks fuel level. Turns off car if reaches zero
void Car::fuelToZero()
{
    if (_gallons <= 0)
    {
        cout<<"Out of Fuel"<<endl;
        _gallons = 0;
        _isOn = false;
    }
}

//Decreases gas for elapsed time
void Car::idling(double gallonElapse)
{
    _gallons -= gallonElapse;
}