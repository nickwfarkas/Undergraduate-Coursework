
#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Car
{
    private:
        int _year;
        string _make;
        string _model;
        float _speed;
        double _gallons;
        bool _isOn;

    public:
        Car(int year, string make, string model);

        int getYear();
        string getMake();
        string getModel();
        float getSpeed();
        float getGallon();
        bool getCarStatus();

        void accelerate();
        void brake();
        void fillUp();
        void startCar();
        void shutOff();
        void printGage();
        void fuelToZero();
        void idling(double);
};

#endif
